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
void read(int n,vector<vector<int>>& x,vector<pair<int,int>>& edges)
{
    x.clear();
    x.resize(n+1);
    edges.resize(n);
    for(int i = 0;i<n-1;i++)
    {
         int a,b;
         cin>>a>>b;
         edges[i+1].first = a;
         edges[i+1].second = b;
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

void DFS(int x,vector<vector<int>>& adj,vector<ll>&c,vector<int>& vis){
    vis[x] = 1;
    for(auto it : adj[x]){
        if(vis[it] == 0){
            c[it] += c[x];
            DFS(it,adj,c,vis);
        }
    }
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
        int n;
        cin>>n;
        vector<vector<int>> adj;
        vector<pair<int,int>> edges;
        vector<ll> c(n+1);
        read(n,adj,edges);
        vector<int> dis(n+1,-1);
        queue<int> q;
        dis[1] = 0;
        q.push(1);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto it : adj[x]){
                if(dis[it] == -1){
                    dis[it] = dis[x]+1;
                    q.push(it);
                }
            }
        }
        int query;
        cin>>query;
        for(int i = 0;i<query;i++){
            int type;
            cin>>type;
            if(type == 1){
                int ei;
                ll ci;
                cin>>ei>>ci;
                int a = edges[ei].first;
                int b = edges[ei].second;
                if(dis[a] < dis[b]){
                    c[1] += ci;
                    c[b] -= ci;
                }
                else{
                    c[a] += ci;
                }
            }
            else{
                int ei;
                ll ci;
                cin>>ei>>ci;
                int b = edges[ei].first;
                int a = edges[ei].second;
                if(dis[a] < dis[b]){
                    c[1] += ci;
                    c[b] -= ci;
                }
                else{
                    c[a] += ci;
                }
            }
        }
        vector<int> vis(n+1);
        DFS(1,adj,c,vis);
        for(int i = 1;i<=n;i++){
            cout<<c[i]<<endl;
        }
    }

    return 0;
}

