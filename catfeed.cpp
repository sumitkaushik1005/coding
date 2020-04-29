#include<bits/stdc++.h>
using namespace std;
int minTimeCatfeed(int feed[],int n){
	int m=INT_MAX;
	for(int i=0;i<n;i++){
		if(feed[i] < m){
			m=feed[i];
		}
	}
	return m;
}
int check(int a[],int m,int feed[],int n){
	
	for(int i=0;i<m;i++){
		int c=a[i];
		//cout<<"c "<<c<<endl;
		int min_f=minTimeCatfeed(feed,n);
		//cout<<min_f<<endl;
		if(feed[c-1]>min_f){
			return -1;
		}
		feed[c-1]+=1;
	}
	for(int i=0;i<n;i++){
		cout<<feed[i]<<" ";
	}
	cout<<endl;
	return 1;

}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int a[m];
		for(int i=0;i<m;i++){
			cin>>a[i];
		}
		int feed[n];
		memset(feed,0,sizeof(feed));
		
		int ans=check(a,m,feed,n);
		if(ans==1){
			cout<<"YES";
		}
		else
			cout<<"NO";
		cout<<endl;
	}
	return -1;
}