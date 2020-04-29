#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
int low[1001];
int disc[1001];
int parent[1001];
bool apt[1001];
bool vis[1001];
void ap(int u){
	static int time=0;
	low[u]=disc[u]=++time;
	vis[u]=true;
	int child=0;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(!vis[v]){
			child++;
			parent[v]=u;
			ap(v);
			low[u]=min(low[u],low[v]);
			/*if(parent[u]==-1 && child>1){
				apt[u]=true;
			}
			if(parent[u]!=-1 && low[v]>=disc[u]){
				apt[u]=true;
			}*/
			if(low[v] > disc[u] ){
				cout<<u<<" "<<v<<endl;
			}
		}
		else if(parent[u]!=v){
			low[u]=min(low[u],disc[v]);
		}
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
	memset(low,-1,sizeof(low));
	memset(disc,0,sizeof(disc));
	memset(parent,-1,sizeof(parent));
	memset(apt,false,sizeof(apt));
	ap(0);
	for(int i=0;i<nodes;i++){
		if(apt[i])
			cout<<i<<" ";
	}

}