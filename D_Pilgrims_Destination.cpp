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
void DFS(int x,vector<vector<pair<ll,ll>>>& adj,vector<ll>& vis,int depth,vector<ll>& nodes){
	// vis[x] = 0;
	int flag = 0;
	for(auto it : adj[x]){
		if(vis[it.first] == -1){
			flag = 1;
			vis[it.first] = vis[x];
			vis[it.first] += it.second * (depth + 1);
			// cout<<x<<" "<<it.first<<" "<<depth<<endl;
			DFS(it.first,adj,vis,depth+1,nodes);
		}
	}
	if(flag == 0){
		nodes.pb(x);
	}
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    cin>>T;
    // cout<<"Case #"<<t;
    for(int t = 1;t<=T;t++)
    {
        int n,m;
		cin>>n>>m;
		vector<ll> v;
		read(m,v);
		sort(all(v));
		vector<vector<pair<ll,ll>>> adj(n+1);
		vector<ll> vis(n+1,-1);
		vector<ll> nodes;
		for(int i = 0;i<n-1;i++){
			ll a,b,c;
			cin>>a>>b>>c;
			adj[a].pb({b,c});
			adj[b].pb({a,c});
		}
		vis[1] = 0;
		DFS(1,adj,vis,0,nodes);
		vector<ll> values;
		for(auto it : nodes){
			// cout<<it<<endl;
			// cout<<vis[it]<<" "<<endl;
			values.pb(vis[it]);
		}
		sort(all(values));
		int count = 0;
		while(!values.empty() && !v.empty()){
			if(values.back() <= v.back()){
				// cout<<values.back()<<" "<<v.back()<<endl;
				values.pop_back();
				v.pop_back();
			}
			else{
				count++;
				values.pop_back();
			}
		}
		while(!values.empty()){
			count++;
			values.pop_back();
		}
		cout<<nodes.size() - count<<endl;
    }

    return 0;
}
