#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int b[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i =0;i<n;i++){
			cin>>b[i];
		}
		int maxP=INT_MIN;
		for(int i=0;i<n;i++){
			int pa=a[i]*20;
			int pb=b[i]*10;
			int pt=((pa-pb)>0)?(pa-pb):0;
			maxP=max(maxP,pt);
		}
		cout<<maxP<<endl;
	}
}