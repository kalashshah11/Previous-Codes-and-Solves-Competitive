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
        // cout<<"Case #"<<t<<": ";
        int n,m;
        cin>>n;
		vector<int> a;
		read(n,a);
		sort(a.begin(),a.end());
		int mini = a[0];
		int maxi = a.back();
		map<int,int> mp;
		for(auto x : a){
			mp[x]++;
		}
		vector<int> nearest(n);
		nearest[0] = a[1] - a[0];
		nearest[n-1] = a[n-1] - a[n-2];
		for(int i = 1;i<n-1;i++){
			nearest[i] = min(a[i] - a[i-1],a[i+1] - a[i]);
		}
		int ans = mod;
		if(n == 2){
			cout<<0<<endl;
			continue;
		}
		for(int i = 1;i<n-1;i++){
			int x = a[i];
			if(x - mini == maxi - x && mp[x] > 1){
				ans = 0;
			}
			else if(x - mini == maxi - x){
				ans = min(ans,nearest[i]);
			}
			else{
				// Search maxi + mini - x
				int z = maxi + mini - x;
				auto it = lower_bound(a.begin(),a.end(),maxi + mini - x);
				int y = it - a.begin();
				if(a[y] == mini || a[y] == maxi){
					if(mp[a[y]] > 1){
						ans = 0;
					}
					else{
						ans = min(ans,nearest[y]);
					}
				}
				else
					ans = min(ans,a[y] - z);
				if(y != 0){
					ans = min(ans,z - a[y-1]);
				}
				cout<<x<<" "<<y<<" "<<z<<endl;
			}
		}
		cout<<ans<<endl;

    }

    return 0;
}
