#include<bits/stdc++.h>
using namespace std;
struct doll{
	int w;
	int h;
};
bool cmp(doll d1,doll d2){
	return ( (d1.w < d2.w) && (d1.h < d2.h));
}
int main(){
	int n;
	cin>>n;
	doll d[n];
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		d[i].w=a;
		d[i].h=b;
	}
	sort(d,d+n,cmp);
	for(int i=0;i<n;i++){
		cout<<d[i].w<<" "<<d[i].h<<endl;
	}
}