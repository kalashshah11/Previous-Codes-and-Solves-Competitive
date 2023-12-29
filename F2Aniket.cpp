// Problem
//

#include <bits/stdc++.h>
using namespace std;



#if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
#define _MATH_DEFINES_DEFINED

#define M_E        2.71828182845904523536
#define M_LOG2E    1.44269504088896340736
#define M_LOG10E   0.434294481903251827651
#define M_LN2      0.693147180559945309417
#define M_LN10     2.30258509299404568402
#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923
#define M_PI_4     0.785398163397448309616
#define M_1_PI     0.318309886183790671538
#define M_2_PI     0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2    1.41421356237309504880
#define M_SQRT1_2  0.707106781186547524401

#endif  /* _USE_MATH_DEFINES */


#define pb push_back
#define mp make_pair
#define lb lower_bound
#define bs binary_search
#define fs first
#define sn second
#define gri greater<int>
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x
#define all(v) v.begin(),v.end()
#define mxs(m,a) m=max(m,a)
#define mns(m,a) m=min(m,a)
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define frrb(i,a,b) for(int i=a; i>=b;i--)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define ainpl(n,arr) ll n; read(n); ll arr[n]; cinp(n,arr);
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define intt int32_t
#define int long long
// #define endl '\n'

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

// Range Queries, Point Update
// updates/queries: 0 indexed, storage array: 1 indexed

int query(int l, int r)
{
  csp("?"); csp(l); cnl(r);
  int q; cin >> q;
  return r+l-1-q;
}

struct item
{
  int val;
};

struct SegTree
{
  int n;
  int h;
  int size;
  vector<item> tree;
  vector<pi> len;

  // CHANGE NEUTRAL, MERGE, SINGLE only
  const int NEUTRAL = 0;
  item merge(item& a, item& b)
  {
    item ans;
    ans.val = a.val+b.val;
    return ans;
  }

  item single(int v)
  {
    return {v};
  }

  void init(int sz, int arr[])
  {
    n = sz;
    h = ceil((float)log2(n))+1;
    size = 1LL<<(h-1);
    tree.resize(2*size, single(NEUTRAL));
    len.resize(2*size, {0,size});
    fr(i,0,n) update(i, arr[i]);
    fr(x,1,size)
    {
      int l = len[x].fs, r = len[x].sn;
      int m = (l+r)/2;
      len[2*x]={l,m};
      len[2*x+1]={m,r};
    }
  }

  void update(int i, int v)
  {
    int x = size + i;
    tree[x] = single(v);
    while(x>>=1)
      tree[x] = merge(tree[2*x], tree[2*x+1]);
  }

  // i is 0-indexed, tree is 1-indexed
  void update(int i)
  {
    int x = size + i;
    tree[x].val--;
    while(x>>=1)
      tree[x] = merge(tree[2*x], tree[2*x+1]);
  }

  // [l,r), [lx, rx), 0-indexed
  item query(int l, int r, int x=1)
  {
    int lx = len[x].fs, rx = len[x].sn;
    if(lx>=l && rx<=r) return tree[x];
    if(rx<=l || lx>=r) return single(NEUTRAL);
    item left = query(l, r, 2*x);
    item right = query(l, r, 2*x+1);
    return merge(left, right);
  }

  void printTree();
  int find(int k)
  {
    // case for single element array
    // if(size==1) if(k!=tree[1].val) return -1;
    int x = 1;

    while(x<size)
    {
      int leftv = tree[2*x].val;
      if(k<=leftv) x=2*x;
      else x=2*x+1, k=k-leftv;
    }
    return x-size;
  }
};

int lower_bound(int l, int r, int X)
{
  int mid;

  // Initialise starting index and
  // ending index
  int low = l;
  int high = r+1;

  // Till low is less than high
  while (low < high) {
    mid = low + (high - low) / 2;
    if (X <= query(1,mid)) {
      high = mid;
    }
    else {
      low = mid + 1;
    }
  }
  return low;
}

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int n; int t; cin >> n >> t;
  int arr[n]={};

  int k; cin >> k; t--;

  int curr=0;
  for(int l =1; l<=n;l+=8)
    arr[curr++]=query(l,min(l+7,n));

  SegTree st;
  st.init(n,arr);

  int l = st.find(k);
  int r = min((l+1)*8,n);
  int ans = lower_bound(l*8+1,r,k);
  csp("!"); cnl(ans);
  st.update(l);

  while(t--)
  {
    int k;
    cin >> k;
    int l = st.find(k);
    int r = min((l+1)*8,n);
    int ans = lower_bound(l*8+1,r,k);
    csp("!"); cnl(ans);
    st.update(l);
  }
}
