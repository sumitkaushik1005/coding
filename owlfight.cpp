#include<bits/stdc++.h>
using namespace std;
int root(int x,int a[]){
	while(x!=a[x]){
		x=a[x];
	}
	return x;
}
void wt_union(int a[],int size[],int x,int y){
	int root_y=root(y,a);
	int root_x=root(x,a);
	if(root_y!=root_x){
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
		size[i]=1;
	}
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		wt_union(a,size,x,y);
	}
	for(int i=0;i<=nodes;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	int q;
	cin>>q;
	while(q--){
		int x,y;
		cin>>x>>y;
		int root_x=root(x,a);
		int max_f_x=root_x;
		for(int i=0;i<=nodes;i++){
			if(a[i]==root_x){
				max_f_x=max(max_f_x,i);
			}
		}
		int root_y=root(y,a);
		int max_f_y=root_y;
		for(int i=0;i<=nodes;i++){
			if(a[i]==root_y){
				max_f_y=max(max_f_y,i);
			}	
		}
		if(root_x!=root_y){
			if(max_f_x > max_f_y){
				cout<<x<<endl;
			}
			else
				cout<<y<<endl;
		}
		else{
			cout<<"TIE"<<endl;
		}
	}
}