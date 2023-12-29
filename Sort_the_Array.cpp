#include <bits/stdc++.h>
  using namespace std;
  #define int long long
   bool isPerfectSquare(int x)
   {
   int sq=sqrt(x);
   return (x==sq*sq);
   }
    signed main() {
// your code goes here

int t,n;
cin>>t;
while(t--)
{
    cin>>n;
    int arr[n];
    vector<pair<int,int>> vect;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        vect.push_back({arr[i],i+1});
    }
    bool flag=1;
    sort(vect.begin(),vect.end());
    for(int i=0;i<n;i++)
    {
        int x=(i+1)*(vect[i].second);
        if(isPerfectSquare(x)==0) 
        {
            flag=0;break;
        }
    }
    if(flag==1)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}
return 0;
}