#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define priority_queue < ll, std::vector<ll>, std::greater<ll> > mnheap;    // mnheap.push(), mnheap.top(), mnheap.pop()
#define REP(i,a,b) for (auto i = a; i != b; i++)
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define pb push_back
#define SQ(a) (a)*(a)
 
using namespace std;
            
const int N = 7e5 + 10, M = 1e3+10;
// const int mod = 998244353;
 
int n, m;
int a[N],b[N];
 
#define ls(x) tr[x].l
#define rs(x) tr[x].r
struct seg
{
    int l, r, cnt;
}tr[N*20];
int root[N], idx;
 
int update(int pre, int l, int r, int x)
{
    int rt = ++idx, mid = (l+r)>>1;
    tr[rt] = tr[pre];
    if(l == r) {
        tr[rt].cnt++;
        return rt;
    }
    if(x<=mid) ls(rt) = update(tr[pre].l, l, mid, x);
    else rs(rt) = update(tr[pre].r, mid+1, r, x);
    tr[rt].cnt = tr[ls(rt)].cnt + tr[rs(rt)].cnt;
    return rt;
}
 
int query(int pre, int rt, int l=1, int r=n)
{
    if(l == r) return tr[rt].cnt-tr[pre].cnt;
    int cntl = tr[ls(rt)].cnt-tr[ls(pre)].cnt;
    int cntr = tr[rs(rt)].cnt-tr[rs(pre)].cnt;
    int mid = (l+r)>>1;
    if(cntl >= cntr) return query(ls(pre), ls(rt), l, mid);
    return query(rs(pre), rs(rt), mid+1, r);
}
bool ck(int l, int r, int blo, int num)
{
    int cnt = (r-l+1)-num;
    int t = min(blo-1, cnt-1); 
    t = max(0, t);
    num -= 2*t;
    blo -= t;
    cnt -= t;
 
    num -= max(0, blo-1);
    return num <= (num+cnt+1)/2;
}


vector<long long>isprime(100005 , true); 
vector<long long>prime; 
vector<long long>SPF(100005); 
  
// function generate all prime number less then N in O(n) 
void manipulated_seive(int N) 
{ 
    // 0 and 1 are not prime 
    isprime[0] = isprime[1] = false ; 
  
    // Fill rest of the entries 
    for (long long int i=2; i<N ; i++) 
    { 
        // If isPrime[i] == True then i is 
        // prime number 
        if (isprime[i]) 
        { 
            // put i into prime[] vector 
            prime.push_back(i); 
  
            // A prime number is its own smallest 
            // prime factor 
            SPF[i] = i; 
        } 
  
        // Remove all multiples of  i*prime[j] which are 
        // not prime by making isPrime[i*prime[j]] = false 
        // and put smallest prime factor of i*Prime[j] as prime[j] 
        // [ for exp :let  i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ] 
        // so smallest prime factor of '10' is '2' that is prime[j] ] 
        // this loop run only one time for number which are not prime 
        for (long long int j=0; 
             j < (int)prime.size() && 
             i*prime[j] < N && prime[j] <= SPF[i]; 
             j++) 
        { 
            isprime[i*prime[j]]=false; 
  
            // put smallest prime factor of i*prime[j] 
            SPF[i*prime[j]] = prime[j] ; 
        } 
    } 
} 



int main(void)
{
	scanf("%d%d", &n, &m);
    manipulated_seive(100005);
	for(ll i=1;i<=n;i++)
	{
		scanf("%d", &a[i]);
		
	}
    vector<int> start(n+1);
    vector<int> nd(n+1);
    int j = 1;
    for(int i = 1;i<=n;i++){
        int temp = a[i];
        // int j = 0;
        start[i] = j;
        while(temp != 1){
            int x = SPF[temp];
            while(temp%x == 0){
                temp/=x;
            }
            // v1[i].insert(x);
            b[j] = x;
            j++;
        }
        nd[i] = j;
        // cout<<start[i]<<" "<<nd[i]<<endl;
    }
    
}
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     int T = 1;
//     //cin>>T;
	
//     // cout<<"Case #"<<t;
//     for(int t = 1;t<=T;t++)
//     {
//         scanf("%d%d", &N, &Q);
// 		// fastInput(N);
// 		// fastInput(Q);
// 		for (int i = 0; i < N; i ++) {
// 			scanf("%d", &a[i]);
// 			// fastInput(a[i]);
// 		}
// 		int j = 0;
		
// 		for(int i = 0;i<v1.size();i++){
// 			cout<<v1[i]<<" ";
// 		}
// 		cout<<endl;
// 		// read(N,v);
// 		MAGIC = ceil((float)sqrt(v1.size()));
// 		for (int i = 0; i < Q; i ++) {
// 			int l, r;
// 			scanf("%d%d", &l, &r);
// 			// fastInput(l);
// 			// fastInput(r);
// 			queries.push_back(query(start[l-1], nd[r-1], i));
// 			// cout<<l<<" "<<r<<" "<<start[l-1]<<" "<<nd[r-1]<<endl;
//     	}
// 		sort(queries.begin(), queries.end());
// 		int L = v1.size() - 1, R = v1.size() - 1;
// 		int answer = 0;
// 		for(int i = 0; i < Q; i ++) {
// 			for(int j = L; j >= queries[i].l; j--) {
// 				add(j, answer);
// 			}
// 			for(int j = R ; j <= queries[i].r; j++) {
// 				add(j, answer);
// 			}
// 			for(int j = L + 1; j <= queries[i].l; j ++) {
// 				remove(j, answer);
// 			}
// 			for(int j = R; j > queries[i].r; j--) {
// 				remove(j, answer);
// 			}
// 			cout<<queries[i].l<<" "<<queries[i].r<<endl;
// 			L = queries[i].l-1;
// 			R = queries[i].r;
// 			output[queries[i].id] = answer;
			
// 		}
// 		for(int i = 0;i<Q;i++){
// 			cout<<output[i]<<endl;
// 		}
//     }

//     return 0;
// }
