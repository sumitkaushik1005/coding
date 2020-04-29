#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int max_index=n-1;
	int min_index=0;
	int max_ele=a[max_index]+1;
	for(int i=0;i<n;i++){
		if(i%2==0){
			a[i]+=((a[max_index]%max_ele)*max_ele);
			max_index--;
		}
		else{
			a[i]+=((a[min_index]%max_ele)*max_ele);
			min_index++;
		}
	}
	for(int i=0;i<n;i++){
		//int t=a[i]/max_ele;
		cout<<a[i]<<" ";
	}
}