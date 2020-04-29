#include<bits/stdc++.h>
using namespace std;
int fn(string s[],char c){
	for(int i=0;i<11;i++){
		string temp=s[i];
		int j=0;
		while(temp[j]!=NULL){
			if(temp[j]==c){
				return i;
			}
			j++;
		}
	}
	return -1;
}
int main(){
	string s[11]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz",""};
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++){
		int f=fn(s,a[i]);
		cout<<f;
	}
	cout<<endl;
	
}