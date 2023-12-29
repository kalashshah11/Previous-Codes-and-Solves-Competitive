#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define priority_queue <ll, std::vector<ll>, std::greater<ll>> mnheap; // mnheap.push(), mnheap.top(), mnheap.pop()
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

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 1;
	cin >> T;
	ll x;
	cin >> x;

	for (int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";
		ll w, e;

		cin >> w >> e;
		string s1 = "SPR";
		string s3 = "RSP";
		// string s2;
		// cin>>s;
		// vector<vector<double>> spr(1, {0, 0, 0});
		// vector<vector<int>> p(1, {0, 1, 0});
		// // vector<vector<int>> s(1, {0, 1, 0});
		// // vector<vector<int>> r(1, {0, 1, 0});
		// // string s1 = "S";
		// string s2 = "P";
		// // string s3 = "R";
		// double count = 1;
		// for (int i = 1; i < 60; i++)
		// {
		// 	spr.pb({p[i - 1][1] / count, p[i - 1][2] / count, p[i - 1][0] / count});
		// 	int x = max_element(all(spr[i])) - spr[i].begin();
		// 	// cout << (x + 2) % 3 << " " << s3[x] << endl;
		// 	s2.pb(s3[x]);
		// 	p.pb(p.back());
		// 	p[i][(x + 2) % 3]++;
		// 	count++;
		// }
		cout << "RPSRPSRPSRPSRPSRPSRPSRPSRPSRPSRPSRPSRPSRPSRPSRPSRPSRPSRPSRPS" << endl;
		// n / 2(k + k + n - 1)
	}

	return 0;
}
