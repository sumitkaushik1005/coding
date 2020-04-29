#include<bits/stdc++.h>
using namespace std;
bool fn(int x){
	set<int> st;
	while(x!=0){
		int digit=x%10;
		if(st.find(digit)!=st.end()){
			return false;
		}
		st.insert(digit);
		x=x/10;
	}
	return true;
}
int main(){
	int l,r;
	cin>>l>>r;
	int max_diff=0;
	int ans=0;
	for(int i=(l+r)/2-1;i<=r;i++){
	    if(i<l){
	        continue;
	    }
		if(fn(i)){
			long long temp=(r-i)*(i-l);
			if(temp>=max_diff){
				max_diff=temp;
				ans=i;
			}
		}
	}
	if(ans==r){
		cout<<-1<<endl;
	}
	else
	cout<<ans<<endl;
}