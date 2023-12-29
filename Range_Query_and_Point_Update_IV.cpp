#include <bits/stdc++.h>
#define int long long
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define priority_queue < ll, std::vector<ll>, std::greater<ll> > mnheap;    // mnheap.push(), mnheap.top(), mnheap.pop()
#define REP(i,a,b) for (auto i = a; i != b; i++)
#define ll long long
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
                
// void read(int n,vector<int>& x)
// {
//     x.clear();
//     x.resize(n);
//     for(int i = 0;i<n;i++)
//     {
//         cin>>x[i];
//     }
    
// }
// void read(int n,int m,vector<vector<int>>& x)
// {
//     x.clear();
//     x.resize(n,vector<int>(m));
//     for(int i = 0;i<n;i++)
//     {
//         for(int j = 0 ;j<m;j++)
//             cin>>x[i][j];
//     }
// }
// void read(int n,vector<vector<int>>& x)
// {
//     x.clear();
//     x.resize(n+1);
//     for(int i = 0;i<n-1;i++)
//     {
//          int a,b;
//          cin>>a>>b;
//          x[a].pb(b);
//          x[b].pb(a);
//     }
// }
// void read(int n,vector<vector<int>>& x,int m)
// {
//     x.clear();
//     x.resize(n+1);
//     for(int i = 0;i<m;i++)
//     {
//          int a,b;
//          cin>>a>>b;
//          x[a].pb(b);
//          x[b].pb(a);
//     }
// }
void read(int n,vector<ll>& x)
{
    x.clear();
    x.resize(n);
    for(int i = 0;i<n;i++)
    {
        cin>>x[i];
    }
}

struct segmentTree{
    vector<pair<ll,ll>> t;
    int neut;
    void init(int n,int x = 0){
        t.resize(4*n,{x,0});
        neut = x;
    }
    void build(vector<int>&a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = {a[tl],1};
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
			if(t[v*2].first == t[v*2 + 1].first){
				t[v] = {t[v*2].first,t[2*v].second + t[2*v + 1].second};
			}
			else if(t[v*2].first > t[v*2 + 1].first){
				t[v] = {t[v*2].first,t[2*v].second};
			}
			else{
				t[v] = {t[v*2 + 1].first,t[2*v + 1].second};
			}
        }
    }
	// void print(){
	// 	for(int i = 0;i<t.size();i++){
	// 		cout<<t[i]<<" ";
	// 	}
	// 	cout<<endl;
	// }

    pair<ll,ll> sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return {neut,0};
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        auto t1 = sum(v*2, tl, tm, l, min(r, tm));
		auto t2 = sum(v*2+1, tm+1, tr, max(l, tm+1), r);
		if(t1.first == t2.first){
			return {t1.first,t1.second + t2.second};
		}
		else if(t1.first > t2.first){
			return {t1.first,t1.second};
		}
		return {t2.first,t2.second};
		
    }  
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = {new_val,1};
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            if(t[v*2].first == t[v*2 + 1].first){
				t[v] = {t[v*2].first,t[2*v].second + t[2*v + 1].second};
			}
			else if(t[v*2].first > t[v*2 + 1].first){
				t[v] = {t[v*2].first,t[2*v].second};
			}
			else{
				t[v] = {t[v*2 + 1].first,t[2*v + 1].second};
			}
        }
    } 
};   

int32_t main()
{
    std::ios::sync_with_stdio(false);
	cin.tie(NULL);
    int T = 1;
    // cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
        int n,q;
		cin>>n;
		vector<int> a;
		read(n,a);
		cin>>q;
		struct segmentTree st;
		st.init(n,INT_MIN);
		st.build(a,1,0,n-1);
		
		for(int i = 0;i<q;++i){
			int type;
			cin>>type;
			if(type == 2){
				ll a,b;
				cin>>a>>b;
				st.update(1,0,n-1,a,b);
				continue;
			}
			int a,b;
			cin>>a>>b;
			printf("%lld\n",st.sum(1,0,n-1,a,b).second);
		}
    }

    return 0;
}