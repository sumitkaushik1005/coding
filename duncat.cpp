#include<bits/stdc++.h>
using namespace std;
bool isPrime(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int i=s.length()-1;
		int count=0;
		int p=0;
		int number=0;
		for(int j=i;j>=0;j--){
			if(s[j]=='1'){
				number+=1*pow(2,p);
				count++;
			}
			p++;
		}
		if(isPrime(number)){
			cout<<count<<" Lucky day"<<endl;
		}
		else{
			cout<<count<<" Unlucky day"<<endl;
		}
	}
}