#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];
void dfs(int s,int *count){
	vis[s]=true;
	cout<<s<<" ";
	*count =*count+1;
	for(int i=0;i<adj[s].size();i++){
		if(!vis[adj[s][i]] && adj[s][i]!=-1 ){
			dfs(adj[s][i],count);
		}
	}
}
void remove(int nodes,int n){
	for(int i=1;i<=nodes;i++){
		for(int j=0;j<adj[i].size();j++){
			if(i==n || adj[i][j]==n){
				adj[i][j]=-1;
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
	int nodeToRemove;
	cin>>nodeToRemove;
	remove(nodes,nodeToRemove);
	memset(vis,false,sizeof(vis));
	int count=0;
	if(nodeToRemove<2){
		dfs(nodeToRemove+1,&count);
	}
	else{
		dfs(nodeToRemove-1,&count);
	}
	cout<<count<<endl;
}