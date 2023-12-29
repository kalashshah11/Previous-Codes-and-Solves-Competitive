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
ll power(ll x, ll y, ll p) 
{ 
	int res = 1;      // Initialize result 

	x = x % p;  // Update x if it is more than or 
			// equal to p 

	while (y > 0) 
	{ 
	// If y is odd, multiply x with result 
		if (y & 1) 
			res = (res*x) % p; 

	// y must be even now 
		y = y>>1; // y = y/2 
		x = (x*x) % p; 
	} 
	return res; 
} 

struct BinaryTree{
	char a;
	ll left = 0;
	ll right = 0;
	ll val = 0;
	ll total = 0;
	ll parent = -1;
	ll leftchild = -1;
	ll rightchild = -1;
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    // cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        int n,m;
		cin>>n;
		ll players = power(2,n,mod);
		vector<BinaryTree> v(2*players-1);
		queue<int> q;
		int z = 0;
		for(int i = 0;i<players;i++){
			q.push(i);
			v[i].val = 1;
			z++;
		}
		map<int,int> indexes;
		for(int i = 0;i<players - 1;i++){
			char c;
			cin>>c;
			int x = q.front();
			q.pop();
			int y = q.front();
			q.pop();
			v[z].right = v[y].val;
			v[z].left = v[x].val;
			v[z].total = v[z].left + v[z].right;
			v[z].a = c;
			v[z].leftchild = x;
			v[z].rightchild = y;
			if(c == '1'){
				v[z].val = v[z].right;
			}
			else if(c == '0'){
				v[z].val = v[z].left;
			}
			else{
				v[z].val = v[z].total;
			}
			v[x].parent = z;
			v[y].parent = z;
			indexes[i+1] = z;
			q.push(z);
			z++;
		}
		int q1;
		cin>>q1;
		for(int i = 0;i<q1;i++){
			int idx;
			char c;
			cin>>idx>>c;
			// cout<<idx<<" "<<c<<endl;
			int w = indexes[idx];
			v[w].a = c;
			if(c == '1'){
				v[w].val = v[w].right;
			}
			else if(c == '0'){
				v[w].val = v[w].left;
			}
			else{
				v[w].val = v[w].total;
			}
			w = v[w].parent;
			while(w != -1){
				v[w].right = v[v[w].rightchild].val;
				v[w].left = v[v[w].leftchild].val;
				v[w].total = v[w].left + v[w].right;
				if(v[w].a == '1'){
					v[w].val = v[w].right;
				}
				else if(v[w].a == '0'){
					v[w].val = v[w].left;
				}
				else{
					v[w].val = v[w].total;
				}
				w = v[w].parent;
			}
			printf("%lld\n",v.back().val);
		}
    }

    return 0;
}
