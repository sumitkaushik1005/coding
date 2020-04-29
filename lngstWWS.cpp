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
	int start=0;
	int end=0;
	int max_len=INT_MIN;
	int start_index=0;
	int curr_sum=0;
	for(int i=0;i<n;i++){
		curr_sum+=a[i];
		end++;
		if(curr_sum==k){
			int len=end-start+1;
			if(max_len<len){
				max_len=len;
				start_index=start;
			}
		}
		else if(curr_sum > k){
				while(curr_sum>k){
					curr_sum=curr_sum-a[start];
					start++;
				}
		}
	}
	for(int i=start_index;i<start_index+max_len-1;i++){
		cout<<a[i]<<" ";
	}
}