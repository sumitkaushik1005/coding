#include<bits/stdc++.h>
using namespace std;
int vis[1001][1001];
int mat[1001][1001];
bool isSafe(int i,int j,int row,int col){
	return (i>=0 && i<row && j>=0 && j<col && !vis[i][j] && mat[i][j]!=0);
}
void dfs(int i,int j,int row,int col){
	int rowN[]={-1,-1,-1,0,0,1,1,1};
	int colN[]={-1,0,1,-1,1,-1,0,1};
	vis[i][j]=true;
	for(int k=0;k<8;k++){
		if(isSafe(i+rowN[k],j+colN[k],row,col)){
			dfs(i+rowN[k],j+colN[k],row,col);
		}
	}
}
int main(){
	int row,col;
	cin>>row>>col;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>mat[i][j];
		}
	}
	for(int i=0;i<1001;i++){
		for(int j=0;j<1001;j++){
			vis[i][j]=false;
		}
	}
	int count=0;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(!vis[i][j] && mat[i][j]!=0){
				dfs(i,j,row,col);
				count++;
			}
		}
	}
	cout<<count<<endl;
}