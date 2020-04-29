#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];
int ans[1001];
int ind;
int countP;
void fn(int s,int d){
	ans[ind]=s;
	vis[s]=true;
	ind++;
	if(s==d){
		for(int i=0;i<ind;i++){
			cout<<ans[i]<<" ";
		}
	countP++;	
	}
	else{
		for(int i=0;i<adj[s].size();i++){
		int v=adj[s][i];
		if(vis[v]==false){
			fn(v,d);
		}
	}
	}
	
	vis[s]=false;
	ind--;
}
int main(){
	int edges,nodes;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	int s,d;
	cin>>s>>d;
	memset(vis,false,sizeof(vis));
	
	ind=0;
	countP=0;
	fn(s,d);
	cout<<countP<<endl;
}