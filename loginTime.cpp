#include<bits/stdc++.h>
using namespace std;
bool compare(string s1,string s2){
	return s1.length()<s2.length();
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string passwords[n+1];
		for(int i=0;i<=n;i++){
			string s;
			cin>>s;
			passwords[i]=s;
		}
		sort(passwords,passwords+n,compare);
		cout<<passwords[n-1]<<endl;
		int plengths[passwords[n-1].length()+1];
		memset(plengths,0,sizeof(plengths));
		for(int i=0;i<n;i++){
			string temp=passwords[i];
			plengths[temp.length()]+=1;
		}
		string crtp=passwords[n];
		cout<<crtp<<endl;
		int crtpl=crtp.length();
		int besttime=0;
		int worsttime=0;
		int x=0;
		for(int i=0;i<crtpl;i++){
			x+=plengths[i];
		}
		if(x<k){
			besttime=x*1;
		}
		else{
			besttime=k*1+(x-k)*5;
		}
		int nx;
		if(plengths[crtpl]==1)
			nx=x;
		else
			nx=x+plengths[crtpl];

		if(nx<k){
			worsttime=nx*1;
		}
		else{
			worsttime=k*1+(nx-k)*5;
		}
		//worsttime=x*1+plengths[crtpl];
		cout<<besttime+1<<" "<<worsttime+1<<endl;



	}
}