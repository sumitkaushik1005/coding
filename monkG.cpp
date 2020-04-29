#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
bool vis[10001];
int dfs(int s){
	stack<int> st;
	st.push(s);
	int count=0;
	while(!st.empty()){
		int u=st.top();
		st.pop();
		if(!vis[u]){
			vis[u]=true;
			
		}
		for(int j=0;j<adj[u].size();j++){
			count++;
			if(!vis[adj[u][j]]){
				st.push(adj[u][j]);
			}
		}
	}
	return count;
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans=INT_MIN;
	for(int i=1;i<=nodes;i++){
		if(!vis[i]){
			int k=dfs(i);
			
			//cout<<k<<endl;
			ans=max(ans,k/2);
		}
	}
	cout<<ans<<endl;
}