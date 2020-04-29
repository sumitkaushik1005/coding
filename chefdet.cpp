#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	bool is_parent[n+1];
	memset(is_parent,false,sizeof(is_parent));
	for(int i=0;i<n;i++){
		int p;
		cin>>p;
		is_parent[p]=true;
	}
	for(int i=0;i<=n;i++){
		if(!is_parent[i]){
			cout<<i<<" ";
		}
	}
	cout<<endl;
}