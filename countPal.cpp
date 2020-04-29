#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.length();
	int dp[n][n];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		dp[i][i]=1;
	}
	for(int i=0;i<n-1;i++){
		if(s[i]==s[i+1]){
			dp[i][i+1]=1;
		}
	}
	for(int gap=2;gap<n;gap++){
		for(int i=0;i<n-gap;i++){
			int j=i+gap;
			if(s[i]==s[j] && dp[i+1][j-1]==1){
				dp[i][j]=1;
			}
		}
	}
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dp[i][j]==1){
				count++;
			}
		}
	}
	cout<<count<<endl;
}