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
int computeXOR(int n) // 0 to n
{
   
  // If n is a multiple of 4
  if (n % 4 == 0)
    return n;
 
  // If n%4 gives remainder 1
  if (n % 4 == 1)
    return 1;
 
  // If n%4 gives remainder 2
  if (n % 4 == 2)
    return n + 1;
 
  // If n%4 gives remainder 3
  return 0;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        int n;
		cin>>n;
		int eXor = 0;
		int oXor = 0;
		int offset = 1048576;
		if(computeXOR(n-1) == 0){
			// print 0 to n-1
			for(int i  =0;i<n;i++)
			{
				cout<<i<<" ";
			}
		}
		else if(computeXOR(n-2) == 0){
			// 0 - n-3 offset+n-2 offset
			for(int i=0;i<n-2;i++)
			{
				cout<<i<<" ";
			}
			cout<<offset + n-2<<" "<<offset<<" ";
		}
		else if(computeXOR(n-3) == 0){
			for(int i=0;i<n-3;i++)
			{
				cout<<i<<" ";
			}
			cout<<3*offset + n-3<<" "<<offset<<" "<<2*offset<<" ";
			// 0 to n - 4 offset + 2offset + n-3, offset,2offset
		}
		else{
			for(int i=0;i<n-3;i++)
			{
				cout<<i<<" ";
			}
			cout<<3*offset<<" "<<offset<<" "<<2*offset<<" ";
			// 0 to n - 4 offset + 2offset, offset,2offset
		}
		cout<<endl;
        
    }

    return 0;
}
