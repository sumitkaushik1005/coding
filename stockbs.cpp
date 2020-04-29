#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int price[n];
	for(int i=0;i<n;i++){
		cin>>price[i];
	}
	int minPrice=price[0];
	int profit=INT_MIN;
	for(int i=0;i<n;i++){
		if(price[i]<minPrice){
			minPrice=price[i];
		}
		else if((price[i]-minPrice)>profit){
			profit=price[i]-minPrice;
		}
	}
	cout<<profit<<endl;
}