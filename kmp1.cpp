#include<bits/stdc++.h>
using namespace std;
int *fn(string s,int *lps,int n){
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
	return lps;
}
int main(){
	string str,pat;
	cin>>str;
	cin>>pat;
	int n=str.length();
	int m=pat.length();
	int lps[m];
	fn(pat,lps,m);
	int i=0,j=0;
	for(int i=0;i<m;i++){
		cout<<lps[i]<<" ";
	}
	cout<<endl;
	while(i<n){
		if(str[i]==pat[j]){
			i++;
			j++;
		}
		if(j==m){
			cout<<"starting index: "<<i-j<<endl;
			j=lps[j-1];
		}
		else if(i<n && str[i]!=pat[j]){
			if(j!=0){
				j=lps[j-1];
			}
			else{
				i=i+1;
			}
		}
	}
}