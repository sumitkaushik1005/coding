#include<bits/stdc++.h>
using namespace std;
int countNo;
int low[10000];
int disc[10000];
int parent[10000];
vector<int> adj[10000];
bool vis[10000];
void bridge(int s){
	static int time=0;
	low[s]=disc[s]=++time;
	vis[s]=true;
	int subtree=0;
	for(int i=0;i<adj[s].size();i++){
		int v=adj[s][i];
		if(vis[v]==false){
			subtree++;
			parent[v]=s;
			bridge(v);
			low[s]=min(low[v],low[s]);
			if(low[v]>disc[s]){
				countNo++;
			}
		}
		else if(v!=parent[s]){
			low[s]=min(low[s],disc[v]);
		}

	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		countNo=0;
		memset(low,INT_MAX/2-2,sizeof(low));
		memset(disc,INT_MAX/2-2,sizeof(disc));
		memset(parent,-1,sizeof(parent));
		memset(vis,false,sizeof(vis));
		for(int i=0;i<nodes;i++){
			if(vis[i]==false){
				bridge(i);
			}
		}
		cout<<countNo<<endl;
	}
	}
	
}