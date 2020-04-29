#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int i=0;
	int l=s1.length();
	while(i<s1.length()){
		if(s2[i]!=s1[(i+2)%l]){
			cout<<"0"<<endl;
		}
		i++;
	}
	if(i==l){
		cout<<"1"<<endl;
	}

}