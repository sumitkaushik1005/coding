#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	int lis[n];
	for(int i=0;i<n;i++){
		lis[i]=1;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(A[i]>=A[j] && lis[i]<=lis[j]+1){
				lis[i]=lis[j]+1;
			}
		}
	}
	int lds[n];
	for(int i=0;i<n;i++){
		lds[i]=1;
	}
	/*for(int i=n-2; i>=0; i--)
    {
        for(int j=i+1; j<n; j++)
        {
            if(A[i] > A[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;
        }
    }*/
      for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(A[i]>= A[j] && lds[i]<lds[j]+1){
                lds[i]=lds[j]+1;
            }
        }
    }
	for(int i=0;i<n;i++){
		cout<<lis[i]<<" ";
	}
	cout<<endl;

	for(int i=0;i<n;i++){
		cout<<lds[i]<<" ";
	}
	cout<<endl;
	int maxN=lis[0]+lds[0]-1;
    for(int i=1;i<n;i++){
        maxN=max(maxN,lis[i]+lds[i]-1);
    }
	cout<<maxN<<endl;
}