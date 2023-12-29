#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
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
// 1,5
struct segmentTree{
    vector<int> t;
    void init(int n,int x = 0){
        t.resize(4*n,x);
    }
    void build(vector<int>&a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
			t[v] = t[v*2] + t[v*2+1];
        }
    }
	void print(){
		for(int i = 0;i<t.size();i++){
			cout<<t[i]<<" ";
		}
		cout<<endl;
	}

    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }  
    void update(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            t[v] -= 1;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos);
            else
                update(v*2+1, tm+1, tr, pos);
            t[v] = t[v*2] + t[v*2+1];
        }
    } 
    void update1(int v, int tl, int tr, int pos,int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update1(v*2, tl, tm, pos,new_val);
            else
                update1(v*2+1, tm+1, tr, pos,new_val);
            t[v] = t[v*2] + t[v*2+1];
        }
    } 
};   
struct segmentTree st;
int query(int l,int r){
	cout<<"? "<<l<<" "<<r<<endl;
	int x;
	cin>>x;
	return r-l + 1 - x;
}
int lower_bound(int l, int r, int X)
{
  int mid;

  // Initialise starting index and
  // ending index
  int low = l;
  int high = r+1;

  // Till low is less than high
  while (low < high) {
    mid = low + (high - low) / 2;
    if (X <= query(1,mid)) {
      high = mid;
    }
    else {
      low = mid + 1;
    }
  }
  return low;
}

bool query(int l,int r,int& k){
	cout<<"? "<<l<<" "<<r<<endl;
	int x;
	cin>>x;
	
	int noofzero = r - l + 1 - x;
	// cout<<x<<" "<<noofzero<<endl;
	if(noofzero < k){
		k -= noofzero;
		return true;
	}
	return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
	int N;
	cin>>N;
    cin>>T;
    st.init(N/8 + 1);
	
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        int m;
		cin>>m;
		if(t == 1)
		{
			for(int x = 1;x<=N/8 + 1;x++){
				int l = (x-1)*8 + 1;
				int r = min(N,x*8);
				if(l > r)
					break;
				cout<<"? "<<l<<" "<<r<<endl;
				int y;
				cin>>y;
                y = r - l + 1 - y;
				st.update1(1,0,N/8,x-1,y);
			}
		}
		int l = 0;
		int r = N/8;
		while(l < r){
			int mid = (l + r)/2;
			if(st.sum(1,0,N/8,0,mid) >= m){
				r = mid;
			}
			else{
				l = mid + 1;
			}
		}
        int le = l*8 + 1;
		int ri = min((l+1)*8,N);
		int ans = lower_bound(le,ri,m);
		cout<<"! "<<ans<<endl;
		st.update(1,0,N/8,l);

    }

    return 0;
}
