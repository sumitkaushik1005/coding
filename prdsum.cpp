#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int q;
	cin>>q;
	while(q--){
		int l,r,d;
		cin>>l>>r>>d;
		int i=0;
		int sum=0;
		while( (r-i*d)>=l){
			sum+=a[r-i*d  ];
			i++;
		}
		cout<<sum<<endl;
	}
}