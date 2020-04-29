#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		bool flag=false;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==1)
				flag=true;
		}
		if(!flag){
			cout<<0<<endl;
			continue;
		}
		int count=0;
		int i=0;
		while(a[i]==0){
			i++;
		}
		for(int j=i;j<n;j++){
			if(a[j]==1){
				count++;
			}
			else{
				while(a[j]==0){
					j++;
				}
				count+=2;
			}
		}
		cout<<count<<endl;
	}
}