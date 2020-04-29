#include<bits/stdc++.h>
using namespace std;
void fn(stack<int> s,int ele){
	if(s.empty() || s.top() < ele ){
		s.push(ele);
		return;
	}
	else{
		int temp=s.top();
		s.pop();
		fn(s,ele);
		s.push(temp);
	}
}
void sort(stack<int> s){
	if(!s.empty()){
		int temp=s.top();
		s.pop();
		sort(s);
		fn(s,temp);
	}
}
int main(){
	stack<int> s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.push(t);
	}
	sort(s);
	while(!s.empty()){
		int t=s.top();
		s.pop();
		cout<<t<<" ";
	}
}