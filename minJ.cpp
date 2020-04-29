#include<bits/stdc++.h>
using namespace std;
int minJ(int a[],int n){
	if(a[0]==0){
		return -1;
	}
	if(n<=1){
		return 0;
	}
	int maxR=a[0];
	int step=a[0];
	int j=1;
	for(int i=1;i<n;i++){
		if(i==n-1){
			return j;
		}
		maxR=max(maxR,i+a[i]);
		step--;
		if(step==0){
			j++;
			if(i>maxR){
				return -1;
			}
			step=maxR-i;
		}
	}
	return -1;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<minJ(a,n);
}