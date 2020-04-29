#include<bits/stdc++.h>
using namespace std;

void dfs(int s,vector<int> adj[],int n,bool vis[]){
	stack<int> st;
	st.push(s);
	vis[s]=true;
	while(!st.empty()){
		int u=st.top();
		st.pop();
		cout<<u<<" ";
		/*if(!vis[u]){
			cout<<u<<" ";
			vis[u]=true;
		}*/
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			if(!vis[v]){
				vis[v]=true;
				st.push(v);
			}
		}
	}
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	vector<int> adj[1001];
	bool vis[nodes];
	memset(vis,false,sizeof(vis));
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(0,adj,nodes,vis);

}