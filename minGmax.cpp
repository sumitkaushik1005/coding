#include<bits/stdc++.h>
using namespace std;
int maxC(int a[],int i,int j){
	int max=a[i];
	for(int k=i+1;k<=j;k++){
		if(a[k]>max){
			max=a[k];
		}
	}
	return max;
}
int minC(int a[],int i,int j){
	int min=a[i];
	for(int k=i;k<=j;k++){
		if(a[k]<min){
			min=a[k];
		}
	}
	return min;
}
int fn(int a[],int k,int n){
	int table[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		table[i][j]=0;
		}
		
	}
	for(int gap=0;gap<n;gap++){
		for(int i=0,j=gap;j<n;i++,j++){
			int min_n=minC(a,i,j);
			int max_n=maxC(a,i,j);
			table[i][j]=(2*min_n>max_n)?0:min(table[i][j-1]+1,table[i+1][j]+1);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
	cout<<table[i][j]<<" ";
		}
		cout<<endl;
		
	}
	return table[0][n-1];
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<fn(a,0,n);
}