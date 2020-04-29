#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int i=-1;
		int n=s.length();
		int j=0;
		while(j<n){
			if(j<n-1 && s[j]=='a' && s[j+1]=='c'){
				j+=2;
			}
			else if(s[j]=='b'){
				j++;
			}
			else {
				s[++i]=s[j++];
			}
		}
		for(int k=0;k<=i;k++){
			cout<<s[k];
		}
		cout<<endl;
	}
	
}