#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int s[n];
	for(int i=0;i<n;i++){
		char c;
		cin>>c;
		if(c=='0'){
			s[i]=0;
		}
		else
			s[i]=1;
	}
	int s1[n];
	int m1=0,m2=0;
	for(int i=0;i<n;i++){
		s1[i]=i%2;
	}
	/*for(int i=0;i<n;i++){
		cout<<s1[i]<<" ";
	}*/
	for(int i=0;i<n;i++){
		if((int)s[i]^(s1[i])){
			m1++;
		}
	}
	//cout<<m1<<endl;
	int s2[n];
	for(int i=0;i<n;i++){
		s2[i]=(i+1)%2;
	}
	/*for(int i=0;i<n;i++){
		cout<<s2[i]<<" ";
	}*/
	for(int i=0;i<n;i++){
		if((int)s[i]^s2[i] ){
			m2++;
		}
	}
	//cout<<m2<<endl;
	cout<<min(m1,m2)<<endl;
}