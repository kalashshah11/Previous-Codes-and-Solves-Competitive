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
ll gcd( ll a, ll b )
    {
        if(b==0)
        {
             return a;
        }
        else
        {
             return gcd( b, a%b );
        }
    }
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    cin>>T;
    vector<int> primes({2,3,5,7,11,13,17,19,23,29,31,37,41});
    for(int t = 1;t<=T;t++)
    {
		cout<<"Case #"<<t<<": ";
        int n;
		cin>>n;
		vector<int> a(n,0);
		string s2;
		cin>>s2;
		set<int> s1;
		for(int i = 0;i<s2.size();i++){
			if(s2[i] == '1'){
				a[i] = 1;
			}
		}
		int q;
		cin>>q;
		for(int i = 0;i<q;i++){
			int x;
			cin>>x;
			if(s1.find(x) != s1.end()){
				s1.erase(x);
			} else {
				s1.insert(x);
			}
		}
		for(auto it = s1.begin();it!=s1.end();it++){
			int y = *it;
			long long x = y;
			for(long long j = 1; x*j <= n;j++){
				a[x*j-1] = 1-a[x*j - 1];
			}
		}
		long long count = 0;
		for(long long i = 1;i<=n;i++){
			if(a[i-1] != 0){
				long long x = i;
				count++;
				for(long long j = 1; x*j <= n;j++){
					a[x*j-1] = 1-a[x*j - 1];
				}
			}
		}
		cout<<count<<endl;
    }

    return 0;
}