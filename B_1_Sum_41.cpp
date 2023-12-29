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
        long long a;
		cin>>a;
		bool valid = true;
		vector<int> ans;
		while(a != 1){
			long long preva = a;
			for(int i = 0;i<primes.size();i++){
				if(a%primes[i] == 0){
					a = a/primes[i];
					ans.push_back(primes[i]);
				}
			}
			if(a == preva) {
				valid = false;
				break;
			}
		}
		int sum = 0;
		for(int i = 0;i<ans.size();i++){
			sum += ans[i];
		}
		if(sum > 41){
			valid = false;
		}
		if(valid == false){
			cout<<-1<<endl;
		} else {
			cout<<ans.size() + 41 - sum<<" ";
			for(int i =0;i<ans.size();i++){
				cout<<ans[i]<<" ";
			}
			for(int i = 1;i<=41-sum;i++){
				cout<<1<<" ";
			}
			cout<<endl;
		}

    }

    return 0;
}
