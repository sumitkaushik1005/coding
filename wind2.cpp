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
	deque<int> d;
	int i;
	for( i=0;i<k;i++){

		while(!d.empty() && a[d.back()] <= a[i]){
			d.pop_back();
		}
		d.push_back(i);
	}
	for(;i<n;i++){
		cout<<a[d.front()]<<" ";
		while(!d.empty() && (i-k) >= d.front()){
			d.pop_front();
		}
		while(!d.empty() && a[d.back()] <= a[i]){
			d.pop_back();
		}
		d.push_back(i);
	}
	cout<<a[d.front()]<<" ";
	
}