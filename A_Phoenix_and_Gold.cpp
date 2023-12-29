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
struct segmentTree{
    vector<int> t;
    void init(int n){
        t.resize(4*n,0);
    }
    void build(vector<int>&a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = t[v*2] | t[v*2+1];
        }
    }
    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm)) | sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }  
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = t[v*2] | t[v*2+1];
        }
    } 
};            
vector<int> function(int N,vector<int> A,int Q,vector<vector<int>> queries){ //C++14
    
    struct segmentTree st;
    st.init(N);
    vector<int> output;
    for(int i =0;i<Q;i++){
        if(queries[i][0] == 1){
            st.update(1,0,N-1,queries[i][1]-1,queries[i][2]);
            continue;
        }
        output.push_back(st.sum(1,0,N-1,queries[i][1]-1,queries[i][2]-1));
    }
    return output;
}        
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
    
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        ll n,m;
		cin>>n>>m;
		vector<ll> A(n);
		read(n,A);
		
		sort(all(A));
		vector<ll> B(all(A));
		int idx = -1;
		for(int i =1;i<n;i++){
			A[i] += A[i-1];
			if(A[i] == m){
				idx = i;
			}
		}
		if(A[0] == m){
			idx = 0;
		}
		if(idx == n-1){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			for(int i = 0;i<n;i++){
				if(i != idx){
					cout<<B[i]<<" ";
				}
			}
			if(idx != -1){
				cout<<B[idx];
			}
			cout<<endl;
		}
    }

    return 0;
}
