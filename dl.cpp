#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int odd=0;
	int even=0;
	for(int i=0;i<n;i++){
		if(a[i] & 1){
			odd++;
		}
		else
			even++;
	}
	if(abs(odd-even) <=1){
		cout<<"DL"<<endl;
	}
	else
		cout<<"DETAIN"<<endl;
}