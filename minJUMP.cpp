#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		
		if(n==0 || a[0]==0){
			cout<<"-1"<<endl;
			return -1;
		}
		int dp[n];
		for(int i=0;i<n;i++){
			dp[i]=INT_MAX;
		}
		
		dp[0]=0;

		for(int i=0;i<n;i++){
			int j=i+1;
			while(i+a[i]>=j){
				dp[j]=min(dp[i]+1,dp[j]);
				j++;
			}
		}
		cout<<dp[n-1]<<endl;
	}
}