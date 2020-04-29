#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10];
bool vis[10];
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(vis,false,sizeof(vis));
	int max_children=adj[1].size();
	int happyVer=0;
	for(int i=2;i<=nodes;i++){
		if(adj[i].size() > max_children){
			happyVer++;
			max_children=adj[i].size();
		}
	}
	cout<<happyVer<<endl;
}