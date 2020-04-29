#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int special=0;
	int pageno=1;
	for(int i=0;i<n;i++){
		int prob=a[i];
		for(int index=1;index<=prob;index++){
			if(index==pageno){
				special++;
			}
			if(index==prob || index%k==0){
				pageno++;
			}
		}
	}
	cout<<"sumit"<<special<<endl;
}