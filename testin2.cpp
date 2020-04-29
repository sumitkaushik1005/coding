#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int max_sum=INT_MIN;
		int number=0;
		for(int i=n-1;i>=0;i--){
			if(a[i]>sum){
				number=a[i];
			}
			int j=i-2;
			int sum=a[i];
			
			while(j>=0){
				sum=sum+a[j];
				if(sum>=max_sum){
					max_sum=sum;
					int temp=a[i]*10+a[j];
					cout<<temp<<endl
;					if(temp>number){
						number=temp;
					}
				}
				j--;
				sum=a[i];
			}
		}
		cout<<number<<endl;
	}
}