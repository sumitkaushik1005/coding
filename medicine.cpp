#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int pills[n];
	pills[0]=1;
	for(int i=1;i<n;i++){
		if(arr[i]>arr[i-1]){
			pills[i]=pills[i-1]+1;
		}
		else
			pills[i]=1;
	}/*
	for(int i=0;i<n;i++){
		cout<<pills[i]<<" ";
	}
	cout<<endl;*/
	for(int i=n-2;i>=0;i--){
		if(arr[i+1]<arr[i] && pills[i]<=pills[i+1]){
			pills[i]=pills[i+1]+1;
		}
	}
/*
	for(int i=0;i<n;i++){
		cout<<pills[i]<<" ";
	}
	cout<<endl;*/
	int count=0;
	for(int i=0;i<n;i++){
		count+=pills[i];
	}
	cout<<count<<endl;
}