#include<bits/stdc++.h>
using namespace std;
bool fn(string pat,string str){
	int n=pat.length();
	int m=str.length();
	bool T[n+1][m+1];
	memset(T,false,sizeof(T));
	T[0][0]=true;
	for(int i=1;i<=n;i++){
		if(pat[i-1]=='*'){
			T[i][0]=T[i-1][0];
		}
	}
	for(int j=1;j<=m;j++){
		T[0][j]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(pat[i-1]=='*'){
				T[i][j]=T[i-1][j] || T[i][j-1];
			}
			else if(pat[i-1] == '?' || str[j-1]==pat[i-1]){
				T[i][j]=T[i-1][j-1];
			}
			else
				T[i][j]=false;
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cout<<T[i][j]<<" ";
		}
		cout<<endl;
	}
	return T[n][m];
}
int main(){
	string str,pat;
	cin>>str;
	cin>>pat;
	if(fn(pat,str)){
		cout<<"yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}