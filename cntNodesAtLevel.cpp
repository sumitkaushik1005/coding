#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool vis[100];
int level[100];
void bfs(int s){
	queue<int> q;
	q.push(s);
	vis[s]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		cout<<u<<" ";
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			
			if(!vis[v]){
				level[v]=level[u]+1;
				q.push(v);
				vis[v]=true;
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
	memset(vis,false,sizeof(vis));
	memset(level,0,sizeof(level));
	bfs(1);
	cout<<endl;
	for(int i=1;i<=nodes;i++){
		cout<<level[i]<<" ";
	}
}