#include<bits/stdc++.h>
using namespace std;
bool isValid(int count[],int k){
	int val=0;
	for(int i=0;i<26;i++){
		if(count[i]!=0){
			val++;
		}
	}
	return k>=val;
}
void fn(string s,int k){
	int count[26];
	memset(count,0,sizeof(count));
	int start=0;
	int end=0;
	int start_index=0;
	int max_len=INT_MIN;
	int n=s.length();
	count[s[0]-'a']++;
	for(int i=1;i<n;i++){
		count[s[i]-'a']++;
		end++;
		while(!isValid(count,k)){
			count[s[start]-'a']--;
			start++;
		}
		int len=end-start+1;
		if(len>max_len){
			max_len=len;
			start_index=start;
		}
	}
	for(int i=start_index;i<=start_index+max_len-1;i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
}
int main(){
	string s;
	cin>>s;
	int k;
	cin>>k;
	int count[26];
	memset(count,0,sizeof(count));
	for(int i=0;i<s.length();i++){
		count[s[i]-'a']++;
	}
	int val;
	for(int i=0;i<26;i++){
		if(count[i]!=0){
			val++;
		}
	}
	if(val>k){
		cout<<"NO window exists"<<endl;
		
	}
	fn(s,k);
	return -1;

}