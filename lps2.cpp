#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.length();
	int lps[n];
	memset(lps,0,sizeof(lps));
	int len=0;
	int i=1;
	while(i<n){
		if(s[i]==s[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len!=0){
				len=lps[len-1];
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
	cout<<endl;
}