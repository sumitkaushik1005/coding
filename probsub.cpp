#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int g,d,c;
		cin>>g>>d>>c;
		double sum=g+d+c;
		double ans;
		if(sum!=0){
			ans=100*(d/sum);
		}
		if(ans>50)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
}