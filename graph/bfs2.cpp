#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];
int parent[1001];
void bfs(int u){
	queue<int> q;
	q.push(u);
	parent[u]=-1;
	vis[u]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			if(!vis[v]){
				q.push(v);
				vis[v]=true;
				parent[v]=u;
			}
			else if(parent[u]!=v){
				cout<<"cycle exist"<<endl;
				return;
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
	bfs(1);
	
	cout<<endl;
}