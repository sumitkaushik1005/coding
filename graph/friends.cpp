#include<bits/stdc++.h>
using namespace std;
const int ll 2e5+3
vector<int> adj[ll];
int dis[ll][ll];
bool vis[ll];
int mat[ll][ll];
int countNu=0;
set<pair<int,int>> st;
void dfs(int s,int d,int *path,int &index,int dis){
	vis[s]=true;
	path[index]=s;
	index++;
	if(dis==0 && s==d ){
		/*for(int i=0;i<index;i++){
			cout<<path[i]<<" ";
		}*/
		for(int i=0;i<index-1;i++){
			pair<int,int> p=make_pair(path[i],path[i+1]);
			if(st.find(p)!=st.end()){
				countNu++;
			}
		}
	}
	for(int i=0;i<adj[s].size();i++){
		if(vis[adj[s][i]]==false){
			dfs(adj[s][i],d,path,index,dis-1);
		}
	}
	index--;
	vis[s]=false;
}
int parent[1001];
int low[1001];
int disc[1001];

void bridge(int s){
	static int time=0;
	low[s]=disc[s]=++time;
	int subtree=0;
	vis[s]=true;
	for(int i=0;i<adj[s].size();i++){
		int v=adj[s][i];
		if(vis[v]==false){
			subtree++;
			parent[v]=s;
			bridge(v);
			low[s]=min(low[s],low[v]);
			if(low[v]>disc[s]){
				st.insert(make_pair(s,v));
				st.insert(make_pair(v,s));
			}
		}
		else if(v!=parent[s]){
			low[s]=min(low[s],disc[v]);
		}
	}
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	memset(vis,false,sizeof(vis));
	for(int i=0;i<1001;i++){
		for(int j=0;j<1001;j++){
			if(i==j){
				dis[i][j]=0;
			}
			else{
				dis[i][j]=INT_MAX/2-2;
			}
		}
	}
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		dis[x][y]=1;
		dis[y][x]=1;
	}
	memset(parent,-1,sizeof(parent));
	memset(low,INT_MAX/2-2,sizeof(low));
	memset(disc,INT_MAX/2-2,sizeof(disc));
	bridge(1);
	
	memset(vis,false,sizeof(vis));
	for(int k=1;k<=nodes;k++){
		for(int i=1;i<=nodes;i++){
			for(int j=1;j<=nodes;j++){
				dis[i][j]=min(dis[i][j],(dis[i][k]+dis[k][j]));
			}
		}
	}

	int path[nodes];
		int index=0;
		int q;
		cin>>q;
		while(q--){
			countNu=0;
			int u;
			cin>>u;
			dfs(u,nodes,path,index,dis[u][nodes]);
			if(countNu==0){
				cout<<"impossible"<<endl;
			}else
			cout<<countNu<<endl;	
		}
		
	/*for(int i=1;i<=nodes;i++){
		for(int j=1;j<=nodes;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}*/
}