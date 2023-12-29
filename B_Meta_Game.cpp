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
int mod = 1000000009;
vector<int> preprocessString(const vector<int> &s) {
    vector<int> result(1,mod);
    for (int c : s) {
        result.push_back(c);
        result.push_back(mod);
    }
    return result;
}

pair<int,int> longestPalindromicSubstring(const vector<int> &s) {
    vector<int> str = preprocessString(s);
    int n = str.size();

    vector<int> P(n, 0); // Array to store the lengths of palindromes centered at each character
    int center = 0;     // Center of the rightmost palindrome
    int right = 0;      // Right boundary of the rightmost palindrome

    for (int i = 0; i < n; i++) {
        // If i is within the right boundary of the rightmost palindrome
        if (i < right) {
            int mirror = 2 * center - i; // Mirror of i with respect to center
            P[i] = min(right - i, P[mirror]);
        }

        // Expand the palindrome centered at i
        int a = i + (1 + P[i]);
        int b = i - (1 + P[i]);
        while (a < n && b >= 0 && str[a] == str[b]) {
            P[i]++;
            a++;
            b--;
        }

        // If the palindrome centered at i expands past the right boundary of
        // the rightmost palindrome, adjust center and right boundary.
        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }
    }

    int maxLen = 0; // Length of the longest palindrome
    int maxCenter = 0; // Center of the longest palindrome
    for (int i = 0; i < n; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            maxCenter = i;
        }
    }

    int start = (maxCenter - maxLen) / 2; // Start of the longest palindrome
    return {maxCenter, maxLen};
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";
		int n;
		cin>>n;
		vector<int> a(n);
		vector<int> b(n);
		int flag = 0;
		for(int i = 0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
			if(a[i] != b[i]){
				flag = 1;
			}
		}
		vector<int> c(b.begin(), b.end());
		c.insert(c.end(), a.begin(), a.end());
		c.insert(c.end(), b.begin(), b.end());
		pair<int,int> p = longestPalindromicSubstring(c);
		int start = (p.first - p.second)/2;
		// cout<<p.first<<" "<<p.second<<" "<<start<<endl;
		if(p.second % 2 || p.second < n || flag == 0){
			cout<<-1<<endl;
		}
		else {
			if(start == 0){
				if(a[0] < b[0])
				cout<<(p.second - 2*n)/2<<endl;
				else{
					cout<<(p.second - 2*n)/2 + n<<endl;
				}
			} else {
				if(a[0] < b[0])
				cout<<(2*n - start)/2<<endl;
				else
				cout<<(2*n-start)/2 + n<<endl;
			}
		}
	}

	return 0;
}
