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
		int rem=0;
		int i;
		for(i=0;i<n;i++){
			if(a[i]+rem < k){
				cout<<"NO "<<i+1<<endl;
				break;
			}
			else{
				rem=(a[i]+rem)-k;
			}
		}
		if(i==n){
			cout<<"YES"<<endl;
		}
	}
}