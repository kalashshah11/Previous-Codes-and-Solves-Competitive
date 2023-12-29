#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 1;
    cin>>t;
    while(t--)
    {
        long long n,m;
		cin>>n>>m;
		long long ans =0;
		while(n > 0 && m > 0){
			ans += n;
			m--;
			ans += m;
			n--;
		}
		cout<<ans<<endl;
    }

    return 0;
}
