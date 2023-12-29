#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

typedef struct
{
	pid_t pid;
	pid_t ppid;
} pids;

int N, A, S, points;

void handler(int sig, siginfo_t *siginfo, void *ucontext)
{
	pids *data = (pids*)(siginfo->si_value.sival_ptr);
	
	printf("%d\t:\tReceived signal (%d, %d) from %d\n", getpid(), data->pid, data->ppid, siginfo->si_pid);
	
	if (data->pid == getppid())
		points += A;
	else if (data->ppid == getppid())
		points -= (S / 2);
	else if (data->ppid == getpid())
		points -= S;
	else
		return;

	//printf("%d\t:\tNew Points: %d\n", getpid(), points);
}

void create_processes(int N)
{
	// Create tree with the property that child indices are 
	// { 2i, 2i + 1 } if current index is i. (Assuming 1 as the index of root)
	int cur_index = 1;
	while (1)
	{
		printf("%d is parent of %d\n", getppid(), getpid());
		
		pid_t left;
		if (2 * cur_index > N)
			break;

		left = fork();
		if (left == 0)
		{
			cur_index *= 2;
			continue;
		}
		
		pid_t right;

		if (2 * cur_index + 1 > N)
			break;

		right = fork();
		if (right == 0)
		{
			cur_index = 2 * cur_index + 1;
			continue;
		}
		
		break;
	}
}

int main(int argc, char** argv)
{
	// Argument count check
	if (argc != 4)
	{
		fprintf(stderr, "Invalid number of arguments\n");
		exit(EXIT_FAILURE);
	}

	// Register handler
	struct sigaction act;
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;

	if (sigaction(SIGRTMIN, &act, NULL) == -1)
		perror("Error registering handler");

	printf("PID\t:\tMessage\n");
	
	// Extract arguments
	N = atoi(argv[1]);
	A = atoi(argv[2]);
	S = atoi(argv[3]);
	points = N;

	// Create N+1 processes as specified, (1 current and N children)
	create_processes(N + 1);
	
	sleep(1);

	// Send the signal to required processes
	for (pid_t p = getppid() - N; p <= getpid() + N; ++p)
	{
		// prepare data
		pids* pid_info = (pids*)calloc(1, sizeof(pids));

		pid_info->pid = getpid();
		pid_info->ppid = getppid();
		
		union sigval sv;
		sv.sival_int = getpid();
		sv.sival_ptr = (void*)(pid_info);
		
		// if (getppid() > 11);
			// printf("%d\t:\tSending (%d, %d) to %d\n", getpid(), pid_info->pid, pid_info->ppid, p);
			
		sigqueue(p, SIGRTMIN, sv);
	}
	
	sleep(10);
	wait(NULL);
	wait(NULL);
	printf("%d\t:\tExiting...\n", getpid());
}