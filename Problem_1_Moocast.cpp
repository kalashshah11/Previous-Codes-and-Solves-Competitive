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
struct DSU{
    int tsize;
    vector<ll> parent;
    vector<ll> rank;
    vector<ll> size;
    ll maxsize = 1;
    void init(int n)
    {
        tsize = n;
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i =1 ;i<=n;i++)
        {
            parent[i] = i;
        }   
    }
    ll getParent(ll a) {
        // ll i = a;
        return parent[a] = (parent[a] == a)?a:getParent(parent[a]); 
    }
    int doUnion(ll newa, ll newb) {
        ll a = getParent(newa);
        ll b = getParent(newb);
        if (a != b) {

            if(rank[a] < rank[b])
            {
                ll temp = a;
                a = b;
                b = temp;
            }
            if(rank[a] == rank[b])
            {
                rank[a] += 1;
            }
            parent[b] = a;
            size[a] += size[b];
            maxsize = max(maxsize,size[a]);
            size[b] = 0;
            return 1;
        } 
        else
            return 0;  
    }
    ll getMaxSize()
    {
        return maxsize;
    }
};
bool comp(vector<ll>& a,vector<ll>& b){
	return a[0] < b[0];
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    //cin>>T;
    // cout<<"Case #"<<t;
	// freopen("moocast.in","r",stdin);
	// freopen("moocast.out","w",stdout);
    for(int t = 1;t<=T;t++)
    {
        int n,m;
		cin>>n;
		vector<ll> x(n+1);
		vector<ll> y(n+1);
		
		for(int i = 1;i<=n;i++){
			cin>>x[i]>>y[i];
		}
		vector<ll> maximum(n+1);
		vector<vector<ll>> edges;
		for(int i =1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				edges.push_back({(x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) , i , j});
			}
		}
		DSU mdsu;
		mdsu.init(n);
		sort(all(edges),comp);
		ll ans = 0;
		for(int i = 0;i<edges.size();i++){
			
			if(mdsu.doUnion(edges[i][1],edges[i][2]) == 1){
				maximum[edges[i][1]] = max(maximum[edges[i][1]],edges[i][0]);
				maximum[edges[i][2]] = max(maximum[edges[i][2]],edges[i][0]);
			}
			if(mdsu.getMaxSize() == n){
				ans = edges[i][0];
				break;
			}
		}
		// cout<<ans<<endl;
		for(int i = 1;i<=n;i++){
			cout<<maximum[i]<<" ";
		}
    }

    return 0;
}
