#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=0;
	int minV=INT_MAX;
	int maxV=INT_MIN;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	for(int i=0;i<n;i++){
		if(minV>a[i]){
			minV=a[i];
		}
	}
	for(int i=0;i<n;i++){
		if(maxV<a[i]){
			maxV=a[i];
		}
	}
	if(sum>k){
		cout<<"YES"<<endl;
		return -1;
	}
	//cout<<minV<<" "<<maxV<<" "<<sum<<endl;
	int req=k-sum;
	bool flag1=false;
	bool flag2=false;
	if(req>minV && req<maxV){
		flag1=true;
	}
	if(!flag1){
		cout<<"NO"<<endl;
		return -1;
	}
	for(int i=0;i<n;i++){
		if(a[i]==req){
			flag2=true;
		}
	}
	if(flag2){
		cout<<"NO"<<endl;
		return -1;
	}
	cout<<"YES"<<endl;
	return -1;
	
}