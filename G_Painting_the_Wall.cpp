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
        int n,m,x,y;
		cin>>n>>m>>x>>y;
		vector<string> v(n);
		for(int i = 0;i<n;i++){
			cin>>v[i];
		}
		vector<vector<int>> ud(n,vector<int>(m));
		vector<vector<int>> lr(n,vector<int>(m));
		for(int i = 0;i<n;i++){
			int j = 0;
			while(j < m){
				if(v[i][j] == 'O'){
					int start = j;
					int end = j;
					while(j < m && v[i][j] == 'O'){
						end++;
						j++;
					}
					for(int k = start;k<end;k++){
						lr[i][k] = max(end - k,k - start + 1);
					}
				}
				else{
					j++;
				}
			}
		}
		for(int i = 0;i<m;i++){
			int j = 0;
			while(j < n){
				if(v[j][i] == 'O'){
					int start = j;
					int end = j;
					while(j < n && v[j][i] == 'O'){
						end++;
						j++;
					}
					for(int k = start;k<end;k++){
						ud[k][i] = max(end - k,k - start + 1);
					}
				}
				else
					j++;
			}
		}
		int flag = 0;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				if(v[i][j] == 'O'){
					int v1 = max(x,y);
					int v2 =  min(x,y);
					int c1 = max(ud[i][j],lr[i][j]);
					int c2 = min(ud[i][j],lr[i][j]);
					// cout<<v1<<" "<<v2<<" "<<c1<<" "<<c2<<endl;
					if(v1 > c1 || v2 > c2){
						flag = 1;
					}
				}
			}
		}
		cout<<(flag?"NO":"YES")<<endl;
        
    }

    return 0;
}
