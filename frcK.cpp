#include<bits/stdc++.h>
using namespace std;
struct item{
	int wt;
	int val;
};
bool cmp(struct item a,struct item b){
	int r1=(double)(a.val/a.wt);
	int r2=(double)(b.val/b.wt);
	return r1>r2;
}
double fn(struct item a[],int W,int n){
	sort(a,a+n,cmp);
	int curr=0;
	double final=0.0;
	cout<<n<<endl;
	for(int i=0;i<n;i++){
		cout<<"sumit";
		if((curr+a[i].wt) <= W){
			curr+=a[i].wt;
			final+=a[i].val;
		}
		else{
			int remain_wt=W-curr;
			final+=a[i].val * ((double)remain_wt/a[i].wt);
			break;
		}
		cout<<final<<endl;
	}
	return final;
}
int main(){
	int n;
	cin>>n;
	struct item a[n];
	for(int i=0;i<n;i++){
		int w,v;
		cin>>v>>w;
		a[i].wt=w;
		a[i].val=v;
	}
	int W;
	cin>>W;
	cout<<fn(a,W,n);
}