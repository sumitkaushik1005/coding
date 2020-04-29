#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	unordered_map<string,int> m;
	for(int i=0;i<n;i++){
		m[s[i]]+=1;
	}
	unordered_map<string,int>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		if(it->second==2){
			cout<<it->first<<endl;
		}
	}

}