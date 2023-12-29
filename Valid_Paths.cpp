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
void DFS(int x,vector<vector<int>>& adj,int p,vector<ll>& dp,vector<ll>& ans){
	ll sum = 0;
	int count = 0;
	for(auto it : adj[x]){
		if(it != p){
			DFS(it,adj,x,dp,ans);
			dp[x] += (2*dp[it])%mod;
			dp[x]%=mod;
			count++;
			ans[x] += ans[it];
			ans[x]%=mod;
			ans[x] += dp[it];
			ans[x]%=mod;
			dp[x] = (dp[x] + mod)%mod;
			ans[x] = (ans[x] + mod)%mod;
			sum += dp[it];
		}
	}
	for(auto it : adj[x]){
		if(it != p){
			ans[x] += (dp[it] * ((sum - dp[it])%mod + mod)%mod)%mod;
			ans[x] %= mod;
			ans[x] += mod;
			ans[x] %= mod;
 		}
	}

}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        int n,m;
		cin>>n;
		vector<vector<int>> adj(n);
		for(int i = 0;i<n-1;i++){
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			adj[a].pb(b);
			adj[b].pb(a);
			// cout<<a<<" "<<b<<endl;
		}
		vector<ll> ans(n,1);
		vector<ll> dp(n,1);
		// vector<ll> vis(n);
		DFS(0,adj,-1,dp,ans);
		cout<<ans[0]<<endl;
    }

    return 0;
}
