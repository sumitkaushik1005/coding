#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
	cin>>s;
	int sum=0;
	int i=0;
	int n=s.length();
	while(i<n){
		int number=0;
		while(s[i]-48>=0 && s[i]-48<=9){
			number=number*10+(s[i]-48);
			i++;
		}
		sum+=number;
		i++;
	}
	cout<<sum<<endl;
	}
	
}