#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int price[n];
	for(int i=0;i<n;i++){
		cin>>price[i];
	}	
	int val[n+1];
	val[0]=0;
	for(int i=1;i<=n;i++){
		int maxV=INT_MIN;
		for(int j=0;j<i;j++){
			maxV=max(maxV,price[j]+val[i-j-1]);
		}
		val[i]=maxV;
	}
	cout<<val[n]<<endl;
}