#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int incl=arr[0];
	int excl=0;
	int excl_new=INT_MIN;
	for(int i=1;i<n;i++){
		excl_new=max(incl,excl);
		incl=excl+arr[i];
		excl=excl_new;
		cout<<incl<<" "<<excl<<endl;
	}
	cout<<"---";
	cout<<max(incl,excl)<<endl;
}