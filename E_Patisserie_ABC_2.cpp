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
bool comp(vector<int>& a,vector<int>& b){
	if(a[0] + a[1] + a[2] == b[2] + b[1] + b[0] && a[0] == b[0]){
		return a[1] < b[1];
	}
	else if(a[0] + a[1] + a[2] == b[2] + b[1] + b[0]){
		return a[0] < b[0];
	}
	return a[0] + a[1] + a[2] < b[2] + b[1] + b[0];
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
        ll n,m;
		// vector<vector<int>> v;
		// for(int i = 0;i<=10;i++){
		// 	for(int j = 0;j<=10;j++){
		// 		for(int k = 0;k<=10;k++){
		// 			v.pb({i,j,k});
		// 		}
		// 	}
		// }
		// sort(all(v),comp);
		// // cout<<
		// map<int,int> mp;
		// for(int i = 0;i<v.size();i++){
		// 	mp[v[i][0] + v[i][1] + v[i][2]]++;
		// }
		// for(auto it : mp){
		// 	cout<<it.first<<" "<<it.second<<endl;
		// }
		cin>>n>>m;
		vector<int> groups;
		for(ll i = 0;i<=n;i++){
			groups.pb( ((i+1)*(i+2))/2);
			cout<<i<<" "<<((i+1)*(i+2))/2<<endl;
		}
    }

    return 0;
}
