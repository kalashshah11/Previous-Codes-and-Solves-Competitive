#include<bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
ll inf = 1000000000000000000LL;
ll mod = 1000000007;
vector<vector<int>> adj;
vector<ll> val;
map<pair<int,int>,ll> mp;
vector<pair<ll,ll>> c1;
vector<pair<ll,ll>> c2;

ll power(ll x,ll y,ll p){
	ll res = 1;
	x = x%p;
	while(y > 0){
		if(y&1)
			res = (res*x)%p;

		y = y>>1;
		x = (x*x)%p;
	}
	return res;
}

void DFS(int x,int par){
	int flag = 0;
	for(auto it : adj[x]){
		if(it != par){
			DFS(it,x);
			flag = 1;
		}
	}
	if(flag == 0){
		// cout<<x<<" "<<"Hello"<<endl;
		c1[x] = {val[x],1};
		c2[x] = {inf,0};
		return;
	}
	ll smincostall = 0;
	ll sminways = 1;
	ll jmincostall = inf;
	ll jminways = 0;
	for(auto it : adj[x]){
		if(it != par){
			if(c1[it].first > c2[it].first){
				// cout<<"A "<<x;
				smincostall += c2[it].first;
				sminways *= (c2[it].second)%mod;
				sminways = (sminways%mod + mod)%mod;
			}
			else if(c1[it].first < c2[it].first){
				// cout<<"B "<<x;
				smincostall += c1[it].first;
				sminways *= (c1[it].second)%mod;
				sminways = (sminways%mod + mod)%mod;
			}
			else{
				// cout<<"C "<<x;
				smincostall += c1[it].first;
				sminways *= (c1[it].second + c2[it].second)%mod;
				sminways = (sminways%mod + mod)%mod;
			}
		}
	}
	// cout<<" "<<smincostall<<endl;

	for(auto it : adj[x]){
		if(it != par){
			auto temp = mp[{x,it}];
			if(c1[it].first > c2[it].first){
				// cout<<"D "<<x<<endl;
				if(jmincostall > smincostall - c2[it].first + c1[it].first - val[it] + temp){
					jmincostall = smincostall - c2[it].first + c1[it].first - val[it] + temp;
					jminways = (sminways * power(c2[it].second,mod-2,mod))%mod;
					jminways = (jminways%mod + mod)%mod;
					jminways *= c1[it].second;
					jminways = (jminways%mod + mod)%mod;
				}
				else if(jmincostall == smincostall - c2[it].first + c1[it].first - val[it] + temp){
					auto temp1 = (sminways * power(c2[it].second,mod-2,mod))%mod;
					temp1 = (temp1%mod + mod)%mod;
					temp1 *= c1[it].second;
					temp1 = (temp1%mod + mod)%mod;
					jminways = ((jminways  + temp1)%mod + mod)%mod;
				}
			}
			else if(c1[it].first < c2[it].first){
				// cout<<"E "<<x<<endl;
				if(jmincostall > smincostall - val[it] + temp){
					jmincostall = smincostall - val[it] + temp;
					jminways = (sminways * power(c1[it].second,mod-2,mod))%mod;
					jminways = (jminways%mod + mod)%mod;
					jminways *= c1[it].second;
					jminways = (jminways%mod + mod)%mod;
				}
				else if(jmincostall == smincostall - val[it] + temp){
					auto temp1 = (sminways * power(c1[it].second,mod-2,mod))%mod;
					temp1 = (temp1%mod + mod)%mod;
					temp1 *= c1[it].second;
					temp1 = (temp1%mod + mod)%mod;
					jminways = ((jminways  + temp1)%mod + mod)%mod;
				}
			}
			else{
				if(jmincostall > smincostall - val[it] + temp){
					// cout<<"F "<<x<<endl;
					jmincostall = smincostall - val[it] + temp;
					jminways = (sminways * power(c1[it].second + c2[it].second,mod-2,mod))%mod;
					jminways = (jminways%mod + mod)%mod;
					jminways *= c1[it].second;
					jminways = (jminways%mod + mod)%mod;
				}
				else if(jmincostall == smincostall - val[it] + temp){
					auto temp1=(sminways * power(c1[it].second + c2[it].second,mod-2,mod))%mod;
					temp1 = (temp1%mod + mod)%mod;
					temp1 *= c1[it].second;
					temp1 = (temp1%mod + mod)%mod;
					jminways = ((jminways  + temp1)%mod + mod)%mod;
				}
			}
		}
	}

	c1[x] = {smincostall + val[x],(sminways%mod + mod)%mod};
	c2[x] = {jmincostall,(jminways%mod + mod)%mod};
	return;
}

int32_t main(){
	int n;
	cin>>n;
	adj.clear();
	val.clear();
	c1.clear();
	c2.clear();
	mp.clear();
	adj.resize(n);
	val.resize(n);
	c1.resize(n,{inf,1});
	c2.resize(n,{inf,1});
	for(auto& it : val){
		cin>>it;
	}
	for(int i =0 ;i<n-1;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		mp[{a,b}] = c;
		mp[{b,a}] = c;
	}
	DFS(0,-1);
	// for(int i = 0;i<n;i++){
	// 	cout<<c1[i].first<<" "<<c1[i].second<<" "<<c2[i].first<<" "<<c2[i].second<<endl;
	// }
	if(c1[0].first < c2[0].first){
		cout<<c1[0].first<<" "<<(c1[0].second%mod + mod)%mod<<endl;
	}
	else if(c1[0].first > c2[0].first){
		cout<<c2[0].first<<" "<<(c2[0].second%mod + mod)%mod<<endl;
	}
	else{
		cout<<c1[0].first<<" "<<((c1[0].second + c2[0].second)%mod + mod)%mod<<endl;
	}
}