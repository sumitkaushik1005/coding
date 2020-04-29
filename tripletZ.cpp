#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	unordered_set<int> s;
	bool found=false;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int x=-(a[j]+a[i]);
			if(s.find(x)!=s.end()){
				cout<<x<<" "<<a[i]<<" "<<a[j]<<endl;
				found=true;
				
			}
			s.insert(a[j]);
		}
	}
	if(!found){
		cout<<"No triplet found"<<endl;
	}
}