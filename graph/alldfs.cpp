#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool vis[100];
int i=0;
vector<int> ans;
void dfs(int u){
	vis[u]=true;
	bool flag=true;
	
	for(int i=0;i<adj[u].size();i++){
		//ans.push_back(u);
		int v=adj[u][i];
		if(!vis[v]){
			dfs(v);
			vis[v]=false;
		//ans.erase(ans.end()-1);
		flag=false;
		}
		
	}
	if(!flag){
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
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
	dfs(1);
}