#include<bits/stdc++.h>
using namespace std;
pair<int,pair<int,int>> p[100];
int arr[100];
void init(int n){
	for(int i=1;i<=n;i++){
		arr[i]=i;
	}
}
int root(int x){
	while(arr[x]!=x){
		x=arr[x];
	}
	return x;
}
void union1(int x,int y){
	int root_x=root(x);
	int root_y=root(y);
	arr[root_x]=root_y;
}
int kruskal(pair<int,pair<int,int> > p[],int n){
	int minCost=0;
	for(int i=0;i<n;i++){
		int x=p[i].second.first;
		int y=p[i].second.second;
		int wt=p[i].first;
		if(root(x) != root(y)){
			union1(x,y);
			minCost+=wt;
		}
	}
	return minCost;
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int x,y,wt;
		cin>>x>>y>>wt;
		p[i]=make_pair(wt,make_pair(x,y));
	}
	sort(p,p+edges);
	init(nodes);
	int minCost=kruskal(p,edges);
	cout<<minCost<<endl;
}