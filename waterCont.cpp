#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int maxarea=INT_MIN;
		int l=0;
		int r=n-1;
		while(l<r){
			maxarea=max(maxarea,min(a[l],a[r])*(r-1));
			if(a[l]<a[r]){
				l++;
			}
			else
				r--;
		}
		cout<<maxarea<<endl;
	}
}