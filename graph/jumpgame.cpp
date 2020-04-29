#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int jump[n];
	for(int i=0;i<n;i++){
		jump[i]=INT_MAX-1;
	}
	jump[0]=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[j]+j>=i && jump[i]>jump[j]+1){
				jump[i]=jump[j]+1;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<jump[i]<<" ";
	}
	cout<<endl;
}