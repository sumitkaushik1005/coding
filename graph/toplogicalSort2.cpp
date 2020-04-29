#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];
vector<int> ans;
priority_queue<int, vector<int>, std::greater<int> > q;
int in_deg[1001];
void topSort(){
	
	while(!q.empty()){
		int u=q.top();
		vis[u]=true;
		q.pop();
		ans.push_back(u);
		vector<int>::iterator it;
		for( it=adj[u].begin();it!=adj[u].end();it++){
				in_deg[*it]--;
				if(in_deg[*it]==0){
					q.push(*it);
				}
		}
	}
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
	memset(in_deg,0,sizeof(in_deg));
	for(int i=1;i<=nodes;i++){
		vector<int>::iterator it;
		for(it=adj[i].begin();it!=adj[i].end();it++){
			in_deg[*it]++;
		}
	}/*
	for(int i=1;i<=nodes;i++){
		sort(adj[i].rend(),adj[i].rbegin());
	}*/
	for(int i=1;i<=nodes;i++){
		if(in_deg[i]==0){
			q.push(i);
		}
	}
	for(int i=1;i<=nodes;i++){
		if(vis[i]==false){
			topSort();
		}
	}
	for(int i=0;i<nodes;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}