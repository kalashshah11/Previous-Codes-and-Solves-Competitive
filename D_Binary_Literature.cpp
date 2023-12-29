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
        int n;
		cin>>n;
		vector<string> v(3);
		for(int i = 0;i<3;i++){
			cin>>v[i];
		}
		vector<int> counts(3);
		// vector<int> counts(3);
		for(int j=0;j<3;j++)
		for(int i =0 ;i<2*n;i++){
			if(v[j][i] == '1')
				counts[j]++;
		}
		for(int i = 0;i<3;i++){
			int j = (i+1)%3;
			if(counts[i] >= n && counts[j] >= n){
				// cout<<i<<" "<<j<<endl;
				vector<int> groups(4*n);
				// put 1s
				for(int k = 0;k<max(counts[i],counts[j]);k++){
						groups[2*k + 1] = 1;
				}
				int l = 0;
				int m = 0;
				int k = 0;
				while(l < 2*n || m < 2*n){
					int countl = 0;
					int countm = 0;
					while(l < 2*n){
						if(v[i][l] == '0'){
							countl++;
						}
						else{
							break;
						}
						l++;
					}
					while(m < 2*n){
						if(v[j][m] == '0'){
							countm++;
						}
						else{
							break;
						}
						m++;
					}
					l++;
					m++;
					groups[k] = max(countl,countm);
					k += 2;
				}

				string ans;
				for(int l = 0;l<groups.size();l++){
					for(int m = 0;m<groups[l];m++){
						if(l%2 == 0){
							ans.pb('0');
						}
						else{
							ans.pb('1');
						}
					}
				}
				cout<<ans<<endl;
				break;
			}
			else if(counts[i] < n && counts[j] < n){
				vector<int> groups(4*n);
				//puts 0
				// cout<<i<<" "<<j<<endl;
				for(int k = 0;k<max(2*n - counts[i],2*n - counts[j]);k++){
						groups[2*k + 1] = 1;
				}
				int l = 0;
				int m = 0;
				int k = 0;
				while(l < 2*n || m < 2*n){
					int countl = 0;
					int countm = 0;
					while(l < 2*n){
						if(v[i][l] == '1'){
							countl++;
						}
						else{
							break;
						}
						l++;
					}
					while(m < 2*n){
						if(v[j][m] == '1'){
							countm++;
						}
						else{
							break;
						}
						m++;
					}
					l++;
					m++;
					groups[k] = max(countl,countm);
					k += 2;
				}
			
				string ans;
				for(int l = 0;l<groups.size();l++){
					for(int m = 0;m<groups[l];m++){
						if(l%2 == 0){
							ans.pb('1');
						}
						else{
							ans.pb('0');
						}
					}
				}
				cout<<ans<<endl;
				break;
			}
		}
		
		
		
		
		

    }

    return 0;
}
