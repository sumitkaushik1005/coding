#include<bits/stdc++.h>
using namespace std;
int main(){
    const unsigned int M = 1000000007; 
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int dp[m+1];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i]<=j){
				dp[j]+=dp[j-arr[i]];
				dp[j]=dp[j] % M;
			}
		}
	}
	cout<<dp[m]<<endl;
	/*for(int i=0;i<=m;i++){
		cout<<dp[i]<<" ";
	}*/
}