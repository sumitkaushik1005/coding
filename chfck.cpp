#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
  
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int minPrime=INT_MAX;
		for(int i=0;i<n;i++){
			if(isPrime(a[i])){
				minPrime=min(minPrime,a[i]);
			}
		}
		cout<<minPrime<<endl;
		
	}
}