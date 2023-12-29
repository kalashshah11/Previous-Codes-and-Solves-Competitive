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
bool comp(pair<int,int>& a,pair<int,int>& b){
	if(a.first == b.first){
		return a.second > b.second;
	}
	else{
		return a.first < b.first;
	}
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    //cin>>T;
    // cout<<"Case #"<<t;
    for(int t = 1;t<=T;t++)
    {
        int n,m;
		cin>>n;
		vector<pair<int,int>> v(9);
		for(int i = 0;i<9;i++){
			cin>>v[i].first;
			v[i].second = i+1;
		}
		// vector<pair<int,int>> v1(all(v));
		// sort(all(v),comp);
		pair<int,int> p = *min_element(all(v),comp);
		// cout<<p.first<<" "<<p.second<<endl;
		if(n < p.first){
			cout<<-1<<endl;
		}
		else{
			ll digits = n/p.first;
			vector<int> num(digits,p.second);
			ll remaining = n%p.first;
			// check v1 from end
			// cout<<digits<<" "<<remaining<<endl;
			int flag = 1;
			int count = 0;
			while(flag == 1){
				flag = 0;
				for(int i = 8;i>p.second - 1;i--){
					if(remaining >= v[i].first - p.first){
						remaining -= (v[i].first - p.first);
						num[count] = v[i].second;
						count++;
						flag = 1;
						break;
					}
				}
			}
			for(int i = 0;i<num.size();i++){
				cout<<num[i];
			}
			cout<<endl;
			
		}
    }

    return 0;
}
