#include<bits/stdc++.h>
using namespace std;
int fn(int s,int w1,int w2,int w3){
	if(w1+w2+w3 <=s){
		return 1;
	}
	if(w2+w3 <= s){
		return 2;
	}
	return 3;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int s,w1,w2,w3;
		cin>>s>>w1>>w2>>w3;
		
		int ans=fn(s,w1,w2,w3);
		ans=min(ans,fn(s,w3,w2,w1));
		cout<<ans<<endl;
	}
}