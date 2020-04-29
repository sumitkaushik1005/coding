#include<bits/stdc++.h>
using namespace std;
#define V 4
	
bool isSafe(int graph[V][V],int v,int c,int color[V]){
	for(int i=0;i<V;i++){
		if(graph[v][i] && c==color[i]){
			return false;
		}
	}
	return true;
}
bool colorUtil(int graph[V][V],int m,int color[V],int v){
	if(v==V){
		cout<<"1"<<endl;
		return true;
	}
	for(int c=1;c<=m;c++){
			if(isSafe(graph,v,c,color)){
				color[v]=c;
				if(colorUtil(graph,m,color,v+1)){
					return true;
				}
				color[v]=0;
			}
	}
	return false;
}
bool fn(int graph[V][V],int m){
	int color[V];
	for(int i=0;i<V;i++){
		color[i]=0;
	}
	if(colorUtil(graph,m,color,0)){
		cout<<"solution exist"<<endl;
		for(int i=0;i<V;i++){
			cout<<color[i]<<" ";
		}
	}
	else
	{
		cout<<"here"<<endl;
		return false;
	}
}
int main(){
	int graph[V][V]={
			{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}
	};
	int m=3;
	fn(graph,m);
}