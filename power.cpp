#include<bits/stdc++.h>
using namespace std;
int fnF(string s, char c){
	int i=0;
	while(s[i]!='\0'){
		if(s[i]==c){
			return i;
		}
		i++;
	}
}
int fnL(string s,char c){
	int i=s.length()-1;
	for(;i>=0;i--){
		if(s[i]==c){
			return i;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string rs;
		cin>>rs;
		string s=rs;
		reverse(rs.begin(),rs.end());
		int count[26];
		memset(count, -1, sizeof(count));
		int i=0;
		while(s[i]!='\0'){
			if(count[s[i]-'a']==-1){
				char c=s[i];
				int f=fnF(s,c);
				int l=fnL(s,c);
			//	cout<<f<<" "<<l<<endl;
				count[c-'a']=(l-f);
			}
			i++;
		}
		int m=INT_MIN;
		int c;
		for(int i=0;i<26;i++){
			if(count[i]>m){
				m=count[i];
				c=i;
			}
		}
		cout<<(char)('a'+c)<<" "<<m<<endl;
	}
}