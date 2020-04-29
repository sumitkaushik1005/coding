#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,W;
		cin>>n>>W;
		int input[n][3];
		for(int i=0;i<n;i++){
			cin>>input[i][0]>>input[i][1]>>input[i][2];
		}
		int knap[n+1][W+1];
		for(int i=0;i<=n;i++){
			for(int j=0;j<=W;j++){
				if(i==0||j==0)
					knap[i][j]=0;
				else if(input[i-1][2] <= j ){
					knap[i][j]=max(input[i-1][0] * input[i-1][1] + knap[i-1][j-input[i-1][2]] , knap[i-1][j]);
				}
				else
					knap[i][j]=knap[i-1][j];
			}
		}
		cout<<knap[n][W]<<endl;
		/*for(int i=0;i<=n;i++){
			for(int j=0;j<=W;j++){
				cout<<knap[i][j]<<" ";
			}
			cout<<endl;
		}*/
	}
}