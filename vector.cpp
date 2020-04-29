#include<bits/stdc++.h>
using namespace std;
void fn(vector<int> &v){
	int n=v.size();
	cout<<n<<" ";
	vector<int> a=v;
	for(int i=0;i<5;i++){
		cout<<a[i]<<" ";
	}
}
int main(){
	vector<int> v;
	for(int i=0;i<5;i++){
		int t;
		cin>>t;
		v.push_back(t);
	}
	
	fn(v);
}