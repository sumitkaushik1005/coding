#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		set<int> st;
		for(int i=0;i<n;i++){
			int temp;
			cin>>temp;
			a[i]=temp;
			st.insert(temp);
		}
		sort(a,a+n);
		int count=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if((a[i]+a[j])%2 == 0){
					int avg=(a[i]+(a[j]-a[i]/2))/2;
				if(st.find(avg)!=st.end()){
					count++;
				}
				}
			}
		}
		cout<<count<<endl;
	}
}