/**
 *    𝕬𝖚𝖙𝖍𝖔𝖗:  𝕽𝖊𝖉 𝕯𝖗𝖆𝖌𝖔𝖓
**/

#include <bits/stdc++.h>
using namespace std;
#define Fast_IO                      \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);                    \
   cout.tie(NULL);
#define int long long int
#define debug(...) fprintf(stderr, _VA_ARGS_), fflush(stderr)

/* ****  My code start here **** */

int32_t main() {
   Fast_IO

#ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   clock_t danger_close = clock();
   int n, k, x;
   cin >> n >> k >> x;
   int arr[n];
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
   }
   sort(arr, arr + n);
   // for (int i = 0; i < n; i++) {
   //    cout << arr[i] << ' ';
   // }
   // cout << '\n';
   int ans = 1;
   priority_queue<int, vector<int>, greater<int> > pq;
   for (int i = 1; i < n; i++) {
      if (arr[i] - arr[i - 1] > x) {
         int val = (arr[i] - arr[i - 1] - 1) / x;
         // cout << val << '\n';
         pq.push(val);
         ans++;
      }
   }
   // cout << '\n';
   // cout << ans << '\n';
   while (k > 0 && !pq.empty()) {
      int elar = pq.top();
      pq.pop();
      if (k >= elar) {
         k -= elar;
      }
      else 
        break;
   }
   cout << pq.size() + 1 << '\n';
   debug("Total Time: %.3f\n", (double)(clock() - danger_close) / CLOCKS_PER_SEC);
   return 0;
}