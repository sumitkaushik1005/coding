#include<bits/stdc++.h>
using namespace std;
int fn(int nums[],int n,int target){
	  int dp[target+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<n;j++){
                if(nums[j] <= i){
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        for(int i=0;i<=target;i++){
        	cout<<dp[i]<<" ";
        }
        return dp[target];
}
int main(){
	int n;
	cin>>n;
	int nums[n];
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	int target;
	cin>>target;
	int ans=fn(nums,n,target);
	cout<<ans<<endl;
}