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
    // cin>>T;
    
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        int n,m;
		string x;
		cin>>x;
		// ll ans = 1;
		int counto = 0;
		int countqm = 0;
		for(int i = 0;i<x.size();i++){
			if(x[i] == 'o'){
				// ans *= 9;
				counto++;
			}
			else if(x[i] == '?'){
				// ans *=/ 10;
				countqm++;
			}
		}
		if(counto > 4){
			cout<<0<<endl;
		}
		else if(counto == 4){
			cout<<24<<endl;
		}
		else if(counto == 3){
			cout<<countqm*24 + 36<<endl;
		}
		else if(counto == 2){
			cout<<(countqm * (countqm - 1))/2*24 + countqm*36 + 14<<endl;
		}
		else if(counto == 1){
			cout<<(countqm * (countqm - 1) *(countqm-2))*4 + (countqm * (countqm - 1))*18 + countqm*14 + 1<<endl;
		}
		else if(counto == 0){
			cout<<(countqm * (countqm - 1) *(countqm-2)*(countqm - 3)) + (countqm * (countqm - 1) *(countqm-2))*6 + (countqm * (countqm - 1))*7 + countqm<<endl;
		}
    }
	// 12 * 3C1
	
    return 0;
}
