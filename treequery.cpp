#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	int in_deg[nodes+1];
	int out_deg[nodes+1];
	memset(in_deg,0,sizeof(in_deg));
	memset(out_deg,0,sizeof(out_deg));
	for(int i=1;i<=nodes;i++){
		out_deg[i]=adj[i].size();
	}
	int ans1=0;
	for(int i=1;i<=nodes;i++){
		if(out_deg[i]==0){
			ans1++;
		}
	}

	int ans2=0;
	for(int i=1;i<=nodes;i++){
		for(int j=0;j<adj[i].size();j++){
			in_deg[adj[i][j]]++;
		}
	}
	for(int i=1;i<=nodes;i++){
		if(in_deg[i]==0){
			ans2++;
		}
	}
	cout<<max(ans2,ans1)<<endl;

}