#include<bits/stdc++.h>
using namespace std;
int main(){
	int r=4;
	int c=5;
	int mat[r][c];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			int x;
			cin>>x;
			mat[i][j]=x;
		}
	}
	int t;
	cin>>t;
	int i=0;
	int j=c-1;
	while(i<5 && j>=0){
		if(mat[i][j]==t){
			cout<<"found at"<<i<<" "<<j<<endl;
			break;
		}
		else if(mat[i][j] < t){
			i++;
		}
		else
			j--;
	}

}