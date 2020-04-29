#include<bits/stdc++.h>
using namespace std;
void fn(int a[],int n,int sum){
	unordered_map<int,int> m;
	int curr_sum=0;
	for(int i=0;i<n;i++){
		curr_sum+=a[i];
		if(curr_sum==sum){
			cout<<0<<" "<<i<<endl;
			return;
		}
		else if(m.find(curr_sum-sum)!=m.end()){
				cout<<m[curr_sum-sum]+1<<" "<<i<<endl;
				return;
		}
		m[curr_sum]=i;
	}
	cout<<"No subarray with given sum exists"<<endl;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum;
	cin>>sum;
	fn(a,n,sum);
}