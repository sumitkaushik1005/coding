#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		int disR=0;
		int i=1;
		while(disR <= x){
			disR+=i;
			if(disR>=x){
				break;
			}
			i++;
		}

		cout<<i<<endl;
		int minT1=1+(i-1)+ (disR-x);
		i--;
		int minT2=1+(i-1)+ (x-(disR-i));
		cout<<minT1<<endl;
		cout<<minT2<<endl;
	}
}