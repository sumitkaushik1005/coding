#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int k;
	cin>>k;
	int window_sum=0;
	for(int i=0;i<k;i++){
		window_sum+=a[i];
	}
	int max_sum=window_sum;
	int start=0;
	for(int i=k;i<=n-k;i++){
		window_sum=window_sum+a[i]-a[start];
		start++;
		max_sum=max(max_sum,window_sum);
	}
	cout<<max_sum<<endl;
}
