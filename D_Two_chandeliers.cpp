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
ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
// ax + by = gcd(a,b)
ll binarysearch(ll n,ll m,ll k,ll lcm1,vector<ll>& minimumday){
	ll low = 1;
	ll high = 2LL * max(n,m) * 1e12;
	// cout<<lcm1<<endl;
	while(high > low){
		ll mid = (high + low)/2;
		// calculate with mid;
		ll ans = 0;
		for(int i = 1;i<=2*max(n,m);i++){
			
			if(minimumday[i] != -1){
				ans += mid/lcm1;
				if(mid%lcm1 >= minimumday[i] && minimumday[i] != 0){
					ans++;
				}
			}
		}
		// cout<<low<<" "<<high<<" "<<mid<<" "<<ans<<" "<<k<<endl;
		if(mid - ans >= k){
			high = mid;
		}
		else{
			low = mid + 1;
		}
	}
	// cout<<lcm1<<endl;
	return low;

}
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    //cin>>T;
    // cout<<"Case #"<<t;
    for(int t = 1;t<=T;t++)
    {
        ll n,m,k;
		cin>>n>>m>>k;
		vector<int> a(2*max(n,m)+1);
		vector<int> b(2*max(n,m)+1);
		// see if solution exists
		ll u,v;
		ll a1 = n;
		ll a2 = m;
		ll a3 = gcd(n,m,u,v);
		// found u,v; 
		for(int i = 1;i<=n;i++){
			int temp;
			cin>>temp;
			a[temp] = i;
		}
		for(int i = 1;i<=m;i++){
			int temp;
			cin>>temp;
			b[temp] = i;
		}
        // a[1] b[1]
		ll lcm = m*n/a3;
		vector<ll> minimumday(2*max(n,m) + 1,-1);
		for(int i = 1;i<= 2*max(n,m);i++){
			if((a[i] - b[i])%a3 == 0 && a[i] > 0 && b[i] > 0){
				minimumday[i] = ((b[i] + m * v * (a[i] - b[i])/a3)%lcm + lcm)%lcm;
			}
			// cout<<minimumday[i]<<" ";
		}
		cout<<binarysearch(n,m,k,lcm,minimumday)<<endl;
		
    }

    return 0;
}
