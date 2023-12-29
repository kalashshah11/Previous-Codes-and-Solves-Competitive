#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
// #define priority_queue < ll, std::vector<ll>, std::greater<ll> > mnheap;    // mnheap.push(), mnheap.top(), mnheap.pop()
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
            
// const int inf = 1000000000;
vector<vector<pair<ll, ll>>> adj;

void dijkstra(ll s, vector<ll> & d, vector<ll> & p) {
    int n = adj.size();
    d.assign(n, inf);
    p.assign(n, -1);

    d[s] = 0;
    // using pii = pair<int, int>;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int T = 1;
    cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        int n,m;
		cin>>n>>m;
		adj.resize(n+1);
		for(int i = 0;i<m;i++){
			ll a,b,c;
			cin>>a>>b>>c;
			a--;
			b--;
			adj[a].pb({b,c});
			adj[b].pb({a,c});
		}
		int B;
		cin>>B;
		for(int i = 0;i<B;i++){
			ll x;
			cin>>x;
			x--;
			adj[x].pb({n,0});
			adj[n].pb({x,0});
		}
		vector<ll> distance;
		vector<ll> parent;
		dijkstra(n,distance,parent);
		for(int i = 0;i<n;i++){
			printf("%lld ",distance[i]);
		}

    }

    return 0;
}
