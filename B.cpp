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
            
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    cin>>T;
    // cout<<"Case #"<<t;
    for(int t = 1;t<=T;t++)
    {
        long long n,k; cin >>n >> k;
        vector<long long> a(n); 
        for(auto &it : a){
            cin>>it;
        }
        long long st = 0;
        if(n>1000) st = n-500;
        long long ans = -100000000000000LL;
        for(long long i = st;i < n;i++) 
            for(long long j = i+1;j < n;j++) 
            {
                long long v = (i+1)*(j+1) - k*(a[i]|a[j]);
                ans = max(ans,v);
            }
        printf("%lld\n",ans);
			
    }

    return 0;
}
