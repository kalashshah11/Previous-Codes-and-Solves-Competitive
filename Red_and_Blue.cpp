#include <bits/stdc++.h>
using namespace std;
#define Fast_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long int

/* ****  My code starts here **** */
struct compare {
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) { 
		return a.first > b.first;
	}
};

int32_t main() {
    Fast_IO
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> arr(n,0);
        int ptr = -1;  // right most blue
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (s[i] == 'B') {
                ptr = i;
            }
        }
		priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        if (ptr == -1) {
            cout << 0 << '\n';
            continue;
        }
		map<int,int> mp;
		int flag = 0;
        for (int i = 0; i < n; i++) {
			
            if (s[i] == 'R' && arr[i] > 0) {
                pq.push(make_pair(i,arr[i] + i));
            }
			else if(s[i] == 'B'){
				// cout<<i<<" "<<pq.top().first<<" "<<pq.top().second<<endl;
				while(!pq.empty() && pq.top().second < i){
					pq.pop();
				}
				if(pq.empty())
				{
					flag = 1;
					break;
				}
				else{
					mp[i] = pq.top().first;
				}
			}
        }
		if(flag)
		{
			cout<<-1<<endl;
			continue;
		}
		int ans = 0;
        for (int i = ptr; i >= 0; ) {
           if(s[i] == 'B'){
				i = mp[i] - 1;
				ans++;
		   }
		   else{
				i--;
		   }
        }
		cout<<ans<<endl;
    }
    // debug("Total Time: %.3f\n", (double)(clock() - danger_close) / CLOCKS_PER_SEC);
    return 0;
}