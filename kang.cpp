#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	float k;
	if(b!=d){
		k=(float)(a-c)/(float)(d-b);
		cout<<k<<endl;
		if(k>0){
			if(floor(k)==ceil(k)){
				cout<<"Yes";
			}
			else{
				cout<<"NO";
			}
		}
		else
			cout<<"NO"<<endl;
	}

}