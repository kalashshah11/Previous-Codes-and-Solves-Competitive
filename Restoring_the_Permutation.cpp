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
    int T = 1;
    cin>>T;
    // cout<<"Case #"<<t;
    for(int t = 1;t<=T;t++)
    {
        int n,m;
		cin>>n;
		vector<int> q;
		read(n,q);
		vector<int> a(n);
		a[0] = q[0];
		set<int> st;
		set<int,greater<int>> st1;
		vector<int> b(n);
		for(int i = 0;i<n;i++){
			st.insert(i+1);
			st1.insert(i+1);
		}
		for(int i = 0;i<n;i++){
			auto it = st.find(q[i]);
			if(it != st.end()){
				a[i] = *it;
				b[i] = *it;
				st.erase(a[i]);
				st1.erase(a[i]);
			}
			else{
				a[i] = *st.begin();
				st.erase(a[i]);
			}
		}
		int maximum = 0;
		for(int i = 0;i<n;i++){
			if(b[i] == 0){
				b[i] = *st1.lower_bound(maximum);
				st1.erase(b[i]);
			}
			else{
				maximum = max(maximum,b[i]);
			}
		}
		for(int i = 0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		for(int i = 0;i<n;i++){
			cout<<b[i]<<" ";
		}
		cout<<endl;
    }

    return 0;
}
