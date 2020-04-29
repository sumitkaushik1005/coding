#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int prices[n];
		for(int i=0;i<n;i++){
			int ta;
			cin>>ta;
			prices[i]=ta;
		}
		int count=1;

		for(int i=1;i<n;i++){
			bool flag=true;
			int j=i-1;
			int p=prices[i];
			for(;j>=0 && j>=i-5;j--){
				if(prices[j] < p){
					flag=false;
				}
			}
			if(flag)
				count++;
		}
		cout<<count<<endl;
	}
}