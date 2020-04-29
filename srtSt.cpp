#include<bits/stdc++.h>
using namespace std;
stack<int> s;
void fn1(int ele){
	if(s.empty() || ele > s.top()){
		s.push(ele);
		return ;
	}
	else{
		int temp=s.top();
		s.pop();
		fn1(ele);
		s.push(temp);
	}
}
void fn(){
	if(!s.empty()){
		int temp=s.top();
		s.pop();
		fn();
		fn1(temp);
	}
}
int main(){
	
	for(int i=0;i<5;i++){
		int k;
		cin>>k;
		s.push(k);
	}
	fn();
	while(!s.empty()){
		int t=s.top();
		s.pop();
		cout<<t<<" ";
	}
}