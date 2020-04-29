#include<bits/stdc++.h>
using namespace std;

int fn(vector<vector<int>> mat,vector<vector<int>> &dp,int i,int j,int r,int c){
	
	if(dp[i][j]>0){
		return dp[i][j];
	}
	int left=1,right=1,up=1,down=1;
	if(j>0 && mat[i][j-1]>mat[i][j]){
		left=1+fn(mat,dp,i,j-1,r,c);
	}
	if(j<c && mat[i][j]<mat[i][j+1]){
		right=1+fn(mat,dp,i,j+1,r,c);
	}
	if(i<r && mat[i][j]<mat[i+1][j]){
		down=1+fn(mat,dp,i+1,j,r,c);
	}
	if(i>0 && mat[i][j]<mat[i-1][j]){
		up=1+fn(mat,dp,i-1,j,r,c);
	}
	dp[i][j]=max(max(left,right),max(up,down));
	return dp[i][j];

}
int main(){
	int r,c;
	cin>>r>>c;
	vector<vector<int>> mat;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>mat[i][j];
		}
	}
	vector<vector<int>> dp;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			dp[i][j]=0;
		}
	}
	int ans=INT_MIN;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			int temp_ans=fn(mat,dp,i,j,r,c);
			ans=max(ans,temp_ans);
		}
	}
	cout<<ans<<endl;
}