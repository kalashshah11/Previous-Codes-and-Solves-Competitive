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
// int query(pair<int,int> p){
// 	cout<<"? "<<p.first<<" "<<p.second<<endl;
// 	int x;
// 	cin>>x;
// 	return x;
// }
// void solve(int n){
// 	pair<int,int> p(1,n);
// 	vector<int> queries;
// 	int shigh = query({1,n});
// 	while(low < high){
// 		int mid = (low + high)/2;
// 		if(queries.back() >= mid){
// 			// check(queries.back() == query(mid,high))
// 			if(high - mid + 1 >= 2){
// 				int x = query(low,mid - 1);
// 				if(shigh == x){
// 					// 2nd highest , highest same group
// 					low = mid;
// 				}
// 				else{
// 					// 2nd highest , highest diff group
// 					shigh = x;
// 					high = mid - 1;
// 				}
// 			}
// 			else{
// 				cout<<"! "<<low<<endl;
// 			}
// 		}
// 		else{
// 			// check(queries.back() == query(low,mid - 1))
// 			//  1 - 2 - 3
// 			if(mid - low >= 2){
// 				int x = query(low,mid - 1);
// 				if(YES){
// 					// 2nd highest , highest same group
// 				}
// 				else{
// 					// 2nd highest , highest diff group
// 				}
// 			}
// 			else if(mid{
				
// 			}
			
// 		}
// 	}
	
// }
map<pair<int,int>,int> mp1;
map<pair<int,int>,int> mp;
int flag = 0;
void DFS(int a, int b){
	mp[{a,b}] = 1;
	cout<<a<<" "<<b<<endl;
	while(!q.empty()){
		auto x = q.front();
		q.pop();
		if(x.first == x.second){
			mp1.insert(all(mp));
		}
	}
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
		for(int i = 1;i<=1000;i++){
			for(int j = 1;j<=1000;j++){
				mp.clear();
				if(mp[{i,j}] == 0){
					flag = 0;
					cout<<i<<" "<<j<<endl;
					DFS(i,j);
					if(!flag){
						mp1[{i,j}] = 1;
					}
				}
			}
		}
		for(int i = 1;i<=1000;i++){
			for(int j = 1;j<=1000;j++){
				if(mp1[{i,j}] == 0){
					cout<<i<<" "<<j<<endl;
				}
			}
		}
        // DFS(2,1);
    }

    return 0;
}
