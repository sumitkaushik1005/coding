#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=a[i];
		}
		if(sum>k){
			cout<<"No"<<endl;
		}
		else{
			cout<<"Yes"<<endl;
		}
	}
}