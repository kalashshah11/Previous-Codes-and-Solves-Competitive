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
        int n,m;
		cin>>n>>m;
		// char k ;
		vector<string> v(n);
		for(auto &x : v){
			cin>>x;
		}
		vector<vector<int>> dp(n+1,vector<int>(m+1));
		queue<pair<int,int>> q;
		q.push({0,0});
		map<pair<int,int>,int> mp;
		while(!q.empty()){
			auto x = q.front();
			// cout<<x.first<<" "<<x.second<<endl;
			q.pop();
			if(v[x.first][x.second] == '*'){
				dp[x.first][x.second] += 1;
			}
			if(x.first < n-1 && x.second < m - 1){
				if(v[x.first + 1][x.second] == v[x.first][x.second + 1]){
					// if(mp[x.first+1][x.second])
					// dp[x.first+1][x.second] = dp[x.first][x.second];
					// q.push({x.first + 1,x.second});
					dp[x.first][x.second + 1] = dp[x.first][x.second];
					q.push({x.first,x.second + 1});
				}
				else if(v[x.first + 1][x.second] == '*'){
					dp[x.first+1][x.second] = dp[x.first][x.second];
					q.push({x.first + 1,x.second});
				}
				else if(v[x.first][x.second + 1] == '*'){
					dp[x.first][x.second + 1] = dp[x.first][x.second];
					q.push({x.first,x.second + 1});
				}
			}
			else if(x.first < n-1){
				dp[x.first+1][x.second] = dp[x.first][x.second];
				q.push({x.first + 1,x.second});
			}
			else if(x.second < m-1){
				dp[x.first][x.second + 1] = dp[x.first][x.second];
				q.push({x.first,x.second + 1});
			}
		}
		int ans = 0;
		for(auto &x : dp){
			for(auto v : x){
				ans = max(v,ans);
			}
		}
		cout<<ans<<endl;
    }

    return 0;
}
