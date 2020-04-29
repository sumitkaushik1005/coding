#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,q;
	cin>>n>>q;
	bool coin[n];
	memset(coin,false,sizeof(coin));
	while(q--){
		int c,l,r;
		cin>>c>>l>>r;
		if(c==1){
			int count=0;
				for(int i=l;i<=r;i++){
					if(coin[i])
						count++;
				}
				cout<<count<<endl;
		}
		if(c==0){
				for(int i=l;i<=r;i++){
					coin[i]=!coin[i];
				}
		}
			
	}
}