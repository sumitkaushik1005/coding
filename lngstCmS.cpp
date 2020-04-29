#include<bits/stdc++.h>
using namespace std;
int fn(string s,int n){
	int vis[26];
	memset(vis,-1,26*sizeof(vis[0]));
	vis[s[0]-97]=0;
	int curr_len=1;
	int max_len=1;
	int prev_index=0;
	for(int i=1;i<n;i++){
		prev_index=vis[s[i]-97];
		if(prev_index==-1 || (i-curr_len)>prev_index ){
			curr_len++;
		}else{
			if(curr_len>max_len){
				max_len=curr_len;
			}
			curr_len=i-prev_index;
		}
		vis[s[i]-97]=i;
	}
	if(curr_len>max_len){
		max_len=curr_len;
	}
	//free(vis);	
	return max_len;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
	cin>>s;
	int n=s.length();
	cout<<fn(s,n)<<endl;
	}
	
}