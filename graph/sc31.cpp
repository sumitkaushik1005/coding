#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<string> input[n];
		for(int i=0;i<n;i++){
			string temp;
			cin>>temp;
			input[i].push_back(temp);
		}
		int ans=0;
		int count=0;
		for(int j=0;j<10;j++){
			count=0;
			for(int i=0;i<n;i++){
				string s=input[i][0];
				if(s[j]=='1'){
					count++;
				}
			}
			if(count%2!=0){
				ans++;
			}
			
		}
		cout<<ans<<endl;

	}
}