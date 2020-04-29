#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		int mat[x+1][y+1];
		memset(mat,0,sizeof(mat));
		int a,b;
		cin>>a>>b;
		mat[0][0]=1;
		for(int i=0;i<=x;i++){
			for(int j=0;j<=y;j++){
				if(i==a && j==b)
					continue;
				if(i+1<=x)
					mat[i+1][j]+=mat[i][j];
				if(j+1<=y)
					mat[i][j+1]+=mat[i][j];
			}
		}
		for(int i=0;i<=x;i++){
			for(int j=0;j<=y;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}