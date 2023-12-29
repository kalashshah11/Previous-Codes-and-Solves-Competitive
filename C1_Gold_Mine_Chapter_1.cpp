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
ll DFS(int x,vector<vector<int>>& adj,vector<ll>& a,int par){
	ll val = 0;
	for(auto it : adj[x]){
		if(it != par){
			// cout<<it<<endl;
			val = max(val,DFS(it,adj,a,x));
		}
	}
	return val + a[x];
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
        cout<<"Case #"<<t<<": ";
        int n,m;
		cin>>n;
		vector<ll> a;
		read(n,a);
		vector<vector<int>> adj(n);
		vector<int> tocheck;
		for(int i = 0;i<n-1;i++){
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			if(a == 0){
				tocheck.push_back(b);
			}
			if(b == 0){
				tocheck.push_back(a);
			}
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		ll ans = a[0];
		priority_queue<int> pq;
		for(int i = 0;i<tocheck.size();i++){
			pq.push(DFS(tocheck[i],adj,a,0));
		}
        if(!pq.empty()){
			ans += pq.top();
			pq.pop();
		}
		if(!pq.empty()){
			ans += pq.top();
			pq.pop();
		}
		cout<<ans<<endl;
    }

    return 0;
}
