#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.length();
	int m=s2.length();
	int lps[m+1][n+1];
	int result=INT_MIN;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0){
				lps[i][j]=0;
			}
			else if(s1[j-1]==s2[i-1]){
				lps[i][j]=1+lps[i-1][j-1];
				result=max(result,lps[i][j]);
			}
			else
				lps[i][j]=0;
		}
	}
	cout<<result<<endl;
}