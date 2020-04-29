#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	string s;
	cin>>s;
	int k;
	cin>>k;
	if(k>s.length()){
		cout<<"0"<<endl;
	}
	else{
		int a[26];
	memset(a,0,26*sizeof(a[0]));
	for(int i=0;i<s.length();i++){
		a[s[i]-97]+=1;
	}
	for(int i=0;i<k;i++){
		int m=INT_MIN;
		int j=-1;
		for(int i=0;i<26;i++){
			if(a[i]>m){
				m=a[i];
				j=i;
			}
		}
		a[j]=a[j]-1;
	}
	int minValue=0;
	for(int i=0;i<26;i++){
		if(a[i]!=0){
			minValue=minValue+pow(a[i],2);
		}
	}
	cout<<minValue<<endl;
	
	}
	}
	
}