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
        cout<<"Case #"<<t<<": ";
        int n,m;
		string s;
		cin>>s;
		cin>>m;
		vector<vector<int>> adj(26);
		for(int i = 0;i<m;i++){
			string d;
			cin>>d;
			adj[d[0] - 'A'].push_back(d[1] - 'A');
		}
		vector<vector<int>> vis(26,vector<int>(26,-1));
        for(int i = 0;i<26;i++){
			// BFS
			queue<int> q;
			q.push(i);
			vis[i][i] = 0;
			while(!q.empty()){
				int x = q.front();
				q.pop();
				for(auto it : adj[x]){
					if(vis[i][it] == -1){
						vis[i][it] = vis[i][x] + 1;
						q.push(it);
					}
				}
			}
		}
		int ans = 1000000000;
		int flag1 = 0;
		for(int i = 0;i<26;i++){
			int flag = 0;
			int count = 0;
			for(int j = 0;j<s.size();j++){
				if(vis[s[j]-'A'][i] != -1){
					count += vis[s[j]-'A'][i];
				}
				else{
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				flag1 = 1;
				ans = min(ans,count);
			}
		}
		cout<<(flag1?ans:-1)<<endl;
    }

    return 0;
}
