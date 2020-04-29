#include<bits/stdc++.h>
using namespace std;
/*int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} */

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		int blackTile=1;
		set<int> factors;
		for(int i=1;i<=sqrt(n);i++){
			if(n%i==0){
				factors.insert(i);
			}
		}
		/*for(auto i=factors.begin();i!=factors.end();i++){
			cout<<*i<<" ";
		}
		cout<<endl;*/
		for(int i=2;i<n;i++){
			if(factors.find(i)==factors.end()){
		//		cout<<i<<endl;
				int g=__gcd(n,i);
				//cout<<g<<endl;
				if(g==1){
					blackTile++;
				}
			}
			
		}
		cout<<blackTile<<endl;
	}
}