#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.length();
	int number=0;
	int max_number=INT_MIN;
	int k=0;
	for(int i=n-1;i>=0;i--){
		if(s[i]>=97 && s[i]<=122){
			number=0;
			k=0;
		}
		else{
			number=(s[i]-48)*pow(10,k)+number;
			k++;
			if(number>max_number){
				max_number=number;
			}
		}
	}
	cout<<max_number<<endl;
}