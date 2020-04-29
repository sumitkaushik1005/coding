#include<bits/stdc++.h>
using namespace std;
pair<int,int> p[100];
int arr[100];
vector<int> adj[100];
int degree(int x){
	return arr[x];
}
void destroy(int x){
	for(int i=0;i<adj[x].size();i++){
		arr[adj[x][i]]-=1;
	}
	arr[x]=0;
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	memset(arr,0,sizeof(arr));
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		p[i]=make_pair(x,y);
		arr[x]+=1;
		arr[y]+=1;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int count=0;
	for(int i=0;i<edges;i++){
		int x=p[i].first;
		int y=p[i].second;
		
		if(y<x){
			int temp=x;
			x=y;
			y=temp;
		}
		int d_x=degree(x);
		int d_y=degree(y);
		if(d_x==0 || d_y == 0){
			continue;
		}
		if(d_x> d_y){
			destroy(x);
		}
		else{
			destroy(y);
		}
		count++;
	}
	cout<<count<<endl;
}