#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int l,b;
		cin>>l>>b;
		int ans;
		for(int x=1;x<=min(l,b);x++){
			if(l%x == 0 && b%x == 0){
				ans=x;
			}
		}
		cout<<l*b/ans/ans<<endl;
	}
}