#include<bits/stdc++.h>
using namespace std;
int graph[10][10];
bool vis[1001];
int dis[1001];
bool sptSet[1001];
int parent[1001];
int minIndex(int nodes){
	int minV=10001;
	int index=-1;
	for(int i=0;i<nodes;i++){
		if(!sptSet[i] && dis[i]<=minV){
			minV=dis[i];
			index=i;
		}
	}
	return index;
}
void printPath(int i){
	if(parent[i]==-1){
		return ;
	}
	printPath(parent[i]);
	cout<<i<<" ";
}
void printSol(int nodes){
	for(int i=1;i<nodes;i++){
		printPath(i);
		cout<<endl;
	}
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<nodes;i++){
		for(int j=0;j<nodes;j++){
			cin>>graph[i][j];
		}
	}
	for(int i=0;i<nodes;i++){
		vis[i]=false;
		sptSet[i]=false;
		dis[i]=10001;
	}
	parent[0]=-1;
	dis[0]=0;
	for(int i=0;i<nodes-1;i++){
		int u=minIndex(nodes);
		sptSet[u]=true;
		for(int v=0;v<nodes;v++){
			if(graph[u][v] && !sptSet[v] && dis[u]+graph[u][v]<dis[v] && dis[u]!=10001 ){
				parent[v]=u;
				dis[v]=dis[u]+graph[u][v];
			}
		}
	}
	for(int i=0;i<nodes;i++){
		cout<<dis[i]<<" ";
	}
	cout<<endl;
	printSol(nodes);

}/*
0 2 0 2
2 0 2 0
0 2 0 2
2 0 2 0*/