#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		long long int p[n];
		int count[n];
		memset(count,0,sizeof(count));
		for(int i=0;i<n;i++){
			cin>>p[i];
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			for(int i=x-1;i<y;i++){
				count[i]+=1;
			}
		}
		int index=-1;
		int maxP=INT_MIN;
		for(int i=0;i<n;i++){
			if(maxP<count[i]){
				maxP=count[i];
				index=i;
			}
		}
		cout<<p[index];
		cout<<endl;
	}
}