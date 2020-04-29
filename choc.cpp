#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int candies[n];
	memset(candies,0,n*sizeof(int));
	candies[0]=1;
	for(int i=1;i<n;i++){
		if(candies[i]==0){
			candies[i]=1;
		}
		if(a[i]>a[i-1]){
			candies[i]=candies[i-1]+1;
		}
	}
	for(int i=0;i<n;i++){
		cout<<candies[i]<<" ";
	}
	cout<<endl;
	for(int i=n-1;i>=0;i--){
		if(a[i-1]>a[i] && candies[i-1]<=candies[i]){
			candies[i-1]=candies[i]+1;
		}
	}
	int result=0;
	for(int i=0;i<n;i++){
		result+=candies[i];
	}
	cout<<result<<endl;
}