#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		l--;
		r--;
		int peak1;
		int peak2;
		int j=l+1;
		peak1=j-1;
		for(;j<=r;j++){
			if(a[j]>a[j-1]){
				peak1=j;
			}
			else
				break;
		}
		int i=r-1;
		peak2=i+1;
		for(;i>=l;i--){
			
			if(a[i]>a[i+1]){
				peak2=i;
			}else
			break;
		}
		if(peak2==peak1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

	
}