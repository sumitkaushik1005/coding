#include<bits/stdc++.h>
using namespace std;
int dp[5][2][3];
int fn(int n,int bC,int cC){
	if(bC<0 || cC<0){
		return 0;
	}
	if(n==0)
		return 1;
	if(bC==0 && cC==0){
		return 1;
	}
	if(dp[n][bC][cC]!=-1){
		return dp[n][bC][cC];
	}
	dp[n][bC][cC]=fn(n-1,bC,cC)+fn(n-1,bC-1,cC)+fn(n-1,bC,cC-1);
	return dp[n][bC][cC];
	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	int ans=fn(n,1,2);
	cout<<ans<<endl;
	}
	
}