#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
bool vis[10001];
void dfs(int s){
	vis[s]=true;
	for(int i=0;i<adj[s].size();i++){
		int t=adj[s][i];
		if(!vis[t]){
			dfs(t);
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(vis,false,sizeof(vis));
	int count=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
			count++;
		}
	}
	cout<<count<<endl;

}