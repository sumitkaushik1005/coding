#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		set<char> st;
		for(int i=0;i<n;i++){
			char c;
			cin>>c;
			st.insert(c);
		}
		
		string s;
		getline(cin,s);
		getline(cin,s);
		int count=0;
		for(int i=0;i<s.length();i++){
			char x=s[i];
			if(st.find(x)!=st.end()){
				count++;
			}
		}
		cout<<count<<endl;
		}
}