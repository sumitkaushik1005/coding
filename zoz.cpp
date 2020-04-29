#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=a[i];
		}
		int count=0;
		for(int i=0;i<n;i++){
			int t1=a[i];
			sum-=t1;
			int t2=t1+k;
			if(t2>sum){
				count++;
			}
			sum+=t1;
		}
		cout<<count<<endl;
	}
}