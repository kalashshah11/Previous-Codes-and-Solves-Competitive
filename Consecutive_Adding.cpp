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
vector<vector<ll>> transpose(vector<vector<ll> > b)
{
    vector<vector<ll> > trans_vec(b[0].size(), vector<ll>());

    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            trans_vec[j].push_back(b[i][j]);
        }
    }

    return trans_vec;    // <--- reassign here
}
string solve(){
	int n,m,x;
	cin>>n>>m>>x;
	vector<vector<ll>> A(n,vector<ll>(m));
	for(int i =0 ;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>A[i][j];
		}
	}
	for(int i =0 ;i<n;i++){
		for(int j = 0;j<m;j++){
			ll v;
			cin>>v;
			A[i][j] -= v;
		}
	}
	for(int i = 0;i<n;i++){
		ll subtract = 0;
		vector<ll> temp = A[i];
		for(int j = 0;j<m;j++){
			if(j < x){
				temp[j] -= subtract;
				subtract += temp[j];
			}
			else{
				subtract -= temp[j-x];
				temp[j] -= subtract;
				subtract += temp[j];
			}			
		}
		for(int j = 0;j<=m-x;j++){
			temp[j] = 0;
		}
		A[i] = temp;
	}
	A = transpose(A);
	for(int i = 0;i<m;i++){
		int subtract = 0;
		vector<ll> temp = A[i];
		for(int j = 0;j<n;j++){
			if(j < x){
				temp[j] -= subtract;
				subtract += temp[j];
			}
			else{
				subtract -= temp[j-x];
				temp[j] -= subtract;
				subtract += temp[j];
			}			
		}
		for(int j = 0;j<=n-x;j++){
			temp[j] = 0;
		}
		A[i] = temp;
	}
	int flag = 0;
	for(int i =0 ;i<m;i++){
		for(int j = 0;j<n;j++){
			if(A[i][j]){
				flag = 1;
				break;
			}
		}
		// cout<<endl;
	}
	if(flag)
		return "No";

	return "Yes";
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    cin>>T;
    // cout<<"Case #"<<t;
    for(int t = 1;t<=T;t++)
    {
        cout<<solve()<<endl;

    }

    return 0;
}
