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
ll DFS1(int x,vector<vector<int>>& adj,vector<ll>& vis,vector<ll>& coin,vector<ll>& vis1,vector<ll>& val){
	
	ll max1 = 0,idx1 = -1;
	ll max2 = 0,idx2 = -1;
	for(auto it : adj[x]){
		if(vis[it] == -1){
			if(idx1 == -1 && max1  < coin[it]){
				idx1 = it;
				max1 = coin[it];
			}
			else if(max1 < coin[it]){
				idx2 = idx1;
				max2 = max1;
				idx1 = it;
				max1 = coin[it];
			}
			else if(max2 < coin[it]){
				idx2 = it;
				max2 = coin[it];
			}
		}
	}
	// if(x == 1){
	// 	cout<<max1<<" " <<idx1<<endl;
	// 	cout<<max2<<" "<<idx2<<endl;
	// }
	for(auto it : adj[x]){
		if(vis[it] == -1){
			vis[it] = 0;
			vis[it] += vis[x] + coin[x];
			ll y = DFS1(it,adj,vis,coin,vis1,val);
			if(it != idx1 && idx1 != -1)
				vis1[x] = max(coin[x] + y + max1,vis1[x]);
			else if(it != idx2 && idx2 != -1)
				vis1[x] = max(coin[x] + y + max2,vis1[x]);
			else{
				vis1[x] = max(coin[x] + y,vis1[x]);
			}
			val[x] = max(val[x],y + coin[x]);
		}
	}
	return val[x];
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
		cin>>n;
		vector<vector<int>> adj(n);
		for(int i = 1;i<n;i++){
			int x;
			cin>>x;
			adj[x].pb(i);
			adj[i].pb(x);
		}
		vector<ll> coin(n);
		for(int i = 0;i<n;i++){
			cin>>coin[i];
		}
		vector<ll> vis(n,-1);
		vector<ll> vis1(n,0);
		vector<ll> val(n,0);
		for(int i = 0;i<n;i++){
			vis1[i] = coin[i];
			val[i] = coin[i];
		}
		
		vis[0] = 0;
		DFS1(0,adj,vis,coin,vis1,val);
		ll ans = 0;
		for(int i = 0;i<n;i++){
			ans = max(ans,vis[i] + vis1[i]);
			// cout<<vis[i]<<" "<<vis1[i]<<" "<<val[i]<<" "<<i<<endl;
		}
		cout<<ans<<endl;
    }

    return 0;
}
