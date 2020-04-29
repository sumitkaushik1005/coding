#include<bits/stdc++.h>
using namespace std;
int fn(string x,string y){
	int j=0;
	for(int i=0;i<=(x.length()-y.length());i++){
		for( j=0;j<y.length();j++){
			if(x[i+j]!=y[j]){
				break;
			}
		}
		if(j==y.length()){
			return i;
		}
	}
	return -1;
}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<fn(s1,s2)<<endl;
}