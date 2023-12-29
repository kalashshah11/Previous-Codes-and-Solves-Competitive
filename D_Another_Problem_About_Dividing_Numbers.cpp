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
int gcd( ll a, ll b )
{
	if(b==0)
	{
			return a;
	}
	else
	{
			return gcd( b, a%b );
	}
}
// vector<long long>isprime(1000005 , true); 
// vector<long long>prime; 
// vector<long long>SPF(1000005); 
  
// // function generate all prime number less then N in O(n) 
// void manipulated_seive(int N) 
// { 
//     // 0 and 1 are not prime 
//     isprime[0] = isprime[1] = false ; 
  
//     // Fill rest of the entries 
//     for (long long int i=2; i<N ; i++) 
//     { 
//         // If isPrime[i] == True then i is 
//         // prime number 
//         if (isprime[i]) 
//         { 
//             // put i into prime[] vector 
//             prime.push_back(i); 
  
//             // A prime number is its own smallest 
//             // prime factor 
//             SPF[i] = i; 
//         } 
  
//         // Remove all multiples of  i*prime[j] which are 
//         // not prime by making isPrime[i*prime[j]] = false 
//         // and put smallest prime factor of i*Prime[j] as prime[j] 
//         // [ for exp :let  i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ] 
//         // so smallest prime factor of '10' is '2' that is prime[j] ] 
//         // this loop run only one time for number which are not prime 
//         for (long long int j=0; 
//              j < (int)prime.size() && 
//              i*prime[j] < N && prime[j] <= SPF[i]; 
//              j++) 
//         { 
//             isprime[i*prime[j]]=false; 
  
//             // put smallest prime factor of i*prime[j] 
//             SPF[i*prime[j]] = prime[j] ; 
//         } 
//     } 
// } 
ll factors(ll n){
	int count = 0;
	while (n % 2 == 0) {
      count++;
      n = n / 2;
   }
   for (int i = 3; i <= sqrt(n); i = i + 2) {
      while (n % i == 0) {
         count++;
         n = n / i;
      }
   }
   if (n > 2) {
      count++;
   }
   return count;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin>>T;
	map<int,int> mp;
	// manipulated_seive(1000005);
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        ll a,b,k;
		cin>>a>>b>>k;
		ll x = gcd(a,b);
		ll faca = mp[a];
		ll facb = mp[b];
		if(faca == 0){
			faca = factors(a);
			mp[a] = faca;
		}	
		if(facb == 0){
			facb = factors(b);
			mp[b] = facb;
		}		
		// cout<<a<<" "<<b<<" "<<factors(a)<<" "<<factors(b)<<endl;
		if(k == 1 && (a==b || x != min(a,b))){
			printf("NO\n");
		}
		else if(faca + facb >= k){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
        
    }

    return 0;
}
