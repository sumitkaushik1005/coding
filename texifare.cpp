#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int x,m,n,d;
		cin>>x>>m>>n>>d;
		int fare=0;
		if(d<=x){
			fare=m;
			cout<<fare<<endl;
			continue;
		}
		fare=m;
		d=d-x;
		fare+=d*n;
		cout<<fare<<endl;
	}
}