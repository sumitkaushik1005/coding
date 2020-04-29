#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int S[n];
	for(int i=0;i<n;i++){
		cin>>S[i];
	}
	int sum;
	cin>>sum;
	int table[sum+1];
	memset(table,10000,sizeof(table));
	table[0]=0;
	for(int i=0;i<=sum;i++){
		cout<<table[i]<<" ";
	}cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=S[i];j<=sum;j++){
			table[j]=min(table[j],1+table[j-S[i]]);
		}
	}
	for(int i=0;i<=sum;i++){
		cout<<table[i]<<" ";
	}
	cout<<table[sum]<<endl;
}