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
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    //cin>>T;
    // cout<<"Case #"<<t;
    for(int t = 1;t<=T;t++)
    {
        double x,y,r;
	cin>>x>>y>>r;
	long double xneg = x - r;
	long double xpos = x + r;
	ll ans1  = 0;
	long double z = 0.00000000000001;
	r+=z;
	for(int i = ceil(xneg); i <= floor(xpos) ; i++){
		long double a = powl(x-i,2);
		long double rsq = powl(r,2);
		long double b = sqrtl(rsq - a);
		// cout<<i<<" "<<b<<endl;
		long double yleft = y - b;
		long double yright = y + b;
		ans1 += floor(yright) - ceil(yleft) + 1;
	}



	// long double yneg = y - r;
	// long double ypos = y + r;
	// ll ans2  = 0;
	// for(int i = ceil(yneg); i <= floor(ypos) ; i++){
	// 	long double a = powl(y-i,2);
	// 	long double rsq = powl(r,2);
	// 	long double b = sqrtl(rsq - a);
	// 	long double xleft = x - b;
	// 	long double xright = x + b;
	// 	ans2 += floor(xright) - ceil(xleft) + 1;
	// }
	cout<<ans1<<endl;
    }

    return 0;
}
