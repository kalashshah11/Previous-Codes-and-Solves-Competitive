#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define mnheap < ll, std::vector<ll>, std::greater<ll> > priority_queue;    // mnheap.push(), mnheap.top(), mnheap.pop()
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
ll run(ll a,ll y,ll len,ll p,ll q,vector<ll>& special){
    cout<<a<<" "<<y<<" "<<len<<" "<<endl;
    if(a >= y - 1)
    {
        if(special[a] == 1){
            return p;
        }
        return q;
    }
    ll a1 = run(2*a + 1,y,len/2,p,q,special);
    ll a2 = run(2*a + 2,y,len/2,p,q,special);
    special[a] = special[2*a + 1] + special[2*a + 2];
    if(special[a] == 0){
        return min(a1 + a2,q);
    }
    return min(a1 + a2,p * len * special[a]);
}
ll solution(ll n,ll p,ll q,vector<ll> v){
    ll x = 1;
    for(int i = 0;i<n;i++){
        x = x * 2;
    }
    ll y = x;
    x *= 2;
    vector<ll> special(x);
    for(auto it : v){
        special[it + y - 2] = 1;
    }
    ll ans = run(0,y,x,p,q,special);
    return (ans%mod + mod)%mod;
}
ll calculate(ll from, ll to, ll p, ll q, const vector<int>& specials)
{

	int ct = upper_bound(specials.begin(), specials.end(), to) - upper_bound(specials.begin(), specials.end(), from - 1);

	if (ct == 0)
		return q;

	if (from == to)
		return p;

	ll ans1 = calculate(from, (from + to) / 2, p, q, specials) + calculate(((from + to) / 2) + 1, to, p, q, specials);
	ll ans2 = (to - from + 1) * ct * p;

	return min({ans1, ans2});
}

int solve(int n, int p, int q, const vector<int>& specials)
{
	auto ans = calculate(1, (1ll << n), p, q, specials);
	const int MOD = 1000'000'000 + 7;
	return (ans + MOD) % MOD;
}
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
        
        cout<<solution(3,2,1,{1,2,3,4,5,6,7,8});
    }

    return 0;
}
