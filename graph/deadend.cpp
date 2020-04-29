#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		set<int> st;
		for(int i=0;i<n;i++){
			st.insert(a[i]);
			if(st.find(a[i]-1)==st.end()){
				st.insert(a[i]+1);
			}
		}
		int ans=st.size()-n;
		cout<<ans<<endl;
	}
}