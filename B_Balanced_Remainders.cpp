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
ll nextPowerOf2(ll n)  
{  
    unsigned count = 0;  
      
    // First n in the below condition  
    // is for the case where n is 0  
    if (n && !(n & (n - 1)))  
        return n;  
      
    while( n != 0)  
    {  
        n >>= 1;  
        count += 1;  
    }  
      
    return 1 << count;  
}  
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    cin>>T;
    // cout<<"Case #"<<t;
    for(int t = 1;t<=T;t++)
    {
        int n,m;
		cin>>n;
		vector<int> a;
		read(n,a);
		int ans = 0;
		vector<int> count(3);
		for(int i  =0;i<n;i++){
			count[a[i]%3]++;
		}
		// cout<<count[0]<<" "<<count[1]<<" "<<count[2]<<endl;
		if(count[0] > n/3){
			ans += count[0] - n/3;
			count[1] += ans;
			count[0] = n/3;
		}
		// cout<<ans<<" ";
		if(count[1] > n/3){
			ans += count[1] - n/3;
			count[2] += count[1] - n/3;
			count[1] = n/3;
		}
		// cout<<ans<<" ";
		if(count[2] > n/3){
			ans += count[2] - n/3;
			count[0] += count[2] - n/3;
			count[2] = n/3;
		}
		// cout<<ans<<" ";
		if(count[0] > n/3){
			ans += count[0] - n/3;
			count[1] += count[0] - n/3;
			count[0] = n/3;
		}
		// cout<<ans<<" ";
		if(count[1] > n/3){
			ans += count[1] - n/3;
			count[2] += count[1] - n/3;
			count[1] = n/3;
		}
		cout<<ans<<endl;

    }

    return 0;
}
