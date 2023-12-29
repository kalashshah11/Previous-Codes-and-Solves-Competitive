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
ll solve(){
	ll N,E,H,A,B,C;
	cin>>N>>E>>H>>A>>B>>C;
	ll x = 0;
	ll y= 0;
	if(E == H){
		x = E;
	}
	else if(E > H){
		y = (E-H)/2;
		x = H;
		x += y;
	}
	else{
		y = (H-E)/3;
		x = E;
		x += y;
	}
	if(N > x){
		return -1;
	}
	else{
		ll sum = 0;
		ll count = 0;
		if(min(A,min(B,C)) == A){
			if(E >= 2*N){
				sum += N*A;
				count += N;
				E -= 2*N;
			}
			else{
				ll temp = E/2;
				sum += temp*A;
				count += E/2;
				E -= temp*2;
			}
			if(min(B,C) == B && count < N){

				if(H >= 3 * (N - count) ){
					sum += (N - count)*A;
					count += N - count;
					H -= 3*(N - count);
				}
				else{

				}


				if(count < N){

				}
			}
			else if(min(B,C) == C && count < N){






				if(count < N){

				}
			}

			
		}
		else if(min(A,min(B,C)) == B){
			
		}
		else{

		}
		return sum;
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
        cout<<solve()<<endl;
    }

    return 0;
}
