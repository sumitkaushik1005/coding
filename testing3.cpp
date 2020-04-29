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
		reverse(a,a+n);
		int number=0;
		int max_sum=INT_MIN;
		for(int i=0;i<=n-1;i++){
			if(a[i]<0){
				continue;
			}
			int sum=a[i];
			int temp_number=a[i];
			for(int j=i+2;j<n;j+=2){
				sum+=a[j];
				if(sum>=max_sum){
					max_sum=sum;
					temp_number=10*temp_number+a[j];
			//		cout<<temp_number<<endl;
					if(temp_number>number){
						number=temp_number;
					}
				}
			}
			//cout<<max_sum<<endl;
			if(a[i]>max_sum){
				number=a[i];
				max_sum=number;
			}
		}
		cout<<number<<endl;
	}
}