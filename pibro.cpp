#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		int head[n];
		head[0]=0;
		int tail[n];
		tail[n-1]=0;
		for(int i=1;i<n;i++){
			if(s[i-1]=='0'){
				head[i]=0;
			}
			else
				head[i]=head[i-1]+1;
		}	
		for(int i=n-2;i>=0;i--){
			if(s[i+1]=='0'){
				tail[i]=0;
			}
			else
				tail[i]=tail[i+1]+1;
		}
		int ans=INT_MIN;
		for(int i=0;i+k<=n;i++){
			ans=max(ans,k+head[i]+tail[i+k-1]);
		}
		cout<<ans<<endl;
	}
}