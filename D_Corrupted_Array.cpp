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
    int T = 1;
    cin>>T;
    // cout<<"Case #"<<t;
    for(int t = 1;t<=T;t++)
    {
        int n,m;
		cin>>n;
		unordered_map<ll,ll> mp;
		vector<ll> v(n+2);
		ll sum = 0;
		for(auto &it : v){
			cin>>it;
			sum += it;
			mp[it]++;
			// cout<<it<<endl;
		}
		int flag = 0;
		vector<ll> ans(n);
		// cout<<mp[18]<<endl;
		for(int i = 0;i<n+2;i++){
			ll x = (sum - v[i]);
			ll extra = v[i];
			mp[v[i]]--;
			// cout<<x/2<<" "<<mp[x/2]<<endl;
			if(mp[x/2] > 0 && x%2 == 0){
				// possible
				flag = 1;
				int flg = 0;
				int k = 0;
				for(int j = 0;j<n+2;j++){
					if(j != i){
						if(v[j] == x/2  && !flg){
							flg = 1;
						}
						else{
							ans[k++] = v[j];
						}
					}
				}
				
			}
			mp[v[i]]++;
		}
		// cout<<endl;
		if(!flag){
			cout<<-1<<endl;
		}
		else{
			sort(all(ans));
			for(int i = 0;i<n;i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}
		
    }

    return 0;
}
//a b c d e f g h