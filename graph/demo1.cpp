#include<bits/stdc++.h>
using namespace std;
int main(){
	string s="adf 123";
	int i=0;
	while(i<s.length()){
		if(s[i]>='0' || s[i]<='9'){
			cout<<s[i]-'0';
			cout<<endl;
			i++;
		}
	}
}