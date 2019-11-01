#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n,k;
	cin>>n>>k;
	if(k==0){
		cout<<0<<" "<<n<<endl;
	}
	else{
		long long int a=n/k;
		long long int b=n%k;
		cout<<a<<" "<<b<<endl;
	}
	}
	
}