#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,d;
		cin>>n>>k>>d;
		int coor[n];
		for(int i=0;i<n;i++){
			cin>>coor[i];
		}
		sort(coor,coor+n);
		int max_dis[n];
		memset(max_dis,0,sizeof(max_dis));
		max_dis[n-1]=coor[n-1]+d;
		for(int i=n-2;i>=0;i--){
			if(coor[i+1]-coor[i] <= d){
				max_dis[i]=max_dis[i+1];
			}
			else{
				max_dis[i]=coor[i]+d;
			}
		}
		for(int i=0;i<n;i++){
			cout<<max_dis[i]<<" ";
		}
	}

}