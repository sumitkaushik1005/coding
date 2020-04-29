#include<bits/stdc++.h>
using namespace std;
const int ll=1e6+1;
vector<int> adj[ll];
bool vis[ll];
int countNo;
const int mod=1e9+7;
void dfs(int s,int d){
	vis[s]=true;
	if(s==d ){
		countNo++;
	}
	for(int i=0;i<adj[s].size();i++){
		if(vis[adj[s][i]]==false){
			dfs(adj[s][i],d);
		}
	}
	vis[s]=false;
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	int a,b;
	cin>>a>>b;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		//adj[y].push_back(x);
	}
	memset(vis,false,sizeof(vis));

		int index=0;
		countNo=0;
		dfs(a,b);
		cout<<countNo%mod<<endl;
	
}