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
		long long int max_coin=INT_MIN;
		for(int i=0;i<n;i++){
			long long int coins=a[i];
			for(int j=i+k;j<n;j+=k){
				coins+=a[j];
			}
			max_coin=max(max_coin,coins);
		}
		cout<<max_coin<<endl;	
	}
}