#include<bits/stdc++.h>
using namespace std;
int fn(int n1,int n2){
	 while(n1 != n2)
    {
        if(n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }	
    return n1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int prod[n];
		for(int i=0;i<n;i++){
			cin>>prod[i];
		}
		int m=0;
		for(int i=2;i<=n;i++){
			if(i*(i-1)==2*n){
				m=i;
				break;
			}
		}
		int ans[m];
		int x=prod[0];
		int y=prod[1];

		ans[0]=fn(x,y);
		cout<<ans[0];
		for(int i=1;i<m;i++){
			ans[i]=prod[i-1]/ans[0];
		}
		for(int i=0;i<m;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}