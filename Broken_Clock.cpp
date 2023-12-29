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
// #define mod 1000000007
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
const __int128_t bck11 = 15709090909091 * (__int128_t)1;
const __int128_t mod = 43200000000000LL * (__int128_t)1;
bool check(ll a, ll b, ll c) {
    __int128_t x = (((b-a) * bck11) % mod + mod) % mod;
    if ((708 * x - c + b) % mod == 0) {
        ll n = x % (ll)1e9;
        x /= 1e9;
        ll s = x % 60;
        x /= 60;
        ll m = x % 60;
        ll h = x / 60;
        cout << h << " " << m << " " << s << " " << n << "\n";
        return true;
    }
    else return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
        cout<<"Case #"<<t<<": ";
		ll a,b,c;
		cin>>a>>b>>c;
		// assert(v[0] == v[1]/12 && v[0] == v[2]/720);
		// cout<<v[0]<<" "<<v[1]/12<<" "<<v[2]/720<<endl;
		if (check(a, b, c) || check(a, c, b) || check(b, a, c) || check(b, c, a) || check(c, a, b) || check(c, b, a)) {

        }
		
		
    }

    return 0;
}


