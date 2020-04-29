#include<bits/stdc++.h>
using namespace std;
void print(char c[]){
	for(int i=0;i<sizeof(c)/sizeof(char);i++){
		cout<<c[i];
	}
}
void fn1(string s,int i,int j,char *c,int n){
	if(i==n){
		c[j]='\0';
		print(c);
		cout<<endl;
		return;
	}
	c[j]=s[i];
	fn1(s,i+1,j+1,c,n);
	c[j]=' ';
	c[j+1]=s[i];
	fn1(s,i+1,j+2,c,n);
}
void fn(string s,int n){
	char c[2*n];
	c[0]=s[0];
	fn1(s,1,1,c,n);
}
int main(){
	string s;
	cin>>s;
	int n=s.length();
	fn(s,n);
}