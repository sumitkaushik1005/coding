#include<bits/stdc++.h>
using namespace std;
int capacity=4;
list<int> dq;
map<int,list<int>::iterator> m;
void insert(int x){
	if(m.find(x)==m.end()){
		if(dq.size()==capacity){
			int last=dq.back();
			dq.pop_back();
			m.erase(last);
		}
	}
	else{
		dq.erase(m[x]);
	}
	dq.push_front(x);
	m[x]=dq.begin();
}
void print(){
	for(auto i=dq.begin();i!=dq.end();i++){
		cout<<*i<<" ";
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		insert(x);
		print();	
	}
}