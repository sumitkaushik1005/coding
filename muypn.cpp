#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string ans;
		int n=s.length();
		if(n==0){
			cout<<"-1"<<endl;
			continue;
		}
		int i;
		for(i=0;i<n;i++){
			if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57)){
				if(s[i]>=65 && s[i]<=90){
				ans+=(char)(s[i]-65+97);
			}
			else if(s[i]>=97 && s[i]<=122){
				ans+=(char)(s[i]-97+65);
			}
			else
				ans+=(char)s[i];
			}
		else{
			cout<<"-1";
			cout<<endl;
			break;
		}
	}
	if(i==n){
		cout<<ans<<endl;
	}
}
}#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string ans;
		int n=s.length();
		if(n==0){
			cout<<"-1"<<endl;
			continue;
		}
		int i;
		for(i=0;i<n;i++){
			if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57)){
				if(s[i]>=65 && s[i]<=90){
				ans+=(char)(s[i]-65+97);
			}
			else if(s[i]>=97 && s[i]<=122){
				ans+=(char)(s[i]-97+65);
			}
			else
				ans+=(char)s[i];
			}
		else{
			cout<<"-1";
			cout<<endl;
			break;
		}
	}
	if(i==n){
		cout<<ans<<endl;
	}
}
}