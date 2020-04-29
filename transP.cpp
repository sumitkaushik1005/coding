#include<bits/stdc++.h>
using namespace std;
int fn(int a[],int low,int high){
	if(low<=high){
		int mid=(low+high)/2;
		if(a[mid]==1){
			return fn(a,mid+1,high);
		}
		else{
			if(mid>0 && a[mid-1]==1)
				return mid;
			else
				return fn(a,low,mid-1);
		}
	}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=fn(a,0,n-1);
	cout<<ans<<endl;
}