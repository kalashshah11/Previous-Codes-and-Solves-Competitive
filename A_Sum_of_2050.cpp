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
set<int> sums;
void subsetSums(vector<int> arr, int n)
{
    // There are totoal 2^n subsets
    long long total = 1<<n;
 
    // Consider all numbers from 0 to 2^n - 1
    for (long long i=0; i<total; i++)
    {
        long long sum = 0;
 
        // Consider binary reprsentation of
        // current i to decide which elements
        // to pick.
        for (int j=0; j<n; j++)
            if (i & (1<<j))
                sum += arr[j];
 
        // Print sum of picked elements.
        // cout << sum << " ";
        sums.insert(sum);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    // cin>>T;
    // cout<<"Case #"<<t;
    for(int t = 1;t<=T;t++)
    {
        ll n,m;
		int dp[4][5][6] = {};
        dp[0][0][0] = 1;
        for(int i = 0;i<=3;i++){
            for(int j = 0;j<=4;j++){
                for(int k = 0;k<=5;k++){
                    if(i!=0)
                    dp[i][j][k] += dp[i-1][j][k];
                    if(j!=0)
                    dp[i][j][k] += dp[i][j - 1][k];
                    if(k!=0)
                    dp[i][j][k] += dp[i][j][k - 1];
                }
            }
        }
        cout<<dp[3][4][5]<<endl;
    }

    return 0;
}
