#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int b[n];
		memset(b,0,sizeof(b));
		b[0]=1;
		for(int i=1;i<n;i++){
			if(a[i-1]<=a[i]){
				b[i]=b[i-1]+1;
			}
			else
				b[i]=1;
		}
		/*for(int i=0;i<n;i++){
			cout<<b[i]<<" ";
		}*/
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=b[i];
		}
		cout<<sum<<endl;
	}
}