#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	long long int n,m,k;
	cin>>n>>m>>k;
	long long int candybought=0;
	long long int candytotal=0;
	while(candytotal < k){
		candybought+=n;
		candytotal+= (n+m);
	}
	cout<<candybought<<endl;
	}
	
}