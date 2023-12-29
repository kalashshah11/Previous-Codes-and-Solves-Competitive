#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define REP(i, a, b) for (auto i = a; i != b; i++)
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define mp(x, y) make_pair(x, y)
#define mem(a, val) memset(a, val, sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define pb push_back
#define SQ(a) (a) * (a)

using namespace std;

void read(int n, vector<int> &x)
{
	x.clear();
	x.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
}
void read(int n, int m, vector<vector<int>> &x)
{
	x.clear();
	x.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> x[i][j];
	}
}
void read(int n, vector<vector<int>> &x)
{
	x.clear();
	x.resize(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		x[a].pb(b);
		x[b].pb(a);
	}
}
void read(int n, vector<vector<int>> &x, int m)
{
	x.clear();
	x.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		x[a].pb(b);
		x[b].pb(a);
	}
}
void read(int n, vector<ll> &x)
{
	x.clear();
	x.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
}
ll gcd(ll a, ll b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}

void updateBIT(vector<int>& BITree, int n, int index, int val)
{
    index = index + 1;
 
    while (index <= n)
    {
        BITree[index] += val;
        index += index & (-index);
    }
}
 
vector<int> constructBITree(vector<int>& arr, int n)
{
    vector<int> BITree(n+1,0);
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
 
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
 
    return BITree;
}
 
int getSum(vector<int>& BITree, int index)
{
    int sum = 0; 
    index = index + 1;
 
    while (index>0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}
 
// Updates such that getElement() gets an increased
// value when queried from l to r.
void update(vector<int>& BITree, int l, int r, int n, int val)
{
    updateBIT(BITree, n, l, val);
    updateBIT(BITree, n, r+1, -val);
}

class Compare {
public:
    bool operator()(pair<int,int> below, pair<int,int> above)
    {
        if (below.first < above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second > above.second) {
            return true;
        }
 
        return false;
    }
};
 
int main()
{
	std::ios::sync_with_stdio(false);
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";
		int n;
		cin >> n;
		vector<int> arr(n,0);
		priority_queue< pair<int,int>, vector<pair<int,int>>, Compare> pq;
		for(int i = 0;i<n;i++){
			cin>>arr[i];
			pq.push({arr[i],i});
		}
    	vector<int> BITree = constructBITree(arr, n);
		int q;
		cin>>q;
		long long sum = 0;
		for(int i = 0;i<q;i++){
			int x,y;
			cin>>x>>y;
			update(BITree, x-1, y-1, n, 1);
			while(!pq.empty()) {
				auto v = pq.top();
				cout<<v.first<<" "<<v.second<<endl;
				int w = getSum(BITree, v.second);
				if(w%2 == 0){
					sum += v.second + 1;
					break;
				} else {
					pq.pop();
					pq.push({mod-v.first, v.second});
					update(BITree, v.second, v.second, n, -1);
				}
			}
		}
		cout<<sum<<endl;
	}

	return 0;
}