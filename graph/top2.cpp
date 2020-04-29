#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];
int in_deg[1001];
vector<int> ans;
void topSort(queue<int> q){
	while(!q.empty()){
		int u=q.front();
		q.pop();
		cout<<u<<" ";
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			in_deg[v]--;
			if(in_deg[v]==0){
				q.push(v);
			}
		}
	}
}
void topSortALL(int nodes){
	bool flag=false;
	for(int i=1;i<=nodes;i++){
		if(!vis[i] && in_deg[i]==0){
			vis[i]=true;
			for(int j=0;j<adj[i].size();j++){
				in_deg[adj[i][j]]--;
			}
			ans.push_back(i);
			topSortALL(nodes);
			vis[i]=false;
			for(int j=0;j<adj[i].size();j++){
				in_deg[adj[i][j]]++;
			}
			ans.erase(ans.end()-1);
			flag=true;
		}
	}
	if(!flag){
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<" "; 
		}
		cout<<endl;
	}
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	memset(in_deg,0,sizeof(in_deg));
	memset(vis,false,sizeof(vis));
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		in_deg[y]++;
	}
	/*queue<int> q;
	for(int i=1;i<=nodes;i++){
		if(in_deg[i]==0){
			q.push(i);
		}
	}*/
	topSortALL(nodes);

}