#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];
int visitedNodes;
void dfs(int s){
	vis[s]=true;
	visitedNodes++;
	for(int i=0;i<adj[s].size();i++){
		int v=adj[s][i];

		if(vis[v]==false){
			dfs(v);
		}
	}
}
int main(){
	int nodes,edges,clib,croad;
	cin>>nodes>>edges>>clib>>croad;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	visitedNodes=0;
	memset(vis,false,sizeof(vis));
	int ans=0;
	for(int i=1;i<=nodes;i++){
		if(vis[i]==false){
			dfs(i);
			ans=ans+min(clib+(visitedNodes-1)*croad,clib*visitedNodes);
		}	visitedNodes=0;
	}
	cout<<ans<<endl;
}