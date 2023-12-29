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
        int n,m;
		vector<string> v(3);
		cin>>v[0]>>v[1]>>v[2];
		int flagO = 0;
		int flagX = 0;
		int flag1 = 0;
		int flag2 = 0;
		int flag3 = 0;
		int countX = 0;
		int countO = 0;
		int count_ = 0;
		for(int i = 0;i<3;i++){
			for(int j = 0;j<3;j++){
				if(v[i][j] == 'O'){
					countO++;
				}
				else if(v[i][j] =='X'){
					countX++;
				}
				else{
					count_++;
				}
			}
		}
		if(countO > countX || countX - countO > 1){
			flag3 = 1;
		}
		for(int i = 0;i<3;i++){
			int countX1 = 0;
			int countO1 = 0;
			for(int j = 0;j<3;j++){
				if(v[i][j] == 'X'){
					countX1++;
				}
				else if(v[i][j] == 'O'){
					countO1++;
				}
			}
			if(countO1 == 3){
				flagO = 1;
			}
			if(countX1 == 3){
				flagX = 1;
			}
		}
		for(int i = 0;i<3;i++){
			int countX1 = 0;
			int countO1 = 0;
			for(int j = 0;j<3;j++){
				if(v[j][i] == 'X'){
					countX1++;
				}
				else if(v[j][i] == 'O'){
					countO1++;
				}
			}
			if(countO1 == 3){
				flagO = 1;
			}
			if(countX1 == 3){
				flagX = 1;
			}
		}
		int countX1 = 0;
		int countO1 = 0;
		for(int i = 0;i<3;i++){
			for(int j = 0;j<3;j++){
				if(i == j){
					if(v[i][j] == 'X'){
						countX1++;
					}
					else if(v[i][j] == 'O'){
						countO1++;
					}
				}
			}
		}
		if(countO1 == 3){
			flagO = 1;
		}
		if(countX1 == 3){
			flagX = 1;
		}
		countX1 = 0;
		countO1 = 0;
		for(int i = 0;i<3;i++){
			for(int j = 0;j<3;j++){
				if(i + j == 2){
					if(v[i][j] == 'X'){
						countX1++;
					}
					else if(v[i][j] == 'O'){
						countO1++;
					}
				}
			}
		}
		if(countO1 == 3){
			flagO = 1;
		}
		if(countX1 == 3){
			flagX = 1;
		}
		if(flagO && flagX){
			flag3 = 1;
		}
		
		if(flag3){
			cout<<3<<endl;
			continue;
		}
		else{
			if(flagX || flagO || count_ == 0){
				if(flagX){
					if(countO == countX - 1){
						cout<<1<<endl;
					}
					else{
						cout<<3<<endl;
					}
					continue;
				}
				if(flagO){
					if(countO == countX){
						cout<<1<<endl;
					}
					else{
						cout<<3<<endl;
					}
					continue;
				}
				if(count_ == 0){
					cout<<1<<endl;
					continue;
				}
			}
			else{
				cout<<2<<endl;
			}
		}
    }

    return 0;
}
