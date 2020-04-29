#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1;
	cin>>s1;
	string s2;
	cin>>s2;
	int a[26];
	memset(a,0,26*sizeof(a[0]));
	for(int i=0;i<s1.length();i++){
		a[s1[i]-'a']=1;
	}
	for(int i=0;i<s2.length();i++){
		if(a[s2[i]-'a']==0){
			a[s2[i]-'a']=2;
		}
		else if(a[s2[i]-'a']==1){
			a[s2[i]-'a']=-1;
		}
	}
	for(int i=0;i<26;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<26;i++){
		if(a[i]==1 || a[i]==2){
			cout<<(char)(i+'a');
		}
	}
	cout<<endl;
}