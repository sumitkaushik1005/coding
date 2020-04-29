#include<bits/stdc++.h>
using namespace std;
int arr[100];
int size[100];
int root(int x){
	while(arr[x] != x){
		x=arr[x];
	}
	return x;
}
void union1(int a,int b){
	int root_a=root(a);
	int root_b=root(b);

	if(size[root_a]<size[root_b]){
		arr[root_a]=arr[root_b];
		size[root_b]+=size[root_a];

	}else{
		arr[root_b]=arr[root_a];
		size[root_a]+=size[root_b];
	}
}
void init(int nodes){
	for(int i=0;i<=nodes;i++){
		arr[i]=i;
		size[i]=1;
	}
}
bool find(int a,int b){
	int root_a=root(a);
	int root_b=root(b);
	if(root_a==root_b){
		return true;
	}else{
		return false;
	}
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	init(nodes);
	int total=0;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		
		if(!find(x,y)){
			union1(x,y);
			for(int i=1;i<=nodes;i++){
				total+=size[root(i)];
			}
			cout<<total<<endl;
		}
		
	}
	cout<<total<<endl;
	/*
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		if(find(a,b)){
			cout<<"connected"<<endl;
		}
		else{
			cout<<"Not connected"<<endl;
		}
	}*/
	

}