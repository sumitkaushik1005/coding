#include<bits/stdc++.h>
using namespace std;
int arr[100];
int root(int x){
	while(arr[x] != x){
		x=arr[x];
	}
	return x;
}
void union(int a,int b){
	int root_a=root(a);
	int root_b=root(b);
	arr[root_a]=root_b;
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	
	for(int i=0;i<=nodes;i++){
		arr[i]=i;
	}
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		union(x,y);
		for(int i=0;i<nodes;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	

}