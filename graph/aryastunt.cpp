#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10];
bool vis[10];
void bfs(int i,int soldier[],int n){
	queue<int> q;
	q.push(i);
	vis[i]=true;
	int injured=0;
	int max_kill=INT_MIN;
	int min_id=INT_MAX;
	while(!q.empty()){
		int s=q.front();
		q.pop();
		//cout<<s<<" ";
		injured+=soldier[s-1];
		cout<<"injured ";
		cout<<injured;
		if(max_kill < soldier[s-1]){
			max_kill=soldier[s-1];
			min_id=s;
		}
		if(max_kill == soldier[s-1] && min_id > s){
			min_id=s;
		}
		for(int i=0;i<adj[s].size();i++){
			if(vis[adj[s][i]]==false){
				q.push(adj[s][i]);
				vis[adj[s][i]]=true;
			}
		}
	}
	cout<<injured<<endl;
	cout<<max_kill<<endl;
	cout<<min_id<<endl;
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	int soldier[nodes];
	for(int i=0;i<nodes;i++){
		cin>>soldier[i];
	}
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=nodes;i++){
		if(vis[i]==false){
			bfs(i,soldier,nodes);
		}
	}
}