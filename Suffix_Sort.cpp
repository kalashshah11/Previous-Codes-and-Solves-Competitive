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
		vector<int> x;
		read(n,x);
		queue<int> q;
		for(int i = 0;i<n;i++){
			q.push(x[i]);
		}
		vector<int> b(all(x));
		sort(all(x));
		int flag = 0;
		int mini = x[0];
		int maxi = x[n-1];
		int count = 0;
		int flag1 = 0;
		for(int i  = 0;i<n;i++){
			if(x[i] != b[i]){
				flag1 = 1;
				break;
			}
		}
		if(flag1 == 0){
			cout<<"YES"<<endl;
			cout<<0<<endl;
			continue;
		}
		else{
			while(1){
				int prev = q.front();
				q.pop();
				q.push(prev);
				count++;
				if(prev == maxi && q.front() == mini){
					flag = 1;
					break;
				}
				if(count > n){
					break;
				}
				// cout<<prev<<" "<<q.front()<<endl;
			}
			
			// cout<<q.front()<<endl;
		}
		// cout<<flag<<endl;
		if(flag){
			int flagx = 0;
			for(int i =0;i<n;i++){
				if(x[i] != q.front()){
					flagx = 1;
					break;
				}
				else{
					q.pop();
				}
			}
			if(flagx == 1){
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;
				cout<<1<<endl;
			}
		}
		else{
			cout<<"NO"<<endl;
		}
    }

    return 0;
}
