#include<bits/stdc++.h>
using namespace std;
#define maximum INT_MAX-10
int main(){
	int t;
	cin>>t;
	while(t--){
		string L1;
		string L2;
		cin>>L1;
		cin>>L2;
		int n=L1.length();
		int D[2];
		D[0]=D[1]=0;
		int nD[2];

		for(int i=0;i<n;i++){
			nD[0]=((L1[i]=='#') ? maximum : min(D[0],D[1]+1));
			nD[1]=((L2[i]=='#') ? maximum : min(D[1],D[0]+1));
			D[0]=nD[0];
			D[1]=nD[1];
		}
		cout<<min(D[0],D[1])<<endl;
	}
}