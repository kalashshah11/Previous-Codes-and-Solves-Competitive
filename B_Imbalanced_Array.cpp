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
struct item{
	ll val;
	ll idx;
};   
struct segtree{

    int size;
    
    vector<item> values;


    item NEUTRAL_E = {0,-1};

    item merge(item a,item b)
    {
		// item x = NEUTRAL_E;
		if(a.val >= b.val){
			return a;
		}
		return b;
    }

    item single(ll idx, ll a)
    {
        return {a,idx + 1};
    }

    void init(int n)
    {
        size = 1;
        while(size < n)
        {
            size *= 2;
        }
        values.resize(2*size,NEUTRAL_E);
    }
    
    void set(int i,int v,int x,int lx,int rx)
    {
        if(rx - lx == 1)
        {
            values[x] = single(i,v);
            return;
        }
        int m = (lx + rx)/2;
        if(i < m)
        {
            set(i,v,2*x + 1,lx,m);
        }
        else
        {
            set(i,v,2*x + 2,m,rx);
        }

        values[x] = merge(values[2*x + 1],values[2*x + 2]);

    }

    void set(int i,ll v)
    {
        set(i,v,0,0,size);
	}
    item calc(int l,int r,int x,int lx,int rx)
    {
        if(lx >= r || l >= rx)
        {
            return NEUTRAL_E;
            //print(NEUTRAL_E);
        }
        if(lx >=l && rx <=r)
        {
            return values[x];
            //print(values[x]);
        }
        int m = (lx+rx)/2;
        auto s1 = calc(l,r,2*x+2,m,rx);
        auto s2 = calc(l,r,2*x+1,lx,m);
        // print(s1);
        // print(s2);
        return merge(s2,s1);
    }
    item calc(int l,int r)
    {
        return calc(l,r,0,0,size);
    }
};
struct segtree1{

    int size;
    
    vector<item> values;


    item NEUTRAL_E = {mod,-1};

    item merge(item a,item b)
    {
		// item x = NEUTRAL_E;
		if(a.val <= b.val){
			return a;
		}
		return b;
    }

    item single(ll idx, ll a)
    {
        return {a,idx + 1};
    }

    void init(int n)
    {
        size = 1;
        while(size < n)
        {
            size *= 2;
        }
        values.resize(2*size,NEUTRAL_E);
    }
    
    void set(int i,int v,int x,int lx,int rx)
    {
        if(rx - lx == 1)
        {
            values[x] = single(i,v);
            return;
        }
        int m = (lx + rx)/2;
        if(i < m)
        {
            set(i,v,2*x + 1,lx,m);
        }
        else
        {
            set(i,v,2*x + 2,m,rx);
        }

        values[x] = merge(values[2*x + 1],values[2*x + 2]);

    }

    void set(int i,ll v)
    {
        set(i,v,0,0,size);
	}
    item calc(int l,int r,int x,int lx,int rx)
    {
        if(lx >= r || l >= rx)
        {
            return NEUTRAL_E;
            //print(NEUTRAL_E);
        }
        if(lx >=l && rx <=r)
        {
            return values[x];
            //print(values[x]);
        }
        int m = (lx+rx)/2;
        auto s1 = calc(l,r,2*x+2,m,rx);
        auto s2 = calc(l,r,2*x+1,lx,m);
        // print(s1);
        // print(s2);
        return merge(s2,s1);
    }
    item calc(int l,int r)
    {
        return calc(l,r,0,0,size);
    }
};
ll maxSumSubarray(segtree& st,int l,int r)
{
    // base case
    if (l >= r)
        return 0;
    item a = st.calc(l, r);
	// cout<<l<<" "<<r<<" "<<a.maxval<<" "<<a.maxidx<<endl;
    // divide the array in two parts
	// return 0;
    return a.val * (r - a.idx + 1) * (a.idx - l)
           + maxSumSubarray(st, l, a.idx - 1)
           + maxSumSubarray(st, a.idx, r);
}
ll minSumSubarray(segtree1& st,int l,int r)
{
    // base case
    if (l >= r)
        return 0;
    item a = st.calc(l, r);
	
    // divide the array in two parts
	// return 0;
    return a.val * (r - a.idx + 1) * (a.idx - l)
           + minSumSubarray(st, l, a.idx - 1)
           + minSumSubarray(st, a.idx, r);
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
		vector<ll> val(n);
		read(n,val);
		segtree st;
		segtree1 st1;
		st.init(n);
		st1.init(n);
		for(int i = 0;i<n;i++){
			st.set(i,val[i]);
			st1.set(i,val[i]);
		}
		cout<<maxSumSubarray(st,0,n) - minSumSubarray(st1,0,n)<<endl;
		// cout<<st.calc(0,1).maxval<<endl;
    }

    return 0;
}
