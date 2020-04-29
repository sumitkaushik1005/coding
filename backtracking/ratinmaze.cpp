#include<bits/stdc++.h>
using namespace std;
#define n 4
bool isSafe(int maze[n][n],int row,int col){
	if(row>=0 && row<n && col>=0 && col<n && maze[row][col]!=0){
		return true;
	}
	return false;
}
bool ratInMaze(int maze[n][n],int row,int col,int sol[n][n]){
	if(row==n-1 && col==n-1){
		sol[row][col]=1;
		return true;
	}
	if(isSafe(maze,row,col)){
		sol[row][col]=1;
		if(ratInMaze(maze,row+1,col,sol)){
			return true;
		}
		if(ratInMaze(maze,row,col+1,sol)){
			return true;
		}
		sol[row][col]=0;
		return false;
	}
	return false;
}
int main(){
	int maze[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>maze[i][j];
		}
	}
	int sol[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sol[i][j]=0;
		}
	}
	sol[0][0]=1;
	ratInMaze(maze,0,0,sol);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
}