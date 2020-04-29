#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.length();
	int lps[n];
	lps[0]=0;
	int index=0;
	for(int i=1;i<n;){
		if(s[i]==s[index]){
			lps[i]=index+1;
			index++;
			i++;
		}else{
				if(index!=0){
					index=lps[index-1];
				}
				else{
					lps[i]=0;
					i++;
				}
		}
	}
	for(int i=0;i<n;i++){
		cout<<lps[i]<<" ";
	}
}