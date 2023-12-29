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
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    //cin>>T;
    // cout<<"Case #"<<t;
    for(int t = 1;t<=T;t++)
    {
        int n, m, x; 
		cin >> n >> m >> x;
		vector<vector<vector<ll>>> edges(n+2, vector<vector<ll>>(m+2,vector<ll>(2,inf)));
		for(int i= 1;i<=n;i++) { 
			for(int j= 1;j<m;j++)  
				cin >> edges[i][j][0];
		}
		for(int i= 1;i<n;i++)  {
			for(int j= 1;j<=m;j++)  
				cin >> edges[i][j][1];
		}

		vector<vector<ll>> ans(n, vector<ll>(m,-1));
		if(x%2) 
		{
			for(int i = 0;i<n;i++){
				for(int j = 0;j<m;j++){
					cout<<-1<<" ";
				}
				cout<<endl;
			}
		}
		else{
			x /= 2;

			vector<vector<vector<ll>>> dp(n+2, vector<vector<ll>>(m+2, vector<ll>(x+2, inf)));
			for(int i= 1;i<=n;i++)  {
				for(int j= 1;j<=m;j++) {
					dp[i][j][0]=0;
				} 
			}
					
			for(int k= 1;k<=x;k++)  {
				for(int i= 1;i<=n;i++) { 
					for(int j= 1;j<=m;j++) 
					{
						dp[i][j][k] = min(dp[i][j][k], edges[i][j][1] + dp[i+1][j][k-1]);
						dp[i][j][k] = min(dp[i][j][k], edges[i][j-1][0] + dp[i][j-1][k-1]);
						dp[i][j][k] = min(dp[i][j][k], edges[i-1][j][1] + dp[i-1][j][k-1]);
						dp[i][j][k] = min(dp[i][j][k], edges[i][j][0] + dp[i][j+1][k-1]);
					}
				}
			}

			for(int i= 1;i<=n;i++)  {
				for(int j= 1;j<=m;j++)
					cout<<2*dp[i][j][x]<<" ";
				cout<<endl;
			}

		}
		

    }

    return 0;
}
