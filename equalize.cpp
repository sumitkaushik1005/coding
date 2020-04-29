#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n,greater<int>());
	int maxOcc=0;
	for(int i=1;i<n;){
		int occ=1;
		while(arr[i]==arr[i-1]){
			occ++;
			i++;
		}
		if(occ>maxOcc){
			maxOcc=occ;
		}
		i++;
		
	}
	cout<<(n-maxOcc)<<endl;
}