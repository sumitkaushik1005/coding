#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.length();
	int dp[n];
	memset(dp,0,sizeof(dp));
	for(int i=n-1;i>=0;i--){
		int d=(int)(s[i]-'0');
		if(i==n-1){
			if(d%2==0){
				dp[i]=1;
			}
			else{
				dp[i]=0;
			}
		}
		else{
			if(d%2==0){
				dp[i]=dp[i+1]+1;
			}
			else{
				dp[i]=dp[i+1];
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
}