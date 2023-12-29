#include <sys/types.h>  /* basic system data types */
#include <sys/socket.h> /* basic socket definitions */
#include <sys/time.h>   /* timeval{} for select() */
#include <time.h>       /* timespec{} for pselect() */
#include <netinet/in.h> /* sockaddr_in{} and other Internet defns */
#include <arpa/inet.h>  /* inet(3) functions */
#include <errno.h>
#include <fcntl.h> /* for nonblocking */
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> /* for S_xxx file mode constants */
#include <sys/uio.h>  /* for iovec{} and readv/writev */
#include <unistd.h>
#include <sys/wait.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
 
#define BUFSIZE 1500
/* globals */
char sendbuf[BUFSIZE];
int datalen; /* #bytes of data following ICMP header */
char *host;
int nsent; /* add 1 for each sendto() */
pid_t pid; /* our PID */
int sockfd;
int verbose;
void init_v6(void);
void proc_v4(char *a, ssize_t b, struct msghdr *c, struct timeval *d);
void proc_v6(char *a, ssize_t b, struct msghdr *c, struct timeval *d);
void send_v4(void);
void send_v6(void);
void readloop(void);
void sig_alrm(int);
void tv_sub(struct timeval *, struct timeval *);
uint16_t in_cksum(uint16_t *addr, int len);
 
struct proto
{
    void (*fproc)(char *, ssize_t, struct msghdr *, struct timeval *);
    void (*fsend)(void);
    void (*finit)(void);
    struct sockaddr *sasend; /* sockaddr{} for send, from getaddrinfo */
    struct sockaddr *sarecv; /* sockaddr{} for receiving */
    socklen_t salen;         /* length of sockaddr {}s */
    int icmpproto;           /* IPPROTO_xxx value for ICMP */
} * pr;
#ifdef IPV6
#include <netinet/ip6.h>
#include <netinet/icmp6.h>
#endif
 
struct proto proto_v4 = {proc_v4, send_v4, NULL, NULL, NULL, 0, IPPROTO_ICMP};
#ifdef IPV6
struct proto proto_v6 = {proc_v6, send_v6, NULL, NULL, 0, IPPROTO_ICMPV6};
#endif
 
int datalen = 56; /* data that goes with ICMP echo request */
 
char *sock_ntop_host(const struct sockaddr *sa, socklen_t salen)
{
    static char str[128]; /* Unix domain is largest */
 
    switch (sa->sa_family)
    {
    case AF_INET:
    {
        struct sockaddr_in *sin = (struct sockaddr_in *)sa;
 
        if (inet_ntop(AF_INET, &sin->sin_addr, str, sizeof(str)) == NULL)
            return (NULL);
        return (str);
    }
 
#ifdef IPV6
    case AF_INET6:
    {
        struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *)sa;
 
        if (inet_ntop(AF_INET6, &sin6->sin6_addr, str, sizeof(str)) == NULL)
            return (NULL);
        return (str);
    }
#endif
    default:
        snprintf(str, sizeof(str), "sock_ntop_host: unknown AF_xxx: %d, len %d",
                 sa->sa_family, salen);
        return (str);
    }
    return (NULL);
}
 
char *Sock_ntop_host(const struct sockaddr *sa, socklen_t salen)
{
    char *ptr;
 
    if ((ptr = sock_ntop_host(sa, salen)) == NULL)
    {
        printf("sock_ntop_host error"); /* inet_ntop() sets errno */
        exit(1);
    }
 
    return (ptr);
}
 
struct addrinfo *host_serv(const char *host, const char *serv, int family, int socktype)
{
    int n;
    struct addrinfo hints, *res;
 
    bzero(&hints, sizeof(struct addrinfo));
    hints.ai_flags = AI_CANONNAME; /* always return canonical name */
    hints.ai_family = family;      /* AF_UNSPEC, AF_INET, AF_INET6, etc. */
    hints.ai_socktype = socktype;  /* 0, SOCK_STREAM, SOCK_DGRAM, etc. */
 
    if ((n = getaddrinfo(host, serv, &hints, &res)) != 0)
        return (NULL);
 
    return (res); /* return pointer to first on linked list */
}
/* end host_serv */
 
/*
 * There is no easy way to pass back the integer return code from
 * getaddrinfo() in the function above, short of adding another argument
 * that is a pointer, so the easiest way to provide the wrapper function
 * is just to duplicate the simple function as we do here.
 */
 
struct addrinfo *
Host_serv(const char *host, const char *serv, int family, int socktype)
{
    int n;
    struct addrinfo hints, *res;
 
    bzero(&hints, sizeof(struct addrinfo));
    hints.ai_flags = AI_CANONNAME; /* always return canonical name */
    hints.ai_family = family;      /* 0, AF_INET, AF_INET6, etc. */
    hints.ai_socktype = socktype;  /* 0, SOCK_STREAM, SOCK_DGRAM, etc. */
 
    if ((n = getaddrinfo(host, serv, &hints, &res)) != 0){
printf("host_serv error for %s, %s: %s",
                 (host == NULL) ? "(no hostname)" : host,
                 (serv == NULL) ? "(no service name)" : serv,
                 gai_strerror(n));
exit(1);
    }
        
    return (res); /* return pointer to first on linked list */
}
 
int main(int argc, char **argv)
{
    int c;
    struct addrinfo *ai;
    char *h;
    // opterr = 0; /* don't want getopt() writing to stderr */
    // while ((c = getopt(argc, argv, "v")) != -1)
    // {
    //     switch (c)
    //     {
    //     case 'v':
    //         verbose++;
    //         break;
    //     case '?':
    //         printf("unrecognized option: %c", c);
    //     }
    // }
    // if (optind != argc - 1)
    //     printf("usage: ping [ -v ] <hostname>");
    // host = argv[optind];
 
    ////////////file read mechanism
 
    pid = getpid() & 0xffff; /* ICMP ID field is 16 bits */
    signal(SIGALRM, sig_alrm);
    ai = Host_serv(host, NULL, 0, 0);
    h = Sock_ntop_host(ai->ai_addr, ai->ai_addrlen);
    printf("PING %s (%s): %d data bytes\n", ai->ai_canonname ? ai->ai_canonname : h, h, datalen);
    /* initialize according to protocol */
    if (ai->ai_family == AF_INET)
    {
        pr = &proto_v4;
#ifdef IPV6
    }
    else if (ai->ai_family == AF_INET6)
    {
        pr = &proto_v6;
        if (IN6_IS_ADDR_V4MAPPED(&(((struct sockaddr_in6 *)
                                        ai->ai_addr)
                                       ->sin6_addr))){
            printf("cannot ping IPv4-mapped IPv6 address");exit(1);
                                       }
 
#endif
    }
    else{
printf("unknown address family %d", ai->ai_family);
exit(1);
    }
        
    pr->sasend = ai->ai_addr;
    pr->sarecv = calloc(1, ai->ai_addrlen);
    pr->salen = ai->ai_addrlen;
    readloop();
    exit(0);
}
 
void readloop(void)
{
    int size;
    char recvbuf[BUFSIZE];
    char controlbuf[BUFSIZE];
    struct msghdr msg;
    struct iovec iov;
    ssize_t n;
    struct timeval tval;
    sockfd = socket(pr->sasend->sa_family, SOCK_RAW, pr->icmpproto);
    setuid(getuid()); /* don't need special permissions any more */
    if (pr->finit)
        (*pr->finit)();
    size = 60 * 1024; /* OK if setsockopt fails */
    setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &size, sizeof(size));
    sig_alrm(SIGALRM); /* send first packet */
    iov.iov_base = recvbuf;
    iov.iov_len = sizeof(recvbuf);
    msg.msg_name = pr->sarecv;
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;
    msg.msg_control = controlbuf;
    for (;;)
    {
        msg.msg_namelen = pr->salen;
        msg.msg_controllen = sizeof(controlbuf);
        n = recvmsg(sockfd, &msg, 0);
        if (n < 0)
        {
            if (errno == EINTR)
                continue;
            else
            {
                printf("recvmsg error");
                exit(1);
            }
        }
        gettimeofday(&tval, NULL);
        (*pr->fproc)(recvbuf, n, &msg, &tval);
    }
}
void tv_sub(struct timeval *out, struct timeval *in)
{
    if ((out->tv_usec -= in->tv_usec) < 0)
    { /* out -= in */
        --out->tv_sec;
        out->tv_usec += 1000000;
    }
    out->tv_sec -= in->tv_sec;
}
// 🥳
void proc_v4(char *ptr, ssize_t len, struct msghdr *msg, struct timeval *tvrecv)
{
    int hlenl, icmplen;
    double rtt;
    struct ip *ip;
    struct icmp *icmp1;
    struct timeval *tvsend;
    ip = (struct ip *)ptr;  /* start of IP header */
    hlenl = ip->ip_hl << 2; /* length of IP header */
    if (ip->ip_p != IPPROTO_ICMP)
        return;                          /* not ICMP */
    icmp1 = (struct icmp *)(ptr + hlenl); /* start of ICMP header */
    if ((icmplen = len - hlenl) < 8)
        return; /* malformed packet */
    if (icmp1->icmp_type == ICMP_ECHOREPLY)
    {
        if (icmp1->icmp_id != pid)
            return; /* not a response to our ECHO_REQUEST */
        if (icmplen < 16)
            return; /* not enough data to use */
        tvsend = (struct timeval *)icmp1->icmp_data;
        tv_sub(tvrecv, tvsend);
        rtt = tvrecv->tv_sec * 1000.0 + tvrecv->tv_usec / 1000.0;
        printf("%d bytes from %s: seq=%u, ttl=%d, rtt=%.3f ms\n",
               icmplen, Sock_ntop_host(pr->sarecv, pr->salen),
               icmp1->icmp_seq, ip->ip_ttl, rtt);
    }
    else if (verbose)
    {
        printf(" %d bytes from %s: type = %d, code = %d\n",
               icmplen, Sock_ntop_host(pr->sarecv, pr->salen),
               icmp1->icmp_type, icmp1->icmp_code);
    }
}
void init_v6()
{
#ifdef IPV6
    int on = 1;
    if (verbose == 0)
    {
        /* install a filter that only passes ICMP6_ECHO_REPLY unless verbose */
        struct icmp6_filter myfilt;
        ICMP6_FILTER_SETBLOCKALL(&myfilt);
        ICMP6_FILTER_SETPASS(ICMP6_ECHO_REPLY, &myfilt);
        setsockopt(sockfd, IPPROTO_IPV6, ICMP6_FILTER, &myfilt,
                   sizeof(myfilt));
        /* ignore error return; the filter is an optimization */
    }
/* ignore error returned below; we just won't receive the hop limit */
#ifdef IPV6_RECVHOPLIMIT
    /* RFC 3542 */
    setsockopt(sockfd, IPPROTO_IPV6, IPV6_RECVHOPLIMIT, &on, sizeof(on));
#else
    /* RFC 2292 */
    setsockopt(sockfd, IPPROTO_IPV6, IPV6_HOPLIMIT, &on, sizeof(on));
#endif
#endif
}
void proc_v6(char *ptr, ssize_t len, struct msghdr *msg, struct timeval *tvrecv)
{
#ifdef IPV6
    double rtt;
    struct icmp6_hdr *icmp6;
    struct timeval *tvsend;
    struct cmsghdr *cmsg;
    int hlim;
    icmp6 = (struct icmp6_hdr *)ptr;
    if (len < 8)
        return; /* malformed packet */
    if (icmp6->icmp6_type == ICMP6_ECHO_REPLY)
    {
        if (icmp6->icmp6_id != pid)
            return; /* not a response to our ECHO_REQUEST */
        if (len < 16)
            return; /* not enough data to use */
        tvsend = (struct timeval *)(icmp6 + 1);
        tv_sub(tvrecv, tvsend);
        rtt = tvrecv->tv_sec * 1000.0 + tvrecv->tv_usec / 1000.0;
        hlim = -1;
        for (cmsg = CMSG_FIRSTHDR(msg); cmsg != NULL;
             cmsg = CMSG_NXTHDR(msg, cmsg))
        {
            if (cmsg->cmsg_level == IPPROTO_IPV6 && cmsg->cmsg_type == IPV6_HOPLIMIT)
            {
                hlim = *(u_int32_t *)CMSG_DATA(cmsg);
                break;
            }
        }
        printf("%d bytes from %s: seq=%u, hlim=",
               len, Sock_ntop_host(pr->sarecv, pr->salen), icmp6->icmp6_seq);
        if (hlim == -1)
            printf("???"); /* ancillary data missing */
        else
            printf("%d", hlim);
        printf(", rtt=%.3f ms\n", rtt);
    }
    else if (verbose)
    {
        printf(" %d bytes from %s: type = %d, code = %d\n",
               len, Sock_ntop_host(pr->sarecv, pr->salen),
               icmp6->icmp6_type, icmp6->icmp6_code);
    }
#endif /* IPV6 */
}
void sig_alrm(int signo)
{
    (*pr->fsend)();
    alarm(1);
    return;
}
 
void send_v4(void)
{
    int len;
    struct icmp *icmp1;
    icmp1 = (struct icmp *)sendbuf;
    icmp1->icmp_type = ICMP_ECHO;
    icmp1->icmp_code = 0;
    icmp1->icmp_id = pid;
    icmp1->icmp_seq = nsent++;
    memset(icmp1->icmp_data, 0xa5, datalen); /* fill with pattern */
    gettimeofday((struct timeval *)icmp1->icmp_data, NULL);
    len = 8 + datalen; /* checksum ICMP header and data */
    icmp1->icmp_cksum = 0;
    icmp1->icmp_cksum = in_cksum((short *)icmp1, len);
    sendto(sockfd, sendbuf, len, 0, pr->sasend, pr->salen);
}
uint16_t in_cksum(uint16_t *addr, int len)
{
    int nleft = len;
    uint32_t sum = 0;
    uint16_t *w = addr;
    uint16_t answer = 0;
    /*
* Our algorithm is simple, using a 32 bit accumulator (sum), we add
 * sequential 16 bit words to it, and at the end, fold back all the
 * carry bits from the top 16 bits into the lower 16 bits.
 */
    while (nleft > 1)
    {
        sum += *w++;
        nleft -= 2;
    }
    /* mop up an odd byte, if necessary */
    if (nleft == 1)
    {
        *(unsigned char *)(&answer) = *(unsigned char *)w;
        sum += answer;
    }
    /* add back carry outs from top 16 bits to low 16 bits */
    sum = (sum >> 16) + (sum & 0xffff); /* add hi 16 to low 16 */
    sum += (sum >> 16);                 /* add carry */
    answer = ~sum;                      /* truncate to 16 bits */
    return (answer);
}
void send_v6()
{
#ifdef IPV6
    int len;
    struct icmp6_hdr *icmp6;
    icmp6 = (struct icmp6_hdr *)sendbuf;
    icmp6->icmp6_type = ICMP6_ECHO_REQUEST;
    icmp6->icmp6_code = 0;
    icmp6->icmp6_id = pid;
    icmp6->icmp6_seq = nsent++;
    memset((icmp6 + 1), 0xa5, datalen); /* fill with pattern */
    gettimeofday((struct timeval *)(icmp6 + 1), NULL);
    len = 8 + datalen; /* 8-byte ICMPv6 header */
    sendto(sockfd, sendbuf, len, 0, pr->sasend, pr->salen);
/* kernel calculates and stores checksum for us */
#endif /* IPV6 */
}