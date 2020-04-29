#include<bits/stdc++.h>
using namespace std;
int main(){
	int s;
	cin>>s;
	while(s--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(n%2==0){
			cout<<"no"<<endl;
			continue;
		}
		if(a[0]!=1){
			cout<<"no"<<endl;
			continue;
		}
		if(a[n-1]!=1){
			cout<<"no"<<endl;
			continue;
		}
		bool flag=true;
		for(int i=0;i<n/2;i++){
			if(a[i]+1 != a[i+1]){
				flag=false;
				break;
			}
		}
		for(int i=n/2;i<n-1;i++){
			if(a[i] != a[i+1]+1){
				flag=false;
				break;
			}
		}
		if(flag){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
}