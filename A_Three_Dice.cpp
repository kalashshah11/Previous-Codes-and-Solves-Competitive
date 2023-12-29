#include <bits/stdc++.h>
using namespace std;
 
void DFS_VISIT(vector<int> adj[], vector<int>& color, int u)
{
//   cout<<"*"<<" ";
  color[u]=1;
  for(int itm:adj[u])
  {
    if(color[itm]==0){
        // cout<<u<<" "<<itm<<endl;
      DFS_VISIT(adj, color, itm);
    }
  }
  color[u]=2;
}
 
int main()
{
  int n;
  vector<int> color(n+1,0);
  cin>>n;
 
  int a;
  vector<int> adj[n+1];
  for(int i=1;i<=n;i++)
  {
    cin>>a;
    if(a==-1)
      continue;
    adj[i].push_back(a);
    adj[a].push_back(i);
    // cout<<a<<" ";
  }
 
  int connected_components=0;
  for(int i=1;i<=n;i++)
  {
    if(color[i]==0)
    {
      connected_components++;
      DFS_VISIT(adj, color, i);
    }
  }
  cout<<connected_components;
  return 0;
}