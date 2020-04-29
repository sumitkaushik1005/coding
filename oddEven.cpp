#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x&1)
			a[i]=-1;
		else
			a[i]=1;
	}
	a[0]=0;
	map<int,int> m;
	m[0]++;
	int ans=0;
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
		ans+=m[a[i]];
		m[a[i]]++;
	}
	cout<<ans<<endl;
}