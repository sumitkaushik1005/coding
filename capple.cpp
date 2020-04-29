#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int apples[n];
		for(int i=0;i<n;i++){
			cin>>apples[i];
		}
		sort(apples,apples+n);
		int count=1;
		int j=0;
		//int b[n];
		for(int i=0;i<n;){
			int k=apples[i];
			while(apples[i]==k){
				i++;
			}
		//	b[j]=k;
			j++;
		}
		cout<<j<<endl;
		/*for(int i=1;i<j;i++){
			int diff=b[i]-b[i-1];
			count+=diff;
		}
		cout<<count<<endl;*/
	}
}