#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int zero=0;
		int two=0;
		for(int i=0;i<n;i++){
			if(a[i]==0){
				zero++;
			}
			else if(a[i]==2){
				two++;
			}
		}
		int ans=(zero)*(zero-1)/2 + (two)*(two-1)/2;
		cout<<ans<<endl;
	}	
}