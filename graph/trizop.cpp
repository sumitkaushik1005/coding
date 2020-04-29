#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int mat[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(mat[i][j]!=mat[i-1][j-1]){
				cout<<"false"<<endl;
				return -1;
			}
		}
	}
	cout<<"true"<<endl;
	return -1;
}