#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<vector<int>> v;
	vector<int> temp1;
	vector<int> temp2;
	for(int i=0;i<5;i++){
		int t;
		cin>>t;
		temp1.push_back(t);
	}
	for(int i=0;i<6;i++){
		int t;
		cin>>t;
		temp2.push_back(t);
	}
	v.push_back(temp1);
	v.push_back(temp2);
	for(int i=0;i!=v.size();i++){
		for(int j=0;j<=v[i].size();j++){
			cout<<v[i].at(j);
		}
	}

}