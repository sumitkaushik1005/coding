#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	string pat;
	getline(cin,pat);
	int hash_str[26];
	int hash_pat[26];
	memset(hash_pat,0,sizeof(hash_pat));
	memset(hash_str,0,sizeof(hash_str));
	for(int i=0;i<pat.length();i++){
		hash_pat[pat[i]-'a']++;
	}
	int start=0;
	int end=0;
	int min_len=INT_MAX;
	int count=0;
	int start_index=0;
	for(int i=0;i<s.length();i++){
		hash_str[s[i]-'a']++;
		
		if(hash_pat[s[i]-'a']!=0 && hash_str[s[i]-'a'] <= hash_pat[s[i]-'a']){
			count++;
		}
		if(count==pat.length()){
			while(hash_pat[s[start]-'a']==0 || hash_str[s[start]-'a'] > hash_pat[s[start]-'a']){
				if(hash_str[s[start]-'a'] > hash_pat[s[start]-'a']){
					hash_str[s[start]-'a']--;
				}
				start++;
			}
			int len=i-start+1;
			if(min_len>len){
				min_len=len;
				start_index=start;
			}
		}
	}
	for(int i=start_index;i<start_index+min_len;i++){
		cout<<s[i]<<" ";
	}
}