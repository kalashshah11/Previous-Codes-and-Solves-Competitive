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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    // cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        int n,m;
		cin>>n;
		string s;
		cin>>s;
		vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(1024,vector<ll>(11,0)));
		dp[0][0][0] = 1;
		for(int i = 1;i<=n;i++){
			for(int j  =0;j<1024;j++){
				int x = s[i-1] - 'A';
				x++;
				for(int k = 0;k<=10;k++){
					dp[i][j][k] = dp[i-1][j][k];
				}
				if(j == 0){
					dp[i][j][x] += dp[i-1][j][0];
				}
				else if(j & 1<<x == 0){
					for(int k = 1;k<=10;k++){
						dp[i][(j | 1<<x)][x] += dp[i-1][j][k];
						dp[i][(j | 1<<x)][x] %= mod;
					}
				}
				else{
					dp[i][j][x] += dp[i-1][j][x];
					dp[i][j][x] %= mod;
				}
			}
		}
		ll ans = 0;
		for(int i = 0;i<1024;i++){
			for(int j = 0;j<=10;j++){
				ans += dp[n][i][j];
				ans = (ans%mod + mod)%mod;
				// cout<<dp[k][i][j]<<endl;
			}
		}
        cout<<ans<<endl;
    }

    return 0;
}
