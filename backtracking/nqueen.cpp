#include<bits/stdc++.h>
using namespace std;
#define n 4
bool isSafe(int board[n][n],int row,int col){
	int i,j;
	for(i=0;i<col;i++){
		if(board[row][i])
			return false;
	}
	for(i=row,j=col;i>=0 && j>=0 ; i--,j--){
		if(board[i][j])
			return false;
	}
	 for (i = row,j = col; j >= 0 && i < n; i++, j--){
	 	if (board[i][j]) 
            return false; 
	 } 
        

     return true;
}
bool solve(int board[n][n],int col){
	if(col>=n){
		return true;
	}
	for(int i=0;i<n;i++){
		if(isSafe(board,i,col)){
			board[i][col]=1;
			if(solve(board,col+1))
				return true;
			board[i][col]=0;
		}
	}
	return false;
}
int main(){
	int board[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			board[i][j]=0;
		}
	}
	solve(board,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}