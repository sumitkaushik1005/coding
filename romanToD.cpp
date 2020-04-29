#include<bits/stdc++.h>
using namespace std;
int getValue(char c){
	if(c=='I'){
		return 1;
	}
	if(c=='V'){
		return 5;
	}
	if(c=='X'){
		return 10;
	}
	if(c=='L'){
		return 50;
	}
	if(c=='C'){
		return 100;
	}
	if(c=='D'){
		return 500;
	}
	if(c=='M'){
		return 1000;
	}
	return -1;
	
	
	
}
int fn(string r){
	int res=0;
	for(int i=0;i<r.length();i++){
		int s1=getValue(r[i]);
		if(i+1 < r.length()){
			int s2=getValue(r[i+1]);
			if(s1 >= s2){
				res=res+s1;
			}
			else{
				res=res+s2-s1;
				i++;
			}
		}
		else{
			res=res+s1;
			i++;
		}
	}
	return res;
}
int main(){
	string r;
	cin>>r;
	cout<<fn(r);
}