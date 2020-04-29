#include<bits/stdc++.h>
using namespace std;
int max_int=INT_MAX;
vector<int> b_i;
vector<int> b_j;
void binary_rep(int i){
	if(i>1){
		binary_rep(i/2);
	}
	b_i.push_back(i%2);
}
int main(){
	int n;
	cin>>n;
	while(n--){
		int i,j;
		cin>>i>>j;
		binary_rep(i);
		string s;
		for(int i=0;i<b_i.size();i++){
			s+=b_i[i]+"";
		}
		cout<<s<<endl;
	}
}