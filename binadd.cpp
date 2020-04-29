#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s1;
		cin>>s1;
		int n1=stoi(s1,0,2);
		
		string s2;
		cin>>s2;
		int n2=stoi(s2,0,2);
		int count=0;
		while(n2!=0){
			int t1=(n1^n2);
			int t2=(n1&n2);
			n1=t1;
			n2=t2*2;
			count++;
		}
		cout<<count<<endl;
	}
}