#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int U,N;
		double D;
		cin>>D>>U>>N;
		double price=D*U;
		int ans=0;
		for(int i=1;i<=N;i++){
			int M;
			double R;
			int C;
			cin>>M>>R>>C;
			double cost=(double)(C/M)+ R*U;
			//cout<<"cost "<<cost<<endl;
			if(cost < price){
				price=cost;
				ans=i;
			}
		}
		cout<<ans<<endl;
	}
}