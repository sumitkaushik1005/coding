#include<bits/stdc++.h>
using namespace std;
stack<int> s;
void fn(int k){
	if(s.empty() || s.top()>k){
		s.push(k);
	}
	
	else{
		int temp=s.top();
		s.pop();
		fn(k);
		s.push(temp);
	}
}
void fn1(){
	if(!s.empty()){
		int temp=s.top();
		s.pop();
		fn1();
		fn(temp);
	}
}
int main(){
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		fn(k);
	//	s.push(k);
	}
	//fn1();
	while(!s.empty()){
		int t=s.top();
		cout<<t<<" ";
		s.pop();
	}
}