#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10];
bool vis[10];
bool isPresent(int s,int location[],int n){
	for(int i=0;i<n;i++){
		if(s== location[i]){
			return true;
		}
	}
	return false;
}
int  bfs(int s,int location[],int n){
	queue<int> q;
	q.push(s);
	int level[10];
	memset(level,0,sizeof(level));
	vis[s]=true;
	int id=INT_MAX;
	while(!q.empty()){
		int temp=q.front();
		q.pop();
		cout<<temp<<" ";
		for(int i=0;i<adj[temp].size();i++){
			if(vis[adj[temp][i]]==false){
				q.push(adj[temp][i]);
				if(isPresent(adj[temp][i],location,n) && adj[temp][i] < id){
					id=adj[temp][i];
				}
				vis[adj[temp][i]]=true;
				level[adj[temp][i]]=level[temp]+1;
			}
		}

	}
	
	return id;
}
int main(){
	int nodes,edges;
	cin>>nodes;
	edges=nodes-1;
	for(int i=1;i<=edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int q;
	cin>>q;
	int location[q];
	for(int i=0;i<q;i++){
		cin>>location[i];
	}
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=nodes;i++){
		if(vis[i]==false){
			int ans=bfs(i,location,q);
			cout<<ans<<endl;
		}
	}


}