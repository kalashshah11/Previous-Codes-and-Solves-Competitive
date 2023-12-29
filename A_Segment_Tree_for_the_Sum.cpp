#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>

#define mnheap priority_queue < ll, std::vector<ll>, std::greater<ll> >;    // mnheap.push(), mnheap.top(), mnheap.pop()
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
	int vsize;
	vector<ll> value;
	void init(int n,int x = 0){
		vsize = n;
		value.resize(4*n,x);
	}
	void build(vector<ll>& a,int v,int tl,int tr){
		if (tl == tr) {
			value[v] = a[tl];
		} else {
			int tm = (tl + tr) / 2;
			build(a, v*2, tl, tm);
			build(a, v*2+1, tm+1, tr);
			value[v] = value[v*2] + value[v*2+1]; // merge function minimum , maximum , xor 
		}
	}
	ll sum(int v, int tl, int tr, int l, int r) {
		if (l > r) 
			return 0;
		if (l == tl && r == tr) {
			return value[v];
		}
		int tm = (tl + tr) / 2;
		return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r); // merge function
	}

	void update(int v, int tl, int tr, int pos, ll new_val) {
		if (tl == tr) {
			value[v] = new_val;
		} else {
			int tm = (tl + tr) / 2;
			if (pos <= tm)
				update(v*2, tl, tm, pos, new_val);
			else
				update(v*2+1, tm+1, tr, pos, new_val);
			value[v] = value[v*2] + value[v*2+1]; // merge
		}
	}
};

int main(){
	std::ios::sync_with_stdio(false);
    cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	vector<ll> a(n,0);
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	segmentTree segTree;
	segTree.init(n,0);
	segTree.build(a,1,0,n-1);
	for(int i = 0;i<q;i++){
		int type;
		cin>>type;
		// cout<<1<<endl;
		if(type == 1){
			ll a,b;
			cin>>a>>b;
			segTree.update(1,0,n-1,a,b);
			// printf("Update\n");
		}
		else{
			int l,r;
			cin>>l>>r;
			printf("%lld\n",segTree.sum(1,0,n-1,l,r-1));
		}
	}
}