#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		char a[n];
		int count=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]=='H'){
				count++;
			}
		}
		int last=n-1;
		while(k--){
			if(a[last]=='H'){
				count=0;
				for(int i=0;i<last;i++){
					if(a[i]=='H'){
						a[i]='T';
					}
					else{
						a[i]='H';
						count++;
					}
				}

			}
			//cout<<count<<endl;
			last--;
		}
		cout<<count<<endl;
	}
}