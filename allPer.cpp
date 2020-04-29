#include<bits/stdc++.h>
using namespace std;
void swap(char *a,char *b){
	char temp=*a;
	*a=*b;
	*b=temp;
}
void fn(char *c,int l,int r){
	if(l==r){
		cout<<c<<endl;
	}
	else{
		for(int i=l;i<=r;i++){
			swap((c+l),(c+i));
			fn(c,l+1,r);
			swap((c+l),(c+i));
		}
	}
}
int main(){
	char c[]="ABC";
	fn(c,0,2);
			
}