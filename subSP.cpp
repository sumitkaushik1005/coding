#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
	cin>>n;
	int a[n];
	int sum=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[i]=x;
		sum+=x;
	}
	//cout<<sum<<endl;
	if(sum%2!=0){
		cout<<"NO"<<endl;
		continue;
	}
	sum=sum/2;
	bool dp[n+1][sum+1];
	for(int i=0;i<=n;i++){
		dp[i][0]=true;
	}
	for(int i=1;i<=sum;i++){
		dp[0][i]=false;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j<a[i-1])
				dp[i][j]=dp[i-1][j];
			else{
				dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
			}
		}
	}
	if(dp[n][sum]){
		cout<<"YES"<<endl;
	}
	else
		cout<<"NO"<<endl;
	}
	

}