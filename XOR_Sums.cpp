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
#define mod 998244353
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define pb push_back
#define SQ(a) (a)*(a)
const int N = 200005;
using namespace std;
ll factorialNumInverse[N + 1]; 
// array to precompute inverse of 1! to N! 
ll naturalNumInverse[N + 1]; 
// array to store factorial of first N numbers 
ll fact[N + 1]; 
unsigned ll derangement[N + 1];  
// Function to precompute inverse of numbers 
void InverseofNumber(ll p) 
{ 
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
} 
// Function to precompute inverse of factorials 
void InverseofFactorial(ll p) 
{ 
	factorialNumInverse[0] = factorialNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 


void factorial(ll p) 
{ 
    fact[0] = 1;  
    for (int i = 1; i <= N; i++) { 
        fact[i] = (fact[i - 1] * i) % p; 
    } 
} 

ll Binomial(ll N, ll R, ll p) 
{ 
    ll ans = ((fact[N] * factorialNumInverse[R]) 
            % p * factorialNumInverse[N - R]) 
            % p; 
    return ans; 
}    
ll power(ll x, ll y, ll p) 
{ 
    int res = 1;      // Initialize result 

    x = x % p;  // Update x if it is more than or 
        // equal to p 

    while (y > 0) 
    { 
    // If y is odd, multiply x with result 
        if (y & 1) 
        res = (res*x) % p; 

    // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
            
        
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
const int MOD = 998244353;
const char nl = '\n';
const int MX = 300001; //check the limits, dummy
 
ll modExp(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}
 
ll inv(ll base) {
    int g = MOD, r = base, x = 0, y = 1;
    while (r != 0) {
        int q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }
    return x < 0 ? x+MOD : x;
}
 
ll mul(ll A, ll B) {
	return (A*B)%MOD;
}
 
ll add(ll A, ll B) {
	return (A+B)%MOD;
}
 
ll dvd(ll A, ll B) {
    return mul(A, inv(B));
}
 
ll sub(ll A, ll B) {
    return (A-B+MOD)%MOD;
}
namespace NTT { //Source: Codeforces user neal
    vector<ll> roots = {0, 1};
    vector<int> bit_reverse;
    int max_size = -1;
    ll root;
 
    bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }
 
    int round_up_power_two(int n) {
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;
 
        return max(n, 1);
    }
 
    // Given n (a power of two), finds k such that n == 1 << k.
    int get_length(int n) {
        assert(is_power_of_two(n));
        return __builtin_ctz(n);
    }
 
    // Rearranges the indices to be sorted by lowest bit first, then second lowest, etc., rather than highest bit first.
    // This makes even-odd div-conquer much easier.
    void bit_reorder(int n, vector<ll> &values) {
        if ((int) bit_reverse.size() != n) {
            bit_reverse.assign(n, 0);
            int length = get_length(n);
 
            for (int i = 0; i < n; i++)
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
        }
 
        for (int i = 0; i < n; i++)
            if (i < bit_reverse[i])
                swap(values[i], values[bit_reverse[i]]);
    }
 
    void find_root() {
        max_size = 1 << __builtin_ctz(MOD - 1);
        root = 2;
 
        // Find a max_size-th primitive root of MOD.
        while (!(modExp(root, max_size) == 1 && modExp(root, max_size/2) != 1))
            root++;
    }
 
    void prepare_roots(int n) {
        if (max_size < 0)
            find_root();
 
        assert(n <= max_size);
 
        if ((int) roots.size() >= n)
            return;
 
        int length = get_length(roots.size());
        roots.resize(n);
 
        // The roots array is set up such that for a given power of two n >= 2, roots[n / 2] through roots[n - 1] are
        // the first half of the n-th primitive roots of MOD.
        while (1 << length < n) {
            // z is a 2^(length + 1)-th primitive root of MOD.
            ll z = modExp(root, max_size >> (length+1));
 
            for (int i = 1 << (length - 1); i < 1 << length; i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = (roots[i] * z)%MOD;
            }
 
            length++;
        }
    }
 
    void fft_iterative(int N, vector<ll> &values) {
        assert(is_power_of_two(N));
        prepare_roots(N);
        bit_reorder(N, values);
 
        for (int n = 1; n < N; n *= 2)
            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    ll even = values[start + i];
                    ll odd = values[start + n + i] * roots[n + i];
                    odd %= MOD;
                    values[start + n + i] = even - odd + MOD;
                    values[start + i] = even + odd;
                    values[start + n + i] %= MOD;
                    values[start + i] %= MOD;
                }
    }
 
    const int FFT_CUTOFF = 150;
 
    vector<ll> mod_multiply(vector<ll> left, vector<ll> right) {
        int n = left.size();
        int m = right.size();
 
        // Brute force when either n or m is small enough.
        if (min(n, m) < FFT_CUTOFF) {
            const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) MOD * MOD;
            vector<uint64_t> result(n + m - 1, 0);
 
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    result[i + j] += (uint64_t) ((int) left[i]) * ((int) right[j]);
 
                    if (result[i + j] > ULL_BOUND)
                        result[i + j] %= MOD;
                }
 
            for (uint64_t &x : result)
                if (x >= MOD)
                    x %= MOD;
 
            return vector<ll>(result.begin(), result.end());
        }
 
        int N = round_up_power_two(n + m - 1);
        left.resize(N);
        right.resize(N);
 
        bool equal = left == right;
        fft_iterative(N, left);
 
        if (equal)
            right = left;
        else
            fft_iterative(N, right);
 
        ll inv_N = inv(N);
 
        for (int i = 0; i < N; i++) {
            left[i] *= (right[i] * inv_N)%MOD;
            left[i] %= MOD;
        }
 
        reverse(left.begin() + 1, left.end());
        fft_iterative(N, left);
        left.resize(n + m - 1);
        return left;
    }
 
    vector<ll> mod_power(const vector<ll> &v, int exponent) {
        assert(exponent >= 0);
        vector<ll> result = {1};
 
        if (exponent == 0)
            return result;
 
        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = mod_multiply(result, result);
 
            if (exponent >> k & 1)
                result = mod_multiply(result, v);
        }
 
        return result;
    }
 
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    InverseofNumber(mod); 
    InverseofFactorial(mod); 
    factorial(mod);
    //cin>>T;
    // cout<<"Case #"<<t;

    for(int t = 1;t<=T;t++)
    {
        int n,q;
        cin>>n;
        vector<ll> a(n);
        vector<ll> onecount(30);
        read(n,a);
        for(auto x : a){
            int temp = x;
            for(int i = 0;i<30;i++){
                onecount[i] += temp&1LL;
                temp = temp/2;
            }
        }
        vector<ll> r;
        vector<ll> s;
        vector<ll> answer;
        vector<ll> finals(n+2);
        for(int i = 0;i<30;i++){
            r.resize(onecount[i]+1,0);
            s.resize(n - onecount[i]+1,0);
            for(int j=1;j<=onecount[i];j = j+2){
                r[j] = Binomial(onecount[i],j,mod);
            }
            for(int j=0;j <= n-onecount[i];j++){
                s[j] = Binomial(n-onecount[i],j,mod);
            }
            answer = NTT::mod_multiply(r,s);
            for(int j = 0;j<=n;j++){
                answer[j] = (answer[j]%mod + mod)%mod;
                finals[j] = (finals[j] + (answer[j] * 1LL << i)%mod)%mod;
            }
        }
        for(int j = 1;j<=n;j++){
            finals[j] = (finals[j] + finals[j-1])%mod;
        }
        cin>>q;
        for(int i = 0;i<q;i++){
            int x;
            cin>>x;
            printf("%lld\n",finals[x]%mod);
        }

    }

    return 0;
}