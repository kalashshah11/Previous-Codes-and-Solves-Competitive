#include<bits/stdc++.h>

using namespace std;
// long long function(int n,int m,vector<string> mat){        
//         vector<vector<long long>> dp(n,vector<long long>(m));
//         long long ans = 0;
//         for(int i = n-1;i >= 0 ;i--){
//             for(int j = 0;j < m;j++){
                
//                 if(mat[i][j] == '1'){
//                     dp[i][j] = -1;
//                 }
//                 else{
//                     dp[i][j] = 0;
//                 }
//                 if(i < n-1 && j > 0 && j < m-1){
//                     // cout<<i<<" "<<"Hello"<<endl;
//                     if(mat[i][j] == '0'){
//                         dp[i][j] = min(min(dp[i+1][j],dp[i+1][j-1]),dp[i+1][j+1]) + 1;
//                     }
//                 }
//                 cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
//                 if(dp[i][j] > 0){
//                     ans += dp[i][j];
//                 }
//             }
//         }
//         for(int i = 0;i < n ;i++){
//             for(int j = 0;j < m;j++){
//                 if(mat[i][j] == '1'){
//                     dp[i][j] = -1;
//                 }
//                 else{
//                     dp[i][j] = 0;
//                 }
//                 if(i > 0 && j > 0 && j < m-1){
//                     if(mat[i][j] == '0'){
//                         dp[i][j] = min(min(dp[i-1][j],dp[i-1][j-1]),dp[i-1][j+1]) + 1;
//                     }
//                 }
//                 if(dp[i][j] > 0){
//                     ans += dp[i][j];
//                 }
//             }
//         }
//         return ans;
// }