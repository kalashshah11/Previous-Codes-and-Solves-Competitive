#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#include <iostream>
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
struct DSU{
	int tsize;
	vector<ll> parent;
	vector<ll> rank;
	vector<ll> size;
	ll maxsize = 1;
	void init(int n)
	{
		tsize = n;
		parent.resize(n+1);
		rank.resize(n+1,0);
		size.resize(n+1,1);
		for(int i =1 ;i<=n;i++)
		{
			parent[i] = i;
		}   
	}
	ll getParent(ll a) {
		// ll i = a;
		// cout<<a<<endl;
		return parent[a] = (parent[a] == a)?a:getParent(parent[a]); 
	}
	int doUnion(ll newa, ll newb) {
		ll a = getParent(newa);
		ll b = getParent(newb);
		if (a != b) {

			if(rank[a] < rank[b])
			{
				ll temp = a;
				a = b;
				b = temp;
			}
			if(rank[a] == rank[b])
			{
				rank[a] += 1;
			}
			// cout<<b<<" "<<a<<" "<<parent[b]<<endl;
			parent[b] = a;
			size[a] += size[b];
			maxsize = max(maxsize,size[a]);
			size[b] = 0;
			return 1;
		} 
		else
			return 0;  
	}
	ll getSize(int a)
	{
		return size[getParent(a)];
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	int T = 1;
	// cin>>T;
	//segmentedSieve(1000000000LL);
	for(int t = 1;t<=T;t++)
	{
		int n,d;
		cin>>n>>d;
		DSU mydsu;
		mydsu.init(n);
		for(int i = 0;i<d;i++){
			int k;
			cin>>k;
			if(k == 0)
				continue;
			else{
				int first;
				cin>>first;
				for(int j = 0;j<k-1;j++){
					int x;
					cin>>x;
					mydsu.doUnion(x,first);
				}
			}
		}
		for(int i=1;i<=n;i++){
			cout<<mydsu.getSize(i)<<" ";
		}
		  
	}

	return 0;
}