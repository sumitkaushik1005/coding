#include<bits/stdc++.h>
using namespace std;
int arr[100];
void init(int nodes){
	for(int i=0;i<=nodes;i++){
		arr[i]=i;
	}
}
int root(int x){
	while(arr[x]!=x){
		x=arr[x];
	}
	return x;
}
void union1(int a,int b){
	int root_a=root(a);
	int root_b=root(b);
	if(a<b){
		arr[root_a]=root_b;

	}else{
		arr[root_b]=root_a;
	}
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	init(nodes);
	for(int i=1;i<=edges;i++){
		int x,y;
		cin>>x>>y;

		union1(x,y);
		for(int i=0;i<=nodes;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		int root_a=root(a);
		int root_b=root(b);
		if(root_a==root_b){
			cout<<"TIE"<<endl;
		}
		else if(root_a > root_b){
			cout<<a<<endl;
		}
		else{
			cout<<b<<endl;
		}
	}
}