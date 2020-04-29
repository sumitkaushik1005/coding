#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
			int n,edges;
	cin>>n>>edges;
	int dis[n][n];
	int graph[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				dis[i][j]=0;
				graph[i][j]=0;
			}
			else{
			dis[i][j]=INT_MAX/2-2;
			graph[i][j]=INT_MAX/2-2;
		}
		}
	}
	for(int i=0;i<edges;i++){
		int x,y,wt;
		cin>>x>>y>>wt;
		dis[x][y]=wt;
		dis[y][x]=wt;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			graph[i][j]=dis[i][j];
		}
	}
	
	
	int batman,superman;
	cin>>batman>>superman;
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		int temp=dis[a][b];
		dis[a][b]=INT_MAX/2-2;
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}

	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}*/
	if(dis[batman][superman]== INT_MAX/2-2){
		cout<<"-1"<<endl;
	}else
	cout<<dis[batman][superman]<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dis[i][j]=graph[i][j];
			}
		}
	}

	}

}