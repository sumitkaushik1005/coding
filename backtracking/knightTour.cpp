#include<bits/stdc++.h>
using namespace std;
#define n 8
bool isSafe(int mat[n][n],int x,int y){
	if(x>=0 && x<n && y>=0 && y<n && mat[x][y]==-1)
		return true;
	return false;
}
void print(int mat[n][n]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool solveKT(int mat[n][n],int x,int y,int move,int a[n],int b[n]){
   int next_x,next_y;
    if(move==n*n){
    	print(mat);
    	return true;
    }
	for(int i=0;i<8;i++){
		next_x=x+a[i];
		 next_y=y+b[i];
		if(isSafe(mat,next_x,next_y)){
			mat[next_x][next_y]=move;
			//cout<<"here"<<move<<endl;
			if(solveKT(mat,next_x,next_y,move+1,a,b)){
				return true;
			}

			mat[next_x][next_y]=-1;
		}
	}
	return false;
}
int main(){
	int mat[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mat[i][j]=-1;
		}
	}
	mat[0][0]=0;

	int a[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
    int b[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
	solveKT(mat,0,0,1,a,b);
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}*/
}