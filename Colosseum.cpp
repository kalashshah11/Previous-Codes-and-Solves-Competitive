#include "bits/stdc++.h"
#define ll long long
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 0;
    cin>>t;
    while(t--){
        string s;
        ll x,n;
        ll mod = 998244353;
        cin>>x>>n;
        ll val = 1;
        ll ans = 0;
        for(int i = 0;i<=n;i++){
            ans += val;
            ans = ans%mod;
            val *=x ;
            val = val%mod;
        }
        cout<<(ans%mod + mod)%mod<<endl;
 
    }
}