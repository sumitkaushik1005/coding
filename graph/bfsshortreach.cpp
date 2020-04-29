#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool vis[100];
void bfs(int source,int distance[],int nodes){
	queue<int> q;
	q.push(source);
	distance[source-1]=0;
	vis[source]=true;
	while(!q.empty()){
		int s=q.front();
		q.pop();
		for(int i=0;i<adj[s].size();i++){
			if(vis[adj[s][i]]==false){
				distance[adj[s][i]-1]=distance[s-1]+1;
				vis[adj[s][i]]=true;
				q.push(adj[s][i]);
			}
		}
	}
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int source;
	cin>>source;
	int distance[nodes];
	memset(distance,-1,sizeof(distance));
	bfs(source,distance,nodes);
	for(int i=0;i<nodes;i++){
		cout<<distance[i]<<" ";
	}
}