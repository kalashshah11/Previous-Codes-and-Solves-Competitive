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
    //cin>>T;
    // cout<<"Case #"<<t;
    for(int t = 1;t<=T;t++)
    {
        int n,m;
        cin>>n;
        vector<queue<int>> v(n+1);
        vector<int> a(n);
        for(int i = 0;i<n;i++){
            cin>>a[i];
            v[a[i]].push(i+1);
        }
		for(int i = 1;i<=n;i++){
            v[i].push(n+2);
        }
        stack<int> s1;
        stack<int> s2;
        for(int i = 0;i<n;i++){
            if(s1.empty()){
                s1.push(a[i]);
                v[a[i]].pop();
            }
            else if(s2.empty()){
                s2.push(a[i]);
                v[a[i]].pop();
            }
            else{
                if(s1.top() == a[i]){
                    s2.push(a[i]);
                    v[a[i]].pop();
                }
                else if(s2.top() == a[i]){
                    s1.push(a[i]);
                    v[a[i]].pop();
                }
                else{
                    if(v[s1.top()].front() < v[s2.top()].front()){
                        s1.push(a[i]);
                        v[a[i]].pop();
                    }
                    else{
                        s2.push(a[i]);
                        v[a[i]].pop();
                    }
                }
            }
        }
        int count= 0;
        while(!s1.empty()){
            int x = s1.top();
            count++;
            while(!s1.empty() && s1.top() == x){
                s1.pop();
            }
        }
        while(!s2.empty()){
            int x = s2.top();
            count++;
            while(!s2.empty() && s2.top() == x){
                s2.pop();
            }
        }
        cout<<count<<endl;
    
    }

    return 0;
}
