#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define mnheap < ll, std::vector<ll>, std::greater<ll> > priority_queue;    // mnheap.push(), mnheap.top(), mnheap.pop()
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
    cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        int n,m;
		cin>>n;
		vector<int> a(n);
		for(auto &it : a)
			cin>>it;
		int v = -1;
		for(int i = 0;i<n;i++){
			if(a[i] != a[n-i-1]){
				v = i;
				break;
			}
		}
		
		if(v == -1){
			cout<<"YES"<<endl;
			continue;
		}
		else{
			int v1 = a[v];
			int v2 = a[n-v-1];
			vector<int> c1;
			vector<int> c2;
			for(auto it : a){
				if(it != v1){
					c1.pb(it);
				}
				if(it != v2){
					c2.pb(it);
				}
			}
			int flag2 = 0;
			int flag1 = 0;
			for(int i = 0;i<c1.size();i++){
				if(c1[i] != c1[c1.size()-i-1]){
					flag1 = 1;
					break;
				}
			}
			for(int i = 0;i<c2.size();i++){
				if(c2[i] != c2[c2.size()-i-1]){
					flag2 = 1;
					break;
				}
			}
			if(flag1 && flag2)
				cout<<"NO"<<endl;
			else{
				cout<<"YES"<<endl;
			}
		}
        
    }

    return 0;
}
