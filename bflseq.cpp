#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void print(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,p;
		cin>>n>>k>>p;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		int count=0;
		for(int i=0;i<n-k+1;i++){
			int j=i+k-1;
			for(;j<n;j++){
				
			}
			int z=j;
			while(z<n){
				for(int l=i;l<=i+k-1;l++){
					if(a[l+1]-a[l]>p)
						break;
				}
				count++;
				swap(&a[j],&a[z]);
				z++;
			}
			print(a,n);
			cout<<count<<endl;
			int temp=a[j];
			int aa;
			for(aa=j;aa<n-1;aa++){
				a[aa]=a[aa+1];
			}
			a[aa]=temp;
			cout<<"after rotation";
			print(a,n);
		}
		cout<<count<<endl;
	}
}

