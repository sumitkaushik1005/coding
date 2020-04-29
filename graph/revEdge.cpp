#include<bits/stdc++.h>
using namespace std;
int minCount=INT_MAX;
int vis[4];
void fn(int s,int d,int count,int mat[4][4]){
	//cout<<count<<"sdf"<<endl;
	if(s==d){
		//cout<<count<<endl;
		minCount=min(minCount,count);
		
	}
	else{
		for(int i=0;i<4 ;i++){
			if(!vis[i] && mat[s][i]!=0){
				if(mat[s][i]==-1){
					count++;
				}
				vis[s]=true;
				fn(i,d,count,mat);
				vis[s]=false;
				count--;
			}
		}
	}
	return;
}
int main(){
	int nodes,edges;
	//cin>>nodes>>edges;
	int mat[4][4]={
				{0,1,0,0},{-1,0,-1,-1},{0,1,1,0}
	};
	memset(vis,false,sizeof(vis));
	fn(0,3,0,mat);
	cout<<minCount;
}