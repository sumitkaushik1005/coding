#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];
bool detectCycle(int s,int parent){
	vis[s]=true;
	for(int i=0;i<adj[s].size();i++){
		int v=adj[s][i];
		if(!vis[v]){
			if(detectCycle(v,s))
				return true;
		}
		else if(parent!=v){
			return true;
		}
	}
	return false;
}
bool detectCycleBfs(int s,int parent[]){
	queue<int> q;
	q.push(s);
	vis[s]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			if(!vis[v]){
				q.push(v);
				parent[v]=u;
				vis[v]=true;
			}
			else if(parent[u]!=v){
				return true;
			}
		}
	}
	return false;
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}/*
	if(detectCycle(1,-1)){
		cout<<"Yeah";
	}
	else
	cout<<"nah";*/
		int parent[1001];
		memset(parent,0,sizeof(parent));
		if(detectCycleBfs(1,parent)){
			cout<<"yeah";
		}
		else
			cout<<"No";

}