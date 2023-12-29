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
		cin>>n>>m;
		queue<int> q;
		vector<pair<int,int>> vis(n+1,{-1,-1});
		vector<int> vis1(n+1,-1);
		vis1[1] = 0;
		vector<vector<int>> adj(n+1);
		for(int i = 0;i<m;i++){
			int x;
			cin>>x;
			vis[x] = {0,x};
			q.push(x);
		}        
		for(int i = 0;i<n-1;i++){
			int a,b;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		while(!q.empty()){
			int x = q.front();
			q.pop();
			for(auto it : adj[x]){
				if(vis[it].first == -1){
					q.push(it);
					vis[it].first = vis[x].first + 1;
					vis[it].second = vis[x].second;
				}
			}
		}
		q.push(1);
		int flag1 = 0;
		set<int> st;
		while(!q.empty()){
			int x = q.front();
			// cout<<x<<endl;
			q.pop();
			if(vis[x].first > vis1[x]){
				int flag = 0;
				for(auto it : adj[x]){
					if(vis1[it] == -1){
						q.push(it);
						vis1[it] = vis1[x] + 1;
						flag = 1;
					}
				}
				if(flag == 0 && vis1[x] < vis[x].first){
					flag1 = 1;
				}
			}
			else{
				st.insert(vis[x].second);
			}
		}
		if(flag1 == 1){
			cout<<-1<<endl;
		}
		else{
			
			cout<<st.size()<<endl;
		}
    }

    return 0;
}
