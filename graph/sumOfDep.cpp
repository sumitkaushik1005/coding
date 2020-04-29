#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	int count=0;
	for(int i=1;i<=nodes;i++){
		int s=adj[i].size();
		count+=s;
	}
	cout<<count<<endl;
}