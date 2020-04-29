#include<bits/stdc++.h>
using namespace std;
int knap(int n,int W,int v[],int w[]){
	if(n==0 || W==0){
		return 0;
	}
	if(w[n-1] > W ){
		return knap(n-1,W,v,w);
	}
	else{
		return max(knap(n-1,W,v,w),v[n-1]+knap(n-1,W-w[n-1],v,w));
	}
}
int knapDP(int n,int W,int v[],int w[]){
	int table[n+1][W+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=W;j++){
			if(i==0|| j==0){
				table[i][j]=0;
			}
			if(w[i-1]>j){
				table[i][j]=table[i-1][j];
			}
			else
				table[i][j]=max(table[i-1][j],v[i-1]+table[i-1][j-w[i-1]]);
		}
	}
	return table[n][W];
}
int main(){
	int n;
	cin>>n;
	int W;
	cin>>W;
	int v[n];
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int w[n];
	for(int i=0;i<n;i++){
		cin>>w[i];	
	}
	//int ansR=knapR(n,W,v,w);
	int ansD=knapDP(n,W,v,w);
	cout<<ansD<<endl;
}