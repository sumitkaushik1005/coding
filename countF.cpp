#include<bits/stdc++.h>
using namespace std;
int root(int a[],int x){
	while(a[x]!=x){
		x=a[x];
	}
	return x;
}
void wt_union(int a[],int size[],int n,int x,int y){
	int root_x=root(a,x);
	int root_y=root(a,y);
	if(root_x!=root_y){
	if(size[root_x]<size[root_y]){
		a[root_x]=a[root_y];
		size[root_y]+=size[root_x];
	}
	else{
		a[root_y]=a[root_x];
		size[root_x]+=size[root_y];
	}
	
	}
	}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	int a[nodes+1];
	int size[nodes+1];
	for(int i=0;i<=nodes;i++){
		a[i]=i;
	}
	for(int i=0;i<=nodes;i++){
		size[i]=1;
	}
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		wt_union(a,size,nodes,x,y);
	}
	for(int i=1;i<=nodes;i++){
		cout<<size[i]<<" ";
	}
	cout<<endl;
}