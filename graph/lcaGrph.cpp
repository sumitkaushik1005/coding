#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
int root_node=1;
int parent[10001];
void getParent(int node,int par){
	for(int i=0;i<adj[node].size();i++){
		int v=adj[node][i];
		if(v!=par){
			parent[v]=node;
			getParent(v,node);
		}
	}
}
int lca(int u,int v){
	int ans;
	bool vis[100];
	memset(vis,false,sizeof(vis));
	while(1){
		vis[u]=true;
		if(u==root_node){
			break;
		}
		u=parent[u];
	}
	while(1){
		if(vis[v]){
			ans=v;
			break;
		}
		v=parent[v];
	}
	return ans;
}
int main(){
	int nodes,edges;
	cin>>nodes;
	edges=nodes-1;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	getParent(root_node,-1);
	int q;
	cin>>q;
	while(q--){
		int r,u,v;
	cin>>r>>u>>v;
	int l[3];
	l[0]=lca(r,u);
	l[1]=lca(r,v);
	l[2]=lca(u,v);
	int s=l[0] ^ l[1] ^ l[2];
	cout<<s<<endl;

	}
	


}