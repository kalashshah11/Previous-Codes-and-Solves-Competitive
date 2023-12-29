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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        // int n,m;
		// cin>>n;
		// map<int,int> mp;
		// vector<pair<int,int>> x(n);
		// for(int i =0;i<n;i++){
		// 	cin>>x[i].first;
		// 	x[i].second = i;
		// 	mp[x[i].first]++;
		// }
		// sort(all(x));
		// int count=0;
		// vector<int> ans(n);
		// for(int i = 0;i<n;){
		// 	int val = mp[x[i].first];
		// 	int y = x[i].first;
		// 	while(i < n && x[i].first == y){
		// 		int left = n - count - val;
		// 		ans[x[i].second] = 2*min(count,left) + val - 1 + val%2;
		// 		i++; 
		// 	}
		// 	count += val;
		// 	// cout<<val<<" "<<count<<endl;
		// }
        // for(int i = 0;i<n;i++){
		// 	cout<<ans[i]<<" ";
		// }
		// cout<<endl;
		int n;
      cin >> n;
      int arr[n], brr[n];
      for (int i = 0; i < n; i++) {
         cin >> arr[i];
      }
      for (int i = 0; i < n; i++) {
         brr[i] = arr[i];
      }
      sort(arr, arr + n);
      map<int, int> mp;
      for (int i = 0; i < n; i++) {
         mp[arr[i]] = max(mp[arr[i]], min((i - 0) * 2 + 1, (n - 1 - i) * 2 + 1));
      }
      for (int i = 0; i < n; i++) {
         cout << mp[brr[i]] << ' ';
      }
      cout << '\n';
    }

    return 0;
}
