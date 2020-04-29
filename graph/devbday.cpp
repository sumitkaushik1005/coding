#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
bool vis[10001];
int money[10001];
void dfs(int s,int *sum){
	vis[s]=true;
	//cout<<"money";
	//cout<<money[s]<<endl;
	*sum += money[s];
	//cout<<*sum<<endl;
	for(int i=0;i<adj[s].size();i++){
		if(vis[adj[s][i]]==false){
			dfs(adj[s][i],sum);
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int nodes;
		cin>>nodes;
		for(int i=1;i<=nodes;i++){
			int x;
			cin>>x;
			adj[i].push_back(x);
		}	
		memset(money,0,sizeof(money));
		for(int i=1;i<=nodes;i++){
			cin>>money[i];
		}
		memset(vis,false,sizeof(vis));
		int max_sum=0;
		for(int i=1;i<=nodes;i++){
			int sum=0;
			dfs(i,&sum);
			for(int i=0;i<=10001;i++){
				vis[i]=false;
			}
			if(sum>max_sum){
				max_sum=sum;
			}
		}
		cout<<max_sum<<endl;
	}
}