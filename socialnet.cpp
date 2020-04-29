#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
bool vis[10001];
int level[1001];
int bfs(int source, int t){
	queue<int> q;
	q.push(source);
	level[source]=0;
	vis[source]=true;
		while(!q.empty()){
			int f=q.front();
			q.pop();
			for(int i=0;i<adj[f].size();i++){
				int v=adj[f][i];
				if(!vis[v]){
					q.push(v);
					vis[v]=true;
					level[v]=level[f]+1;
				}
			}
		}	
	/*for(int i=1;i<=9;i++){
		cout<<level[i]<<" ";
	}*/
	return -1;
}
int main(){
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int q;
	cin>>q;
	while(q--){
		int s,t;
		cin>>s>>t;
		memset(level,0,sizeof(level));
		memset(vis,false,sizeof(vis));
		bfs(s,t);
		int count=0;
		for(int i=0;i<n;i++){
			if(level[i]==t){
				count++;
			}
		}
		cout<<count<<endl;
	}
}