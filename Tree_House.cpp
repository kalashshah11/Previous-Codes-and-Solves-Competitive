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
vector<vector<int>> adj;
vector<__int128> value;
bool comp(int a,int b){
	return value[a] > value[b];
}
void DFS(int x,int par,vector<int>& vis){
    // vis[x] = 0;
	for(int i = 0;i<adj[x].size();i++){
        if(adj[x][i] != par)
			DFS(adj[x][i],x,vis);
	}
    sort(all(adj[x]),comp);
    int j = 1;
    value[x] = 1;
    // cout<<x<<" "<<adj[x].size()<<endl;
    for(int i = 0;i<adj[x].size();i++){
        if(vis[adj[x][i]] == 1){
            value[x] += value[adj[x][i]]*j;
            j++;
        }
    } 
    vis[x] = 1;
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
        ll n,m;
		cin>>n>>m;
        adj.clear();
		adj.resize(n);
        value.resize(n,0);
		for(int i = 0;i<n-1;i++){
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			adj[a].pb(b);
            adj[b].pb(a);
            // cout<<a<<" "<<b<<endl;
		}
        vector<int> vis(n,-1);
		DFS(0,-1,vis);
		cout<<(ll)(((value[0]%mod + mod)%mod * m )%mod  + mod)%mod<<endl;
    }

    return 0;
}
