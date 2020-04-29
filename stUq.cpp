#include<bits/stdc++.h>
using namespace std;
queue<int> q1,q2;
void enqueue(int k){
	
	q2.push(k);
	while(!q1.empty()){
		q2.push(q1.front());
		q1.pop();
	}
	queue<int> temp=q1;
	q1=q2;
	q2=temp;
}
int main(){
	for(int i=0;i<5;i++){
		int t;
		cin>>t;
		enqueue(t);
	}
	while(!q1.empty()){
		int t=q1.front();
		cout<<t<<" ";
		q1.pop();
	}
}