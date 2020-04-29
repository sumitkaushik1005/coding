#include<bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
vector<int> adj[100001];
bool vis[100001];
vector<int> ans;
void print(vector<int> ans){
	for(auto i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
 }
// void fn(vector<int> ans){
// 	for(int i=1;i<ans.size();i++){
// 		int v=ans[i];
// 		int u=ans[i-1];
		
// 	}
// }
void dfs(int s,int d,int cost[]){
	if(s==d){
		ans.push_back(s);
		int prod=1;
		for(auto i=0;i<ans.size();i++){
		//cout<<ans[i]<<" ";
			prod=(prod*cost[ans[i]])%M;
		}
		cout<<prod<<endl;
		
	}
	else{
		vis[s]=true;
		ans.push_back(s);
		for(int i=0;i<adj[s].size();i++){
			int v=adj[s][i];
			if(!vis[v]){
				dfs(v,d,cost);
			}
		}
	}
	vis[s]=false;
	ans.erase(ans.end()-1);
	return ;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int nodes;
	cin>>nodes;
	int edges=nodes-1;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int cost[nodes+1];
	cost[0]=0;
	for(int i=1;i<=nodes;i++){
		cin>>cost[i];
	}
	int q;
	cin>>q;
	while(q--){
		int s,d;
		cin>>s>>d;
		for(int i=0;i<=nodes;i++){
			vis[i]=false;
		}
		dfs(s,d,cost);
		
		//cout<<endl;
		}
	}
	

}