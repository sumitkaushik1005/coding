#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,p;
	cin>>n>>k>>p;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int dis[n];
	dis[n-1]=a[n-1]+k;
	for(int i=n-2;i>=0;i--){
		if(a[i+1]-a[i] <= k){
			dis[i]=dis[i+1];
		}
		else{
			dis[i]=a[i]+k;
		}
	}
	for(int i=0;i<n;i++){
		cout<<dis[i]<<" ";
	}

}