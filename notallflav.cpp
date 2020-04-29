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
		int flavour[k+1];
		for(int i=0;i<=k;i++){
			flavour[i]=0;
		}
		int start=0;
		int end=0;
		int distinctFlav=0;
		int maxLen=-1;
		while(end<n){

			if(flavour[a[end]]==0){
				distinctFlav++;
			}
			flavour[a[end]]++;
			while(distinctFlav>=k){

				if((end-start)>maxLen){
					maxLen=end-start;
				}
				flavour[a[start]]--;
				if(flavour[a[start]]==0){
					distinctFlav--;
				}
				start++;
			}
			end++;
		}
		if(maxLen==-1){
			cout<<n<<endl;
		}
		else
		cout<<maxLen<<endl;
		

	}
}