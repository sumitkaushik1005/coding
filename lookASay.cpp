#include<bits/stdc++.h>
using namespace std;
string fn(int n){
	if(n==1){
		return "1";
	}
	if(n==2){
		return "11";
	}
	string str="11";
	for(int i=3;i<=n;i++){
		str+='$';
		string temp="";
		int len=str.length();
		int cnt=1;
		for(int j=1;j<len;j++){
			if(str[j]!=str[j-1]){
				temp+=cnt+'0';
				temp+=str[j-1];
				cnt=1; 
			}
			else{
				cnt++;
			}
		}
		str=temp;
	}
	return str;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
	cin>>n;
	cout<<fn(n)<<endl;
	}
	
}