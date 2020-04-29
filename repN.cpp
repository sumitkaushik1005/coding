#include<bits/stdc++.h>
using namespace std;
void fn(int a[],int n){
	for(int i=0;i<n;i++){
		if(a[abs(a[i])]>=0){
			a[abs(a[i])]=-a[abs(a[i])];
		}
		else
			cout<<abs(a[i])<<" ";
	}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	fn(a,n);
}