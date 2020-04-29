#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool vis[100];
bool detectCycle(int s,int parent){
	vis[s]=true;
	for(int i=0;i<adj[s].size();i++){
		if(vis[adj[s][i]]==false && detectCycle(adj[s][i],s)){
				return true;
		}else if(parent!=s){
			return true;
		}
	}
	return false;
}
int main(){
	int nodes, edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		//adj[y].push_back(x);
	}
	memset(vis,false,sizeof(vis));
	if(detectCycle(1,-1)){
		cout<<"Cycle"<<endl;
	}
	else{
		cout<<"Not cycle"<<endl;
	}
}