#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		vector<vector<long long>> dp(n,vector<long long>(2));
		dp[0][0] = 1;
		dp[0][1] = 1;
		for(int i = 1;i<n;i++){
			dp[i][0] = dp[i-1][0] + dp[i-1][1];
			dp[i][1] = dp[i-1][0];
            // cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
		}
		vector<int> dp1;
		for(auto &x : dp){
			dp1.push_back(x[0] + 1);
		}
		dp1.push_back(dp[n-1][0] + dp[n-1][1] + 1);
		string x;
		if(dp1.back() <= k){
			cout<<-1<<endl;
			continue;
		}
		// for(auto x : dp1){
		// 	cout<<x<<" ";
		// }
        for(int)
	}
	return 0;
}
