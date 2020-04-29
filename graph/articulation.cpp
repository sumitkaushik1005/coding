#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];
int low[1001];
int disc[1001];
bool ap[1001];
int parent[1001];
void dfs(int u){
	static int time=0;
	vis[u]=true;
	int sub_tree=0;
	disc[u]=low[u]=++time;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(vis[v]==false){
			sub_tree++;
			parent[v]=u;
			dfs(v);
			low[u]=min(low[u],low[v]);
			if(parent[u]!=-1 && low[v]>=disc[u]){
				ap[u]=true;
			}
			if(parent[u]==-1 && sub_tree>1){
				ap[u]=true;
			}

		}
		else if(v!=parent[u]){
			low[u]=min(low[u],disc[v]);
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
	memset(ap,false,sizeof(ap));
	memset(disc,10001,sizeof(disc));
	memset(low,10001,sizeof(low));
	memset(parent,-1,sizeof(parent));
	dfs(1);
	for(int i=1;i<=nodes;i++){
		if(ap[i]){
			cout<<i<<" ";
		}
	}

}