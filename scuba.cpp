#include<bits/stdc++.h>
using namespace std;
struct Cylinder{
	int ox;
	int nt;
	int wt;
};
int main(){
	int t;
	cin>>t;
	while(t--){
		int O,N;
		cin>>O>>N;
		int n;
		cin>>n;
		Cylinder c[n+1];
		for(int i=0;i<n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			c[i+1].ox=x;
			c[i+1].nt=y;
			c[i+1].wt=z;
		}
		/*for(int i=1;i<=n;i++){
			cout<<c[i].ox<<endl;
			cout<<c[i].nt<<endl;
			cout<<c[i].wt<<endl;
		}*/
		int dp[n+1][n+1];
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				dp[i][j]=0;
			}
		}
		bool used[n+1][n+1];
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				used[i][j]=false;
			}
		}
		
		for(int i=1;i<=n;i++){
			dp[i][i]=c[i].wt;
			if(c[i].ox >= O && c[i].nt >= N){
				used[i][i]=true;
			}
		}
		for(int k=2;k<=n;k++){
			for(int i=1;i<=n-k+1;i++){
				int j=i+k-1;
				int x=INT_MAX;
				int y=INT_MAX;
				int z=INT_MAX;
				if(used[i][j-1]){
					x=dp[i][j-1];
				}
				if(used[i+1][j]){
					y=dp[i+1][j];
				}
				if( (c[i].ox + c[j].ox >=O) && (c[i].nt + c[j].nt >=N)){
					z=c[i].wt+c[j].wt;
					
				}
				used[i][j]=true;
				/*if(k==5){
					for(int i=0;i<=n;i++){
						for(int j=0;j<=n;j++){
							cout<<used[i][j]<<" ";
						}
						cout<<endl;
					}
					cout<<x<<endl;
					cout<<y<<endl;
					cout<<z<<endl;
				}*/
				int ans=min(x,min(y,z));
				dp[i][j]=ans;
			}
		}
/*		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
*/
		cout<<dp[1][n]<<endl;
	}
}