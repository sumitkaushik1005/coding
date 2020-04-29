#include<bits/stdc++.h>
using namespace std;
int fn(int a,int b,int c,int d){
	return max(max(a,b),max(c,d));
}
int main(){
	
		int n;
		cin>>n;
		char mat[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>mat[i][j];
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=1;j<=n-2;j++){
				int maxDepth=fn((int)mat[i][j-1],(int)mat[i][j+1],(int)mat[i+1][j],(int)mat[i-1][j]);
				if((int)mat[i][j] > maxDepth){
					mat[i][j]='X';
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<mat[i][j];
			}
			cout<<endl;
		}
}