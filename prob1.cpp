#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		map<int,int> m;
		for(int i=0;i<n;i++){
			int p,s;
			cin>>p>>s;
			if(m[p]< s){
				m[p]=s;	
			}
		} 
		int ans=0;
		for(int i=1;i<=8;i++){
			ans+=m[i];
		}
		cout<<ans<<endl;
	}
}