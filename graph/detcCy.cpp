#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10];
bool vis[10];
bool recS[10];
bool dfs(int s){
	if(vis[s]==false){
		vis[s]=true;
		recS[s]=true;
		for(int i=0;i<adj[s].size();i++){
			if(!vis[adj[s][i]] && dfs(adj[s][i])){
					return true;
			}
			else if(recS[adj[s][i]]){
				return true;
			}
		}
	}
	recS[s]=false;
	return false;
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	memset(vis,false,sizeof(vis));
	memset(recS,false,sizeof(recS));
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	if(dfs(1)){
		cout<<"cycle exists"<<endl;
	}
	else{
		cout<<"Cycle not exists"<<endl;
	}
}