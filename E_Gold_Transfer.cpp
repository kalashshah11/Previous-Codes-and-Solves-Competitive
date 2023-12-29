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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    // cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        ll q,n,m;
		cin>>q>>n>>m;
        vector<ll> parent(300005,-1);
		vector<ll> cost(300005,0);
		vector<ll> quantity(300005,0);
		vector<vector<ll>> up(300005,vector<ll>(20,-1));
		// parent.pb(-1);
		cost[0] = m;
		quantity[0] = n;
		// up.pb(vector<ll>(20,-1));
		// int z = 1;
		for(int i = 1;i<=q;i++){
			int type;
			cin>>type;
			if(type == 1){
				ll p;
				ll a;
				ll c;
				cin>>p>>a>>c;
				// cout<<p<<" "<<a
				parent[i]  = p;
				cost[i] = c;
				quantity[i] = a;
				up[i][0] = p;
				// cout<<i<<" "<<up[i][0]<<endl;
				for(int j = 1;j<20;j++){
					if(up[i][j-1] != -1)
						up[i][j] = up[up[i][j-1]][j-1];
					else{
						break;
					}
					// cout<<i<<" "<<up[i][j-1]<<" "<<j<<endl;
				}
				
			}
			else{
				ll v,w,x;
				cin>>v>>w;
				x = v;
				ll ans = 0;
				ll quant = 0;
				ll l = 0;
				for(int j = 19;j>=0;j--){
					if(up[x][j] != -1 && quantity[up[x][j]] > 0){
						x = up[x][j];
						l += 1LL<<j;
					}
				}
				
				while(w > 0 && l >=0){
					x = v;
					for(int j = 19;j>=0;j--){
						if(l&1LL<<j){
							x = up[x][j];
						}
					}
					if(quantity[x] >= w){
						quantity[x] -= w;
						ans += cost[x]*w;
						quant += w;
						w = 0;
					}
					else{
						w -= quantity[x];
						ans += cost[x]*quantity[x];
						quant += quantity[x];
						quantity[x] = 0;
					}
					l--;
				}
				cout<<quant<<" "<<ans<<endl;
			}
		}

    }

    return 0;
}
