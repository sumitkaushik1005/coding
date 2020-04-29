#include<bits/stdc++.h>
using namespace std;
int fn(string a,string b){
	int hash[26];
		memset(hash,0,26*sizeof(hash[0]));
		for(int i=0;i<a.length();i++){
			hash[a[i]-65]+=1;
		}
		for(int i=0;i<b.length();i++){
			if(hash[b[i]-97]!=0){
				return 1;
			}
		}
		return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		cout<<fn(a,b)<<endl;
	}
}