#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string r,g;
		cin>>r>>g;
		int i=0;
		int prev=-1;
		int index=0;
		while(g[i]!='\0'){
			index=r.find(g[i],index);
			if(index>prev){
				prev=index;
			}
			else{
				cout<<"NO"<<endl;
				break;
			}
			i++;
		}
		if(i==g.length()){
			cout<<"YES"<<endl;
		}
	}
}