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
		int i=0;
		int j=n-1;
		int x=1;
		while(i<=j){
			if(a[i]==a[j] && (a[i] == x || a[i] == x+1)){
				x=a[i];
				i++;
				j--;
				
			}
			else{
				break;
			}
		}
		if(i>j){
			cout<<"yes";
		}
		else{
			cout<<"no";
		}
		cout<<endl;
	}
}