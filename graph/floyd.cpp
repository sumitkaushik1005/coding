#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,edges,x;
	cin>>n>>edges>>x;
	long long int dis[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dis[i][j]=INT_MAX;
		}	
	}
	int spl[x];
	for(int i=0;i<x;i++){
		cin>>spl[i];
	}
	for(int i=0;i<edges;i++){
		int x,y,wt;
		cin>>x>>y>>wt;
		dis[x][y]=wt;
		dis[y][x]=wt;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
					if(dis[i][j] > (dis[i][k]+dis[k][j])){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
			
			}
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}
	/*long long int sum=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			sum+=dis[i][j];
		}
	}
	cout<<sum<<endl;*/
}