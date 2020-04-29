#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool recStack[1001];
bool vis[1001];
bool detectCycleUsingRecStack(int u){
	if(vis[u]==false){
		vis[u]=true;
	recStack[u]=true;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(!vis[v] && detectCycleUsingRecStack(v)){
			return true;
		}
		else if(recStack[v]){
			return true;
		}
	}
	}
	recStack[u]=false;
	return false; 
	

}
bool detectCycleBFS(queue<int> q,int nodes,int in_deg[]){
	int cnt=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			in_deg[v]--;
			if(in_deg[v]==0){
				q.push(v);
			}
		}
		cnt++;
	}
	if(cnt!=nodes){
		return true;
	}
	else
		return false;
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	memset(recStack,false,sizeof(recStack));
	memset(vis,false,sizeof(vis));
	/*if(detectCycleUsingRecStack(1)){
		cout<<"yeah";
	}
	else
		cout<<"nah!";*/
	int in_deg[1001];
	memset(in_deg,0,sizeof(in_deg));
	for(int i=1;i<=nodes;i++){
		int u=i;
		for(int j=0;j<adj[u].size();j++){
			int v=adj[u][j];
			in_deg[v]++;
		}
	}
	queue<int> q;
	for(int i=1;i<=nodes;i++){
		if(in_deg[i]==0){
			q.push(i);
		}
	}

	if(detectCycleBFS(q,nodes,in_deg)){
		cout<<"yeah";
	}
	else
		cout<<"nah!";
}