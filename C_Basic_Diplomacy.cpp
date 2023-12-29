#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = a; i != b; i++)
#define ll long long int
#define all(c) c.begin(),c.end()
#define pb push_back

using namespace std;
            
map<int,int> mp;
bool cmp(pair<vector<int>,int>& a,pair<vector<int>,int>& b){
	return a.first.size() < b.first.size();
}
bool comp1(int a,int b){
	return mp[a] < mp[b];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
		cin>>n>>m;
		vector<pair<vector<int>,int>> a(m);
		for(int i = 0;i<m;i++){
			int x;
			cin>>x;
            a[i].first.resize(x);
			for(int j = 0;j<x;j++){
				cin>>a[i].first[j];
			}
            a[i].second = i;
		}
		sort(all(a),cmp);
		vector<int> ans(m);
		for(int i = 0;i<m;i++){
            sort(all(a[i].first),comp1);
            mp[a[i].first[0]]++;
            ans[a[i].second] = a[i].first[0];
		}
		ll f = 1;
		for(auto it : mp){
			if(it.second > (m + 1)/2 ){
				cout<<"NO"<<endl;
				f = 0;
			}
		}


		if(f){
			cout<<"YES"<<endl;
			for(int i = 0;i<m;i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}
        mp.clear();
    }

    return 0;
}
