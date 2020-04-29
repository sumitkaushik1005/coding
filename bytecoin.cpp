#include<bits/stdc++.h>
using namespace std;

long long int fn(long long int n,long long int a[]){
	if(n==0 || n==1){
		return n;
	}
	if(a[n]!=0){
		return a[n];
	}
	a[n]=max(n,fn(n/2,a)+fn(n/3,a)+fn(n/4,a));
	return a[n];
}
int main(){
	long long int n;
	while(cin>>n){
	long long int a[n+1];
	memset(a,0,sizeof(a));
	long long int ans=fn(n,a);
	cout<<ans<<endl;
	}
	
}