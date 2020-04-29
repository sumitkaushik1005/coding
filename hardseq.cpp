#include<bits/stdc++.h>
using namespace std;
int fn(int a[],int x,int l){
	int i;
	bool flag=false;
	for(i=l-2;i>=0;i--){
		if(a[i]==x){
			flag=true;
			break;
		}
	}
	if(flag){
		return (l-1-i);
	}
	else
		return 0;
}
int main(){
	int t;
	cin>>t;
	int arr[129];
	arr[0]=0;
	arr[1]=0;
	for(int i=2;i<129;i++){
		arr[i]=	fn(arr,arr[i-1],i);

	}
	while(t--){
		int n;
		cin>>n;
		int x=arr[n-1];
		int count=0;
		for(int i=n-1;i>=0;i--){
			if(arr[i]==x){
				count++;
			}
		}
		cout<<count<<endl;
	}
}