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
struct BST{
	int idx;
	int depth;
	BST* left;
	BST* right;
};
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
		vector<pair<int,int>> a(n);
		for(int i =0;i<n;i++){
			cin>>a[i].first;
			a[i].second = i+1;
		}
		sort(rall(a));
		BST *head = (BST*)malloc(sizeof(BST));
		head->idx = a[0].second;
		head->depth = 0;
		head->left = NULL;
		head->right = NULL;
		vector<int> ans(n);
		ans[a[0].second] = 0;
		for(int i = 1;i<n;i++){
			BST* temp = head;
			int flag = 1;
			while(flag){
				if(a[i].second > temp->idx){
					if(temp->right == NULL){
						temp->right = (BST*)malloc(sizeof(BST));
						temp->right->idx = a[i].second;
						// temp->right->x = a[i].first;
						temp->right->left = NULL;
						temp->right->right = NULL;
						temp->right->depth = temp->depth + 1;
						ans[a[i].second - 1] = temp->right->depth;
						flag = 0;
					}
					else{
						temp = temp->right;
					}
				
				}
				else{
					if(temp->left == NULL){
						temp->left = (BST*)malloc(sizeof(BST));
						temp->left->idx = a[i].second;
						// temp->left->x = a[i].first;
						temp->left->left = NULL;
						temp->left->right = NULL;
						temp->left->depth = temp->depth + 1;
						ans[a[i].second - 1] = temp->left->depth;
						flag = 0;
					}
					else{
						temp = temp->left;
					}
				}
			}
			
		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
    }

    return 0;
}
