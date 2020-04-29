#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int coin[n];
	int type[n];
	for(int i=0;i<n;i++){
		cin>>coin[i];
	}
	for(int i=0;i<n;i++){
		cin>>type[i];
	}
	int min_1=INT_MAX;
	int min_2=INT_MAX;
	int min_3=INT_MAX;
	for(int i=0;i<n;i++){
		switch(type[i]){
			case 1:
				if(min_1 > coin[i]){
					min_1=coin[i];
				}
			break;
			case 2:
				if(min_2 > coin[i]){
					min_2=coin[i];
				}
			break;
			case 3:
				if(min_3 > coin[i]){
					min_3 = coin[i];
				}
			break;
		}
	}
	/*cout<<min_1<<endl;
	cout<<min_2<<endl;
	cout<<min_3<<endl;*/
	if(min_1!=INT_MAX && min_2!=INT_MAX){
		int minimum=((min_1+min_2)>min_3)? min_3: (min_1+min_2) ;
		cout<<minimum<<endl;
	}
	else{
		cout<<min_3<<endl;
	}
	
}