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
        int n,m,x,y;
		cin>>n>>m>>x>>y;
		vector<vector<char>> v(n,vector<char>(m,'*')); 
		int flag = 0;
		for(int i = 0;i<n-2;i+=3){
			for(int j = 0;j<m-2;j+=3){
				if(x >= i+1 && x <= i + 3 && y >= j + 1 && y <= j+3){
					if(x == i + 2 && y == j + 2){
						if((i + j)%2 == 0){
							v[i][j] = 'D';
							v[i][j+1] = 'D';
							v[i][j+2] = 'E';
							v[i+1][j] = 'X';
							v[i+1][j+2] = 'E';
							v[i+2][j] = 'X';
							v[i+2][j+1] = 'F';
							v[i+2][j+2] = 'F';
						}
						else{
							v[i][j] = 'A';
							v[i][j+1] = 'A';
							v[i][j+2] = 'B';
							v[i+1][j] = 'Y';
							v[i+1][j+2] = 'B';
							v[i+2][j] = 'Y';
							v[i+2][j+1] = 'C';
							v[i+2][j+2] = 'C';
						}
					}
					else if((x == i+3 || x == i+1) && y == j + 2){
						if((i + j)%2 == 0){
							v[i][j] = 'I';
							v[i][j+1] = 'J';
							v[i][j+2] = 'K';
							v[i+1][j] = 'I';
							v[i+1][j+1] = 'J';
							v[i+1][j+2] = 'K';
							v[i+2][j] = 'I';
							v[i+2][j+1] = 'J';
							v[i+2][j+2] = 'K';
						}
						else{
							v[i][j] = 'L';
							v[i][j+1] = 'M';
							v[i][j+2] = 'N';
							v[i+1][j] = 'L';
							v[i+1][j+1] = 'M';
							v[i+1][j+2] = 'N';
							v[i+2][j] = 'L';
							v[i+2][j+1] = 'M';
							v[i+2][j+2] = 'N';
						}
						v[x-1][y-1] = '*';
					}
					else{
						if((i + j)%2 == 0){
							v[i][j] = 'D';
							v[i][j+1] = 'D';
							v[i][j+2] = 'D';
							v[i+1][j] = 'E';
							v[i+1][j+1] = 'E';
							v[i+1][j+2] = 'E';
							v[i+2][j] = 'F';
							v[i+2][j+1] = 'F';
							v[i+2][j+2] = 'F';
						}
						else{
							v[i][j] = 'A';
							v[i][j+1] = 'A';
							v[i][j+2] = 'A';
							v[i+1][j] = 'B';
							v[i+1][j+1] = 'B';
							v[i+1][j+2] = 'B';
							v[i+2][j] = 'C';
							v[i+2][j+1] = 'C';
							v[i+2][j+2] = 'C';
						}
						v[x-1][y-1] = '*';
					}
					flag = 1;
					break;
				}
				else{
					if((i + j)%2 == 0){
						v[i][j] = 'D';
						v[i][j+1] = 'D';
						v[i][j+2] = 'D';
						v[i+1][j] = 'E';
						v[i+1][j+1] = 'E';
						v[i+1][j+2] = 'E';
						v[i+2][j] = 'F';
						v[i+2][j+1] = 'F';
						v[i+2][j+2] = 'F';
					}
					else{
						v[i][j] = 'A';
						v[i][j+1] = 'A';
						v[i][j+2] = 'A';
						v[i+1][j] = 'B';
						v[i+1][j+1] = 'B';
						v[i+1][j+2] = 'B';
						v[i+2][j] = 'C';
						v[i+2][j+1] = 'C';
						v[i+2][j+2] = 'C';
					}
				}
			}
		}
		
		for(int i)
		
		
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				cout<<v[i][j];
			}
			cout<<endl;
		}
        
    }

    return 0;
}
