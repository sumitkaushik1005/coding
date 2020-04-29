#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool vis[100];
int countN;
void print(int ans[],int len){
	for(int i=0;i<len;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
void fn(int s,int d,int ans[],int index){
	ans[index]=s;
	index++;
	vis[s]=true;
	if(s==d){
		countN++;
		print(ans,index);
	}
	else{
		for(int i=0;i<adj[s].size();i++){
			int v=adj[s][i];
			if(!vis[v]){
				fn(v,d,ans,index);
			}
		}
	}
	vis[s]=false;
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		
	}
	memset(vis,false,sizeof(vis));
	int s,d;
	cin>>s>>d;
	int ans[100];
	int index=0;
	countN=0;
	fn(s,d,ans,index);
	cout<<countN<<endl;
}