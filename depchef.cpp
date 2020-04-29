#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int attack[n];
		int defend[n];
		for(int i=0;i<n;i++){
			cin>>attack[i];
		}
		for(int i=0;i<n;i++){
			cin>>defend[i];
		}
		int ans=-1;
		for(int i=0;i<n;i++){
			int left=(i-1+n)%n;
			int right=(i+1+n)%n;
			int total_attack=attack[left]+attack[right];
			if(total_attack < defend[i] && defend[i] > ans){
				ans=defend[i];
			}
		}
		cout<<ans<<endl;
	}
}