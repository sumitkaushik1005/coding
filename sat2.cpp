#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int arr[n+1];
		memset(arr,0,sizeof(arr));
		for(int i=0;i<m;i++){
			int u,v;
			cin>>u>>v;
			arr[u]=1;
			arr[v]=1;
		}
		int cost=0;
		for(int i=1;i<=n;i++){
			if(arr[i]==0){
				for(int j=1;j<=n;j++){
					if(j!=i){
						cost+=(j*i);
						arr[i]=1;
						break;
					}
				}
			}
		}
		cout<<cost<<endl;
	}
}