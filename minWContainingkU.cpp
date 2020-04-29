#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.length();
	int count[26];
	int k;
	cin>>k;
	memset(count,0,sizeof(count));
	int disE=0;
	int start=0;
	int end=0;
	int minL=INT_MAX;
	int start_index=0;
	for(int i=0;i<n;i++){
		count[s[i]-'a']++;
		end++;
		if(count[s[i]-'a']==1){
			disE++;
		}
		if(disE==k){
			while(start<end && count[s[start]-'a']>1){
					count[s[start]-'a']--;
					start++;
			}
			int len=end-start+1;
			if(minL>len){
				minL=len;
				start_index=start;
			}
		}
	}
	for(int i=start_index;i<start_index+minL-1;i++){
		cout<<s[i]<<" ";
	}
}