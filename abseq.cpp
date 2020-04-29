#include<bits/stdc++.h>
using namespace std;
int main(){
	int l;
	cin>>l;
	string s;
	cin>>s;
	stack<char> st;
	st.push(s[0]);
	for(int i=1;i<l;i++){
		char c=s[i];
		if(!st.empty() && st.top()=='a' && c=='b'){
			st.pop();
		}
		else{
			st.push(c);
		}
	}
	cout<<st.size()<<endl;
}