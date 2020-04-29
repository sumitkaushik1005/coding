#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10];
bool vis[10];
int c;
bool dfs(int s){
	cout<<s<<" ";
	c++;
	vis[s]=true;
	for(int i=0;i<adj[s].size();i++){
		if(vis[adj[s][i]]==false){
			dfs(adj[s][i]);
		}
		else{
			cout<<"cycle exists";
			return true;
		}
	}
	return false;
}
int main(){
	int nodes,edges,k;
	cin>>nodes>>edges>>k;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(vis,false,sizeof(vis));
	int connectedComp=0;
	c=0;
	int sub_ways=0;
	int total_ways=(nodes*(nodes-1))/2;
	for(int i=1;i<=nodes;i++){
		if(vis[i]==false){
			if(dfs(i)){
				return -1;
			}		//	sub_ways+=(c*(c-1))/2;
		//	c=0;
		//	connectedComp++;
		}
	}
	/*if(connectedComp>k){
			cout<<"-1"<<endl;		
	}
	else{
		cout<<(edges-nodes+connectedComp)<<endl;
	}*/
	//cout<<(total_ways-sub_ways)<<endl;

	//cout<<connectedComp<<endl;
}