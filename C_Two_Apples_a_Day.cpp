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
#define mod 998244353
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
ll power(ll a, ll b)    //a is base, b is exponent
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	if(b%2 == 1)
		return (power(a,b-1)*a)%mod;
	ll q = power(a,b/2);
	return (q*q)%mod;
}
ll gcd( ll a, ll b )
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
ll lcm (ll a, ll b)
{
	return (a*b)/gcd(a,b);
}
ll check(vector<ll> a, ll b, int n){
	a.push_back(b);
	sort(a.begin(), a.end());
	ll pairsum = a[0] + a.back();
	for(int i = 0;i<n;i++){
		if(a[i] + a[2*n-i-1] != pairsum){
			return -1;
		}
	}
	return b;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    cin>>T;
    for(int t = 1;t<=T;t++)
    {
    	cout<<"Case #"<<t<<": ";
        int n;
		cin>>n;
		vector<ll> a(2*n-1);
		ll sum = 0;
		for(int i = 0;i<2*n-1;i++){
			cin>>a[i];
			sum += a[i];
		}
		if(n == 1) {
			cout<<1<<endl;
			continue;
		}
		sort(a.begin(), a.end());
		if(n == 2) {
			if(a[0] + a[1] - a[2] > 0) {
				cout<<a[0] + a[1] - a[2]<<endl;
			} else {
				cout<<a[1] + a[2] - a[0]<<endl;
			}
			continue;
		}
		
		ll sum1 = (a[0] + a[2*n-3])*n;
		ll rem1 = sum1 - sum;
		
		if(rem1 <= a[0] && rem1 > 0){
			ll h = check(a, rem1, n);
			if(h != -1){
				cout<<h<<endl;
				continue;
			}
		}
		ll sum3 = (a[0] + a[2*n-2])*n;
		ll rem3 = sum3 - sum;
		
		if(rem3 > 0){
			ll h = check(a, rem3, n);
			if(h != -1){
				cout<<h<<endl;
				continue;
			}	
		}
		ll sum2 = (a[1] + a[2*n-2])*n;
		ll rem2 = sum2 - sum;
		
		if(rem2 >= a[2*n-2]){
			ll h = check(a, rem2, n);
			if(h != -1){
				cout<<h<<endl;
				continue;
			}
		}
		cout<<-1<<endl;
    }

    return 0;
}
