#include<bits/stdc++.h>
using namespace std;
int dis[1001][1001];
int main(){
	int n,e,f;
	cin>>n>>e>>f;
	int cap[n];
	for(int i=0;i<n;i++){
		cin>>cap[i];
	}
	for(int i=0;i<1001;i++){
		for(int j=0;j<1001;j++){
			if(i==j){
				dis[i][j]=0;
			}
			else
			dis[i][j]=INT_MAX/2-2;
		}
	}
	for(int i=0;i<e;i++){
		int x,y,wt;
		cin>>x>>y>>wt;
		dis[x][y]=wt;
		dis[y][x]=wt;
	}
	int k;
	cin>>k;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=k;i++){
		int min=INT_MAX;
		int index=0;
		int cost=0;
		for(int j=1;j<=n;j++){
			if(dis[1][j]<min && cap[j-1]!=0){
				min=dis[1][j];
				index=j;
			}
		}
		if(min==0){
			cost+=f;
		}else{
			cost=f+ min;
		}
		cap[index-1]-=1;
		cout<<cost<<" ";
	}

}