#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		vector<int> ans;
		for(int i=0;i<n;i++){
			ans.push_back(a[i]);
			if(ans.size()==3){
				sort(ans.begin(),ans.end());
				vector<int>::iterator it=ans.begin();
				ans.erase(it+1);
			}
		}
		for(auto i=ans.begin();i!=ans.end();i++){
			cout<<*i<<endl;
		}
	}
}