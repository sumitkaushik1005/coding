#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1;
	cin>>s2;
	unordered_map<char,int> m;
	int i=0;
	while(s2[i]!=NULL){
		m[s2[i]]=1;
		i++;
	}
	i=0;
	while(s1[i]!=NULL){
		if(m[s1[i]]!=1){
			cout<<s1[i];
		}
		i++;
	}
	cout<<endl;
}