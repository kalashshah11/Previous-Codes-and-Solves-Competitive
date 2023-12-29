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

ll function(string& st,string& str){
		
		
		
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
		string st;
		cin>>st;
		n = st.size();
		map<char,int> mp;
		vector<int> count(4,0);
		mp['A'] = 0;
		mp['N'] = 1;
		mp['O'] = 2;
		mp['T'] = 3;
    	for(int i=0;i<n;i++) 
			count[mp[st[i]]]++;
		// for(int i = 0;i<4;i++){
		// 	cout<<count[i]<<" ";
		// }
		vector<char> permutation({'A', 'N','O', 'T'});
		string fin;

		ll maxi = -1;
		do
		{
			string str;
			for(int i=0;i<4;i++) {
				for(int j = 0;j<count[mp[permutation[i]]];j++) {
					str.pb(permutation[i]);
				}
			}
			int n = st.size();
			int i = 0;
			vector<ll> first(4,mod);
			vector<ll> last(4,mod);
			while(i < n){
				int z = mp[str[i]];
				char x = str[i];
				first[z] = i;
				while(i < n && str[i] == x){
					i++;
				}
				last[z] = i-1;
			}
			ll ans = 0;
			for(int i = 0;i<n;i++){
				int x = mp[st[i]];
				if(first[x] == last[x]){
					for(int j = 0;j<4;j++){
						if(first[j] < first[x]){
							first[j] += 1;
							last[j] += 1;
						}
					}
					ans += (first[x] - i);
					last[x] = mod;
					first[x] = mod;
				}
				else{
					for(int i = 0;i<4;i++){
						if(first[i] < first[x]){
							first[i] += 1;
							last[i] += 1;
						}
					}
					ans += (first[x] - i);
					first[x] += 1;
				}
			}
		
			if(ans > maxi){
				fin = str;
				maxi=ans;
			} 
				
		} while(next_permutation(all(permutation)));
		cout<<fin<<endl;
    }

    return 0;
}
