#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
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
struct comp{
	bool operator()(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
		return a.first > b.first;
	}
};
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
		cin>>n>>m;
		vector<int> A(n);
		priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,comp> pq;
		vector<int> changed(n,-1);
		for(int i = 0;i<n;i++){
			cin>>A[i];
		}
		for(int i = 0;i<n-1;i++){
			pq.push({abs(A[i] - A[i+1]),make_pair(i,i+1)});
		}
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			A[a-1] = b;
			if(a != 1){
				pq.push({abs(A[a-1] - A[a-2]),make_pair(a-1,a-2)});
			} 
			if(a != n){
				pq.push({abs(A[a-1] - A[a]),make_pair(a-1,a)});
			}
			
			while(!pq.empty()){
				auto x = pq.top();
				if(abs(A[x.second.first] - A[x.second.second]) != x.first)
					pq.pop();
				else{
					cout<<x.first<<endl;
					break;
				}
			}
		}

        
    }

    return 0;
}
