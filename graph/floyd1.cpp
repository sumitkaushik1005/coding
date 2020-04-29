#include<bits/stdc++.h>
using namespace std;
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	int graph[nodes+1][nodes+1];
	for(int i=0;i<=nodes;i++){
		for(int j=0;j<=nodes;j++){
			if(i==j){
				graph[i][j]=0;
			}
			else
				graph[i][j]=10001;
		}
	}
	for(int i=0;i<edges;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		graph[u][v]=wt;
	}
	int dis[nodes+1][nodes+1];
	for(int i=0;i<=nodes;i++){
		for(int j=0;j<=nodes;j++){
			dis[i][j]=graph[i][j];
		}
	}
	for(int k=1;k<=nodes;k++){
		for(int i=1;i<=nodes;i++){
			for(int j=1;j<=nodes;j++){
				if(dis[i][j] > dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	int q;
	cin>>q;
	while(q--){
		int x,y;
		cin>>x>>y;
		if(dis[x][y]==10001)
			cout<<-1<<endl;
		else
			cout<<dis[x][y]<<endl;
	}/*
	for(int i=0;i<=nodes;i++){
		for(int j=0;j<=nodes;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}*/

}