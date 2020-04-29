#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.length();
		int count[26];
		int start=0;
		int end=0;
		int start_index=0;
		int max_len=INT_MIN;
		memset(count,0,sizeof(count));
		for(int i=0;i<n;i++){
			count[s[i]-'a']++;
			end++;
			if(count[s[i]-'a'] > 1){
				while(count[s[i]-'a']!=1){
					count[s[start]-'a']--;
					start++;
				}
				int len=end-start+1;
				if(max_len<len){
					max_len=len;
					start_index=start;
				}

			}
		}
		for(int i=start_index;i<start_index+max_len-1;i++){
			cout<<s[i];
		}
		cout<<endl;

	}
}