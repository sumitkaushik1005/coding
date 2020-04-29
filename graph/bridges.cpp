#include<bits/stdc++.h>
using namespace std;
const int len=1e5+5;
vector<pair<int,int>> adj[len];
set<int> brid;
bool vis[len];
int parent[len];
int low[len];
int disc[len];
bool ap[len];
void bridge(int u){
	static int time=0;
	vis[u]=true;
	low[u]=disc[u]=time;
	time++;
	int subtree=0;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i].first;
		int ind=adj[u][i].second;
		if(vis[v]==false){
			subtree++;
			parent[v]=u;
			bridge(v);
			low[u]=min(low[u],low[v]);
			if(parent[u]!=-1 && low[v]>=disc[u]){
				ap[u]=true;
			}
			if(parent[u]==-1 && subtree>1){
				ap[u]=true;
			}
			if(low[v]>disc[u]){
				brid.insert(ind);
				
			}
		}
		else if(v!=parent[u]){
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
		adj[x].push_back(make_pair(y,i));
		adj[y].push_back(make_pair(x,i));
	}
	memset(vis,false,sizeof(vis));
	memset(parent,-1,sizeof(parent));
	memset(low,10001,sizeof(low));
	memset(disc,10001,sizeof(disc));
	
	for(int i=1;i<=nodes;i++){
		if(vis[i]==false){
			bridge(i);		
		}
	}
	
	
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		if(brid.find(x-1)!=brid.end()){
			cout<<"Unhappy"<<endl;
		}
		else{
			cout<<"Happy"<<endl;
		}
	}

}