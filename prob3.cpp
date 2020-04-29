#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> &a,pair<int,int> &b){
	return a.second>b.second;
}
void fn(int a[],int n,int k){
	unordered_map<int,int> m;
	vector<pair<int,int> >v;
	for(int i=0;i<n;i++){
		m[a[i]]++;
	}
	copy(m.begin(),m.end(),back_inserter(v));
	sort(v.begin(),v.end(),cmp);
	set<int> st;
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].second;j++){
			cout<<v[i].first<<" ";
			if(k>0 && st.find(v[i].first)==st.end()){
				st.insert(v[i].first);
				k--;	
			}
		}
	}
	cout<<endl;
	set<int>:: iterator it;
	for(it=st.begin();it!=st.end();it++){
		cout<<*it<<" ";
	}
}
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
		int k;
		cin>>k;
		fn(a,n,k);

	}
}