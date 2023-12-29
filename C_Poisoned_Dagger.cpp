#include <bits/stdc++.h>

using namespace std;

struct DSU{
    int tsize;
    ll ans = 0;
    vector<ll> parent;
    vector<ll> rank;
    vector<ll> size;
    vector<ll> valsum;
    void init(int n)
    {
        tsize = n;
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        valsum.resize(n+1);
        for(ll i =1 ;i<=n;i++)
        {
            parent[i] = i;
            valsum[i] = i;
            ans += i;
        }   
    }
    ll getParent(ll a) {
        // ll i = a;
        return parent[a] = (parent[a] == a)?a:getParent(parent[a]); 
    }
    int doUnion(ll newa, ll newb) {
        ll a = getParent(newa);
        ll b = getParent(newb);
        if (a != b) {

            if(rank[a] < rank[b])
            {
                ll temp = a;
                a = b;
                b = temp;
            }
            if(rank[a] == rank[b])
            {
                rank[a] += 1;
            }
            parent[b] = a;
            size[a] += size[b];
            int toSubtract = min(valsum[a],valsum[b]);
            int toPut = max(valsum[a],valsum[b]);
            valsum[b] = 0;
            valsum[a] = max()
            ans -= toSubstract;
            size[b] = 0;
            return 1;
        } 
        else
            return 0;  
    }
    ll getAns()
    {
        return ans;
    }
};
int main()
{
    int c_nodes;
    cin>>c_nodes;
    int c_edges;
    cin>>c_edges;
    DSU mdsu;
    mdsu.init(c_nodes);
    for(int i = 0;i<c_edges;i++){
        int a,b;
        cin>>a>>b;
        mdsu.doUnion(a,b);
        cout<<mdsu.getAns()<<endl;
    }
    return 0;
}
