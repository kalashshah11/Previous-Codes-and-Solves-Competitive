#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define mnheap < ll, std::vector<ll>, std::greater<ll> > priority_queue;    // mnheap.push(), mnheap.top(), mnheap.pop()
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
        cout<<"Case #"<<t<<": ";
        int n,m;
        string s;
        cin>>s;
		int q;
		cin>>q;
		vector<vector<int>> count(s.size()+1,vector<int>(26));
		for(int i = 1;i<=s.size();i++){
			for(int j = 0;j<26;j++){
				count[i][j] = count[i-1][j];
			}
			count[i][s[i-1]-'a']++;
		}
		int ans = 0;
		int pref = -1;
        for(int i = 0;i<q;i++){
			int l,r;
			cin>>l>>r;
			int flag = 0;
			int fflag1 = 0;
			int fflag2 = 0;
			int ch = -1;
			if((r - l)%2 == 1)
				continue;
			vector<int> diff(26);
			vector<int> diff1(26);
			vector<int> diff2(26);
			// cout<<r - (r-l)/2<<" "<<r - (r-l)/2 + 1<<" "<<l<<" "<<r<<endl;
			for(int j=0;j<26;j++){
				diff[j] = count[r][j] - count[l-1][j];
				if(diff[j]%2 == 1 && flag == 1){
					flag++;
					break;
				}
				if(diff[j]%2 == 1){
					flag = 1;
					ch = j;
				}
				diff1[j] = count[r - (r-l)/2 - 1][j] - count[l-1][j];
				diff2[j] = count[r - (r-l)/2][j] - count[l-1][j];
				// cout<<j<<" "<<diff[j]<<" "<<diff1[j]<<" "<<diff2[j]<<endl;
			}
			if(flag == 1){
				for(int j = 0;j<26;j++){
					if(j != ch){
						if(diff1[j] != diff[j] - diff1[j]){
							fflag1 =1;
							break;
						}
					}
				}
				for(int j = 0;j<26;j++){
					if(j != ch){
						// cout<<diff2[i]<<" "<<diff[i]<<endl;
						if(diff2[j] != diff[j] - diff2[j]){
							fflag2 = 1;
							break;
						}
					}
				}
				// cout<<"fflag: "<<fflag1<<" "<<fflag2<<" "<<ch<<" "<<i<<endl;
				if(fflag1 + fflag2 <= 1){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
        
    }

    return 0;
}
