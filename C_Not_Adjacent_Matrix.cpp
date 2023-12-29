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
	if(a[0] == b[0]){
		return a[2] < b[2];
	}
	return a[0] < b[0];
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        int n,m;
		cin>>n;
		if(n == 2){
			cout<<-1<<endl;
			continue;
		}
		// int i = 1;
		vector<vector<int>> indexes;
		vector<vector<int>> indexes1;
		for(int j = 0;j<n;j++){
			for(int k = 0;k<n;k++){
				if((j+k)%2 == 0)
					indexes.pb({j+k,j,k});
				else{
					indexes1.pb({j+k,j,k});
				}
			}
		}
		vector<vector<int>> fin(n,vector<int>(n));
		sort(all(indexes),comp);
		sort(all(indexes1),comp);
		int next = 1;
		for(int i = 0;i<indexes.size();i++){
			fin[indexes[i][1]][indexes[i][2]] = next;
			next++;
		}
		for(int i = 0;i<indexes1.size();i++){
			fin[indexes1[i][1]][indexes1[i][2]] = next;
			next++;
		}
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				cout<<fin[i][j]<<" ";
			}
			cout<<endl;
		}
    }

    return 0;
}