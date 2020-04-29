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
	deque<int> dq;
	int i;
	for(i=0;i<k;i++){
		if(a[i]<0)
			dq.push_back(i);
	}
	for(;i<n;i++){
		if(dq.empty()){
			cout<<0<<endl;
		}
		else{
			cout<<a[dq.front()];
		}
		while(!dq.empty() && (i-k+1) > dq.front()){
			dq.pop_front();
		}
		if(a[i]<0){
			dq.push_back(i);
		}
	}
	if(dq.empty())
		cout<<0<<endl;
	else{
		cout<<a[dq.front()]<<" ";
	}
}