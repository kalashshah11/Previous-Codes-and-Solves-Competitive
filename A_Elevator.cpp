#include <bits/stdc++.h>
#include <atcoder/all>
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
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define pb push_back
#define SQ(a) (a)*(a)
 
using namespace std;
using namespace atcoder;
        
void read(int n,vector<int>& x)
{
    x.clear();
    x.resize(n);
    for(int i = 0;i<n;i++)
    {
        cin>>x[i];
    }
    
}
void read(int n,int m,vector<vector<int>>& x)
{
    x.clear();
    x.resize(n,vector<int>(m));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0 ;j<m;j++)
            cin>>x[i][j];
    }
}
void read(int n,vector<vector<int>>& x)
{
    x.clear();
    x.resize(n+1);
    for(int i = 0;i<n-1;i++)
    {
         int a,b;
         cin>>a>>b;
         x[a].pb(b);
         x[b].pb(a);
    }
}
void read(int n,vector<vector<int>>& x,int m)
{
    x.clear();
    x.resize(n+1);
    for(int i = 0;i<m;i++)
    {
         int a,b;
         cin>>a>>b;
         x[a].pb(b);
         x[b].pb(a);
    }
}
void read(int n,vector<ll>& x)
{
    x.clear();
    x.resize(n);
    for(int i = 0;i<n;i++)
    {
        cin>>x[i];
    }
}
const int N = 10000005;
ll factorialNumInverse[N + 1]; 
// array to precompute inverse of 1! to N! 
ll naturalNumInverse[N + 1]; 
// array to store factorial of first N numbers 
ll fact[N + 1]; 
unsigned ll derangement[N + 1];  
// Function to precompute inverse of numbers 
void InverseofNumber(ll p) 
{ 
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
} 
// Function to precompute inverse of factorials 
void InverseofFactorial(ll p) 
{ 
        factorialNumInverse[0] = factorialNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 


void factorial(ll p) 
{ 
    fact[0] = 1;  
    for (int i = 1; i <= N; i++) { 
        fact[i] = (fact[i - 1] * i) % p; 
    } 
} 

ll Binomial(ll N, ll R, ll p) 
{ 
    ll ans = ((fact[N] * factorialNumInverse[R]) 
                % p * factorialNumInverse[N - R]) 
                % p; 
    return ans; 
}
void derangements(ll p){
    derangement[1] = 0;
    for (int i = 2; i <= N; i++) { 
        if(i%2 == 0)
            derangement[i] = (derangement[i - 1] * i + 1) % p; 
        else{
            derangement[i] = (((derangement[i - 1] * i - 1) % p) + p)%p; 
        }
    }
}     
ll power(ll x, ll y, ll p) 
{ 
    int res = 1;      // Initialize result 

    x = x % p;  // Update x if it is more than or 
            // equal to p 

    while (y > 0) 
    { 
    // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 

    // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    // cin>>T;
    // cout<<"Case #"<<t;
    InverseofNumber(mod); 
    InverseofFactorial(mod); 
    factorial(mod);
    for(int t = 1;t<=T;t++)
    {
        int n,m;
        cin>>n>>m>>p;
        cout<<((Binomial(n+m,p) - Binomial(m,p))%mod + mod)%mod<<endl;
		// cin>>n>>m;
		// cout<<min(20*(n-1),5*(n - 1 + m-1))<<endl;
    }

    return 0;
}
