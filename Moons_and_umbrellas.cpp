#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
int solve(int a,int b,int count){
	if(a < 3 && b < 3){
		return count%2;
	}
	if(a > 3 && b > 3)
		return solve(a%3,b + a/3,count+1) || solve(a + b/3,b%3,count+1);
	else if(a > 3){
		return solve(a%3,b + a/3,count+1);
	}
	else{
		return solve(a + b/3,b%3,count+1);
	}
}
int main() {
	int t;
	cin>>t;
	while(t--){
		int a,b;
		int newa,newb;
		cin>>a>>b;
		int x = solve(a,b,0);
		cout<<x<<endl;

	}
	// Your code here
	return 0;
}