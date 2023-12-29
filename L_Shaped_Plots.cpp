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
struct value{
	int v = -1;
	int left = 0;
	int right = 0;
	int up = 0;
	int down = 0;
};
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    cin>>T;
    // cout<<"Case #"<<t;
    for(int t = 1;t<=T;t++)
    {
		cout<<"Case #"<<t<<": ";
        int n,m;
		cin>>n>>m;
		vector<vector<value>> var(n,vector<value>(m));
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				cin>>var[i][j].v;
			}
		}
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				int x = i,y= i,z = j,w = j;
				while(x >= 0 && var[x][j].v == 1){
					var[i][j].up++;
					x--;
				}
				while(y < n && var[y][j].v == 1){
					var[i][j].down++;
					y++;
				}
				while(z >= 0 && var[i][z].v == 1){
					var[i][j].left++;
					z--;
				}
				while(w < m && var[i][w].v == 1){
					var[i][j].right++;
					w++;
				}
			}
		}
		int ans = 0;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				if(var[i][j].v == 1){
					for(int k = 2;k<=var[i][j].left;k++){
						if(var[i][j].up >= 2*k){
							ans++;
						}
						if(var[i][j].down >= 2*k){
							ans++;
						}
					}
					for(int k = 4;k<=var[i][j].left;k+=2){
						if(var[i][j].up >= k/2){
							ans++;
						}
						if(var[i][j].down >= k/2){
							ans++;
						}
					}
					for(int k = 2;k<=var[i][j].right;k++){
						if(var[i][j].up >= 2*k){
							ans++;
						}
						if(var[i][j].down >= 2*k){
							ans++;
						}
					}
					for(int k = 4;k<=var[i][j].right;k+=2){
						if(var[i][j].up >= k/2){
							ans++;
						}
						if(var[i][j].down >= k/2){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
    }

    return 0;
}
