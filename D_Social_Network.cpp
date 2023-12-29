#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
// #define mnheap < ll, std::vector<ll>, std::greater<ll> > priority_queue;    // mnheap.push(), mnheap.top(), mnheap.pop()
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
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
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
			pq.push({1,i});
        }   
    }
    ll getParent(ll a) {
        // ll i = a;
        return parent[a] = (parent[a] == a)?a:getParent(parent[a]); 
    }
    int doUnion(ll newa, ll newb) {
        ll a = getParent(newa);
        ll b = getParent(newb);
        if (a == b) {
			while(!pq.empty()){
				auto e = pq.top();
				pq.pop();
				if(parent[e.second] == e.second){
					a = e.second;
					break;
				}
			}
			while(!pq.empty()){
				auto e = pq.top();
				pq.pop();
				if(parent[e.second] == e.second){
					b = e.second;
					break;
				}
			}
        } 
		cout<<a<<" "<<b<<endl;
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
		pq.push({size[a],a});
		maxsize = max(maxsize,size[a]);
		size[b] = 0;
		return 1;
    }
    ll getMaxSize()
    {
        return maxsize;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    // cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        int n,m;
		cin>>n>>m;
		DSU mdsu;
		mdsu.init(n);
		for(int i = 0;i<m;i++){
			int x,y;
			cin>>x>>y;
			mdsu.doUnion(x,y);
			cout<<mdsu.getMaxSize() - 1<<endl;
		}
        
    }

    return 0;
}