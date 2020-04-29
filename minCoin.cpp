#include<bits/stdc++.h>
using namespace std;

int minCoins(int coin[], int n, int sum) 
{ 
	int dp[sum+1];
		dp[0]=0;
		for(int i=1;i<=sum;i++){
			dp[i]=INT_MAX;
		}
		
		for(int i=1;i<=sum;i++){
			for(int j=0;j<n;j++){
				if(coin[j] <= i){
					int sub_res=dp[i-coin[j]];
					if(sub_res!=INT_MAX && 1+sub_res < dp[i])
						dp[i]=1+sub_res;
				}
			}
		}
		return dp[sum];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int dis[n];
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			dis[i]=a;
		}
		int petrol[n];
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			petrol[i]=a;
		}
		
		int ans=0;
		for(int i=0;i<n;i++){
			int sum=dis[i]*2;
			//cout<<"sum"<<sum<<endl;
			 ans+=minCoins(petrol,n,sum);
			 //cout<<"required "<<ans<<endl;
		}
		cout<<ans<<endl;
		
	}
}