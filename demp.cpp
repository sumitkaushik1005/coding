#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<vector<int>> a;
	vector<int> temp;
	for(int i=1;i<5;i++){
		for(int j=1;j<=5;j++){
			temp.push_back(j);
		}
		a.push_back(temp);
	}
	vector<int> ans= a[1];
	for(int i=ans.size()-5;i<ans.size();i++){
		cout<<ans[i]<<" ";	
	}
}