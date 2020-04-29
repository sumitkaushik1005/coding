#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];
stack<int> st;
void topSort(int s){
	vis[s]=true;
	for(int i=0;i<adj[s].size();i++){
		int v=adj[s][i];
		if(!vis[v]){
			topSort(v);
		}
	}
	st.push(s);
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
	for(int i=1;i<=nodes;i++){
		if(!vis[i]){
			topSort(i);
		}
	}
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
}