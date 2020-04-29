#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int maxEle;
void push(int k){
	if(s.empty()){
		s.push(k);
		maxEle=k;
	}
	if(k>maxEle){
		s.push(2*k-maxEle);
		maxEle=k;
	}
	else{
		s.push(k);
	}
}
int getMax(){
	return maxEle;
}
void pop(){
	if(s.empty()){
		return;
	}
	int t=s.top();
	s.pop();
	if(t> maxEle){
		cout<<"element to be poped out "<<endl;
		cout<<maxEle<<endl;
		maxEle=2*maxEle-t;
	}
	else{
		cout<<t<<" ";
	}
}
int main(){
	int n;
	push(2);
	push(5);
	push(1);
	push(9);
	//push(12);
	//pop();
	//pop();
	cout<<getMax()<<endl;
}