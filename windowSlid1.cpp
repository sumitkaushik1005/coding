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
	int max_sum=INT_MIN;
	int sum=0;
	for(int i=0;i<k;i++){
		sum+=a[i];
	}
	int start=0;
	int end=k;
	while(end<n){
		if(sum>max_sum){
			max_sum=sum;
		}
		sum-=a[start];
		sum+=a[end];
		start++;
		end++;
	}
	cout<<((max_sum>sum)? max_sum : sum)<<endl;
}