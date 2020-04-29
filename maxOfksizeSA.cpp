#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int k;
	cin>>k;
	int maxI=INT_MIN;
	for(int i=0;i<k;i++){
		maxI=max(maxI,a[i]);
	}
	cout<<maxI<<" ";
	for(int i=k;i<n;i++){
		maxI=max(maxI,a[i]);
		cout<<maxI<<" ";
	}
	
}