#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define REP(i,a,b) for (auto i = a; i != b; i++)
#define maxheap priority_queue < ll, std::vector<ll>, std::less<ll> >
#define minheap priority_queue < ll, std::vector<ll>, std::greater<ll> >   // mxheap.push(), mxheap.top(), mxheap.pop()
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
// using namespace FastIO;
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
 
void dijkstra(int s,vector<vector<pair<int,ll>>>& adj, vector<ll>& d, vector<int> &p) {
    int n = adj.size();
    d.assign(n, inf);
    p.assign(n, -1);
 
    d[s] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;
 
        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;
 
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
//     for(int i = 0;i<n;i++)
//         printf("%lld ",d[i]);
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    // freopen("mixmilk.in", "r", stdin);
    // freopen("mixmilk.out", "w", stdout);
    //cin>>T;
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        int n,m;
        cin>>n>>m;
        vector<vector<pair<int,ll>>> adj(n);
	vector<ll> cont(n,inf);
        for(int i = 0;i<m;i++)
        {
            int x,y;
            ll z;
            cin>>x>>y>>z;
            x--;
            y--;
            adj[x].pb(mp(y,z));
	    if(x == y){
		    cont[x] = min(cont[x],z);
	    }
	}
	
        vector<vector<ll>> dis(n);
        vector<vector<int>> par(n);
	for(int i = 0;i<n;i++)
        	dijkstra(i,adj,dis[i],par[i]);

	for(int i = 0;i<n;i++){
		dis[i][i] = cont[i];
	}
	for(int i = 0;i<n;i++){
		int flag = 0;
		ll dist = inf;
		for(int j = 0;j<n;j++){
			if(i != j && dis[i][j] + dis[j][i] < dist){
				flag=1;
				dist = dis[i][j] + dis[j][i];
			}
			else if(i == j && dis[j][j] < dist){
				flag = 1;
				dist = dis[j][j];
			}
		}
		if(flag){
			cout<<dist<<endl;
		}
		else{
			cout<<-1<<endl;
		}

	}
        
    }
 
    return 0;
}