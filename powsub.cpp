#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	string a="hail";
	string b="hydra";
	int count=0;
	int maxCount=0;
	for(int i=0;i<s.length();i++){
		if(s.substr(i,a.length())==a){
			count=0;
			for(int j=i+1;j<s.length();j++){
				if(s.substr(j,b.length())==b){
					count++;
				}
			}
			maxCount+=count;
		}
	}
	cout<<maxCount<<endl;


}