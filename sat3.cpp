#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int mat[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int x;
				cin>>x;
				mat[i][j]=x;
			}
		}
		int dp[n][m];
		dp[0][0]=mat[0][0];
		for(int i=1;i<m;i++){
			dp[0][i]=dp[0][i-1]+mat[0][i];
		}
		for(int i=1;i<n;i++){
			dp[i][0]=dp[i-1][0]+mat[i][0];
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){
				dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]))+mat[i][j];
			}
		}
		cout<<dp[n-1][m-1]<<endl;
		/*for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}*/
	}
}