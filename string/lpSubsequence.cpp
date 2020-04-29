#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.length();
	int dp[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		dp[i][i]=1;
	}
	int len;
	for(len=2;len<=n;len++){
		for(int i=0;i<n-len+1;i++){
			int j=i+len-1;
			if(len==2 && s[i]==s[j]){
				dp[i][j]=2;
			}
			else if(s[i]==s[j]){
				dp[i][j]=dp[i+1][j-1]+2;
			}
			else
				dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
		}
	}
	cout<<dp[0][n-1]<<endl;
}