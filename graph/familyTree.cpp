#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];
int w[1001];
int diff=INT_MIN;
void dfs(int s,int *anc){
	vis[s]=true;
	int temp=abs(w[s]-w[*anc]);
	if(temp>diff){
		diff=temp;
	}
	cout<<s<<" ";
	for(int i=0;i<adj[s].size();i++){
		int v=adj[s][i];
		if(vis[v]==false){
			dfs(v,anc);
		}
	}
}
int main(){
	int nodes;
	cin>>nodes;
	for(int i=1;i<=nodes;i++){
		cin>>w[i];
	}
	int p[nodes+1];
	for(int i=1;i<=nodes;i++){
		cin>>p[i];
	}
	int root=0;
	for(int i=1;i<=nodes;i++){
		int x=p[i];
		if(x!=-1){
			adj[x].push_back(i);
		}
		else{
			root=i;
		}
	}
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=nodes;i++){
		if(vis[i]==false){
			dfs(i,&i);		
			memset(vis,false,sizeof(vis));
		}

	}
	
	cout<<endl;
	cout<<diff<<endl;

}