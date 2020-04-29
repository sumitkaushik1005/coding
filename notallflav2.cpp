#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int first=0;
		int second=0;
		int maxLen=-1;
		int start=0;
		int end=0;
		while(end<n){
			if(a[end]==1){
				first++;
			}
			else{
				second++;
			}
			if(first==0 || second==0){
				if((end-start+1)>maxLen){
					maxLen=end-start+1;
				}

			}
			else{
				while( !(first==0 || second==0) ){
					if(a[start]==1){
						first--;
					}
					else{
						second--;
					}
					start++;
				}
			}
			end++;
		}
		cout<<maxLen<<endl;
	}
}