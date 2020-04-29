#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
int dis[10001][10001];
int main(){
	int t;
	cin>>t;
	while(t--){
		int nodes,edges;
		cin>>nodes;
		cin>>edges;
		for(int i=0;i<=nodes;i++){
			for(int j=0;j<=nodes;j++){
				if(i==j){
					dis[i][j]=0;
				}
				else
				dis[i][j]=INT_MAX/2-2;
			}
		}
		for(int i=1;i<=nodes-1;i++){
			dis[i][i+1]=1;
			dis[i+1][i]=1;
		}
		for(int i=0;i<edges;i++){
			int x,y;
			cin>>x>>y;
			dis[x][y]=1;
			dis[y][x]=1;
		}
		for(int k=1;k<=nodes;k++){
			for(int i=1;i<=nodes;i++){
				for(int j=1;j<=nodes;j++){
					dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
				}
			}
		}
		int sum=0;
		for(int i=1;i<=nodes;i++){
			for(int j=i+1;j<=nodes;j++){
				sum+=dis[i][j];
			}
		}
		cout<<sum<<endl;
		for(int i=1;i<=nodes;i++){
			for(int j=1;j<=nodes;j++){
				cout<<dis[i][j]<<" "; 
			}
			cout<<endl;
		}

	}
}