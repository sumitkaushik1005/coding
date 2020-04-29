#include<bits/stdc++.h>
using namespace std;
int fn(string s,int i,int j,string pat){
	int a[26];
	memset(a,0,26*sizeof(a[0]));
	for(int k=i;k<j;k++){
		a[s[k]-97]+=1;
	}
	for(int k=0;k<pat.length();k++){
		if(a[pat[k]-97]==0){
			return -1;
		}
	}
	return 1;
}
int main(){
	string s;
	cin>>s;
	string pat;
	cin>>pat;
	int n=s.length();
	int m=pat.length();
	for(int gap=m;gap<n;gap++){
		for(int i=0,j=gap;j<n;i++,j++){
			int ans=fn(s,i,j,pat);
			if(ans==1){
				cout<<i<<" "<<j<<endl;
				return -1;
			}
		}
	}
}