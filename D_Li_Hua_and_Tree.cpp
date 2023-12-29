#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define mnheap < ll, std::vector<ll>, std::greater<ll> > priority_queue;    // mnheap.push(), mnheap.top(), mnheap.pop()
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
struct comp {
	bool operator()(pair<long long,int> a, pair<long long,int> b){
		if(a.first == b.first){
			return a.second > b.second;
		}
		return a.first < b.first;
	}
};


void DFS1(int x, vector<vector<int>>& adj, int parent, vector<priority_queue<pair<long long,int>,vector<pair<long long,int>>, comp>>& pq, vector<ll>& val, vector<ll>& sums, vector<int>& parents){
	long long sum = 0;
	sum += val[x];
	parents[x] = parent;
	for(int i = 0;i<adj[x].size();i++){
		if(adj[x][i] != parent){
			DFS1(adj[x][i], adj, x, pq, val, sums);
			sum += sums[adj[x][i]];
			pq[x].push({sums[adj[x][i]], adj[x][i]});
		}
	}
	sums[x] = sum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    // cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
		int n,m;
		cin>>n>>m;
		vector<ll> a;
		read(n,a);
		vector<ll> sums(n,0);
		vector<vector<int>> adj(n,vector<int>());
		for(int i = 0;i<n-1;i++){
				int x,y;
				cin>>x>>y;
				x--;
				y--;
				adj[x].push_back(y);
				adj[y].push_back(x);
		}
		vector<priority_queue<pair<long long,int>,vector<pair<long long,int>>, comp>> pq(n);
		vector<int> parents(n);
		DFS1(0,adj,-1,pq,a,sums, parents);
		for(int i = 0;i<m;i++){
			int x,y;
			cin>>x>>y;
			y--;
			if(x == 1){
				cout<<sums[y]<<endl;
			} else {
				// Importance of parent of y remains same
				// parent[hson] = parent[y]
				// parent[y] = hson
				// add hson to pq of parent[y]
				// remove parent[]
				pair<long long,int> hson = pq[y].top();
				pq[y].pop();

			}
		}
        
    }

    return 0;
}
