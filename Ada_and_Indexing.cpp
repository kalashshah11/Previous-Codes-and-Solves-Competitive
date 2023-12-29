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
struct TrieSingle{
	int prefixes;
	int ends;
	vector<int> next;
	TrieSingle(){
		prefixes = 0;
		ends = 0;
		next.resize(26,-1);
	}
};

struct Trie{
	int root;
	int size;
	vector<TrieSingle> tries;
	void init(){
		root = 0;
		size = 1;
		tries.resize(1,TrieSingle());
	}
	void AddString(string a){
		int curr = root;
		for(int i = 0;i<a.size();i++){
			tries[curr].prefixes++;
			if(tries[curr].next[a[i]-'a'] == -1){
				tries.push_back(TrieSingle());
				tries[curr].next[a[i]-'a'] = size++;
			}
			curr = tries[curr].next[a[i]-'a'];
		}
		tries[curr].prefixes++;
		tries[curr].ends++;
	}
	int search(string key)
	{
		int curr = root;
		for (int i = 0; i < key.length(); i++)
		{
			int index = key[i] - 'a';
			if (tries[curr].next[index] == -1)
				return false;
	
			curr = tries[curr].next[index];
		}
		return tries[curr].prefixes;
	}
};
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
		Trie t1;
		cin>>n>>m;
		t1.init();
		for(int i = 0;i<n;i++){
			string x;
			cin>>x;
			t1.AddString(x);
		}
		for(int i = 0;i<m;i++){
			string x;
			cin>>x;
			printf("%d\n",t1.search(x));
		}
        
    }

    return 0;
}
