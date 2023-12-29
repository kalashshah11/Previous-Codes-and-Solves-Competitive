#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
// #define priority_queue < ll, std::vector<ll>, std::greater<ll> > mnheap;    // mnheap.push(), mnheap.top(), mnheap.pop()
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
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    //cin>>T;
    // cout<<"Case #"<<t;
    for(int t = 1;t<=T;t++)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> v(n,vector<int>(2));
        for(int i=0 ;i<n;i++){
            cin>>v[i][0]>>v[i][1];
            v[i][1] += v[i][0];
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(all(v),comp);
        pq.push(v[0][1]);
        int i=1;
        int ans = 1;
        while(!pq.empty()){
            // cout<<pq.top();
            while(i < n && !pq.empty() && pq.top() + m >= v[i][0]){
                pq.push(v[i][1]);
                i++;
            }
            ans = max(ans,(int)pq.size());
            pq.pop();
        }
        cout<<ans<<endl;
        
        
    }

    return 0;
}
