#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];
int in_deg[1001];
vector<int> ans;
int nodes;
void allTopSort(){
	bool flag=false;
	for(int i=0;i<nodes;i++){
		if(vis[i]==false && in_deg[i]==0){
			vis[i]=true;
			ans.push_back(i);
			vector<int>::iterator it;
			for( it=adj[i].begin();it!=adj[i].end();it++){
				in_deg[*it]--;
			}
			allTopSort();
			vis[i]=false;
			ans.erase(ans.end()-1);
			for(it=adj[i].begin();it!=adj[i].end();it++){
				in_deg[*it]++;
			}
			flag=true;
		}
	}
	if(!flag){
		for(int i=0;i<nodes;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	memset(vis,false,sizeof(vis));
	memset(in_deg,0,sizeof(in_deg));
	for(int i=0;i<nodes;i++){
		vector<int>::iterator it;
		for(it=adj[i].begin();it!=adj[i].end();it++){
			in_deg[*it]++;
		}
	}
	allTopSort();
}