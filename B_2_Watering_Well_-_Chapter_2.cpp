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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
        cout<<"Case #"<<t<<": ";
		long long n,q;
		cin>>n;
		vector<long long> x(n,0);
		vector<long long> y(n,0);
		long long sumx = 0;
		long long sumy = 0;
		long long sumsqx = 0;
		long long sumsqy = 0;
		long long tempx = 0;
		long long tempy = 0;
		for(int i = 0;i<n;i++){
			cin>>x[i]>>y[i];
			sumx = (sumx + x[i])%mod;
			sumx = (sumx % mod + mod)%mod;
			tempx = x[i] * x[i];
			tempx = tempx%mod;
			sumsqx = (sumsqx + tempx)%mod;
			sumsqx = (sumsqx%mod + mod)%mod;
			sumy = (sumy + y[i])%mod;
			sumy = (sumy % mod + mod)%mod;
			tempy = y[i] * y[i];
			tempy = tempy%mod;
			sumsqy = (sumsqy + tempy)%mod;
			sumsqy = (sumsqy%mod + mod)%mod;
		}
		cin>>q;
		long long suma = 0;
		long long sumb = 0;
		long long sumsqa = 0;
		long long sumsqb = 0;
		long long tempa = 0;
		long long tempb = 0;
		vector<long long> a(q,0);
		vector<long long> b(q,0);
		for(int i = 0;i<q;i++){
			cin>>a[i]>>b[i];
			suma = (suma + a[i])%mod;
			suma = (suma % mod + mod)%mod;
			tempa = a[i] * a[i];
			tempa = tempa%mod;
			sumsqa = (sumsqa + tempa)%mod;
			sumsqa = (sumsqa%mod + mod)%mod;
			sumb = (sumb + b[i])%mod;
			sumb = (sumb % mod + mod)%mod;
			tempb = b[i] * b[i];
			tempb = tempb%mod;
			sumsqb = (sumsqb + tempb)%mod;
			sumsqb = (sumsqb%mod + mod)%mod;
		}
		long long calcaddx = sumsqx%mod;
		long long calcadda = sumsqa%mod;
		calcaddx = ((calcaddx%mod + sumsqy%mod) + mod)%mod;
		calcadda = ((calcadda%mod + sumsqb%mod) + mod)%mod;
		calcadda *= n;
		calcadda = (calcadda%mod + mod)%mod;
		calcaddx *= q;
		calcaddx = (calcaddx%mod + mod)%mod;
		long long calcsubx = suma * sumx;
		calcsubx = (calcsubx%mod + mod)%mod;
		long long calcsuby = sumb * sumy;
		calcsuby = (calcsuby%mod + mod)%mod;
		long long calcsub = calcsubx + calcsuby;
		calcsub = (calcsub%mod + mod)%mod;
		calcsub *= -2;
		calcsub = (calcsub%mod + mod)%mod;
		long long calcadd = calcadda + calcaddx;
		calcadd = (calcadd%mod + mod)%mod;
		long long ans = calcadd + calcsub;
		ans = (ans%mod + mod)%mod;
        cout<<ans<<endl;
    }

    return 0;
}
