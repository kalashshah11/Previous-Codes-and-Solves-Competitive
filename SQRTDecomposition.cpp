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
int MAXN = 200005;
int B = 450;
int getBlock(int idx){
	return idx/B;
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
        int n,m;
		cin>>n>>m;
		vector<ll> v(MAXN);
		vector<ll> sum(B);
		for(int i=0;i<n;i++){
			cin>>v[i];
			sum[getBlock(i)] = sum[getBlock(i)]^v[i];
		}
		for(int i = 0;i<m;i++){
			// int type;
			// cin>>type;
			// if(type == 1){
			// 	int a,b;
			// 	cin>>a>>b;
			// 	a--;
			// 	v[a] = b;
			// 	sum[getBlock(a)] = mod;
			// 	for(int i = B*getBlock(a);getBlock(i) == getBlock(a);i++){
			// 		sum[getBlock(i)] = min(sum[getBlock(i)],v[i]);
			// 	}
			// 	// v[a] = b;
			// }
			// else{
				int a,b;
				cin>>a>>b;
				a--;
				b--;
				ll ans = 0;
				if((getBlock(a) == getBlock(b)) || getBlock(a) + 1 == getBlock(b)){
					for(int i = a;i<=b;i++){
						ans = ans^v[i];
					}
				}
				else{
					for(int i = getBlock(a) + 1;i<getBlock(b);i++){
						ans = ans^sum[i];
					}
					for(int i = a;getBlock(i) == getBlock(a);i++){
						ans = ans^v[i];
					}
					for(int i = b;getBlock(i) == getBlock(b);i--){
						ans = ans^v[i];
					}
				}
				cout<<ans<<endl;
			// }
		}

        
    }

    return 0;
}
