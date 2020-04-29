#include<bits/stdc++.h>
using namespace std;
int fn(string s,int start,string p,int m){
	sort(s.begin()+start,s.begin()+start+m);
	int j=0;
	for(j=start;j<start+m;j++){
		if(s[j]!=p[j-start]){
			return -1;
		}
	}
	return start;
}
int main(){
	string s;
	cin>>s;
	string p;
	cin>>p;
	int n=s.length();
	int m=p.length();
	sort(p.begin(),p.end());
	for(int i=0;i<=n-m;i++){
		int ans=fn(s,i,p,m);
		cout<<ans<<endl;
	}
}