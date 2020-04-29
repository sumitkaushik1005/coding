#include<bits/stdc++.h>
using namespace std;
int profit(int price[],int n,int k){
    int profit[k+1][n];
    for(int i=0;i<n;i++){
        profit[0][i]=0;
    }
    for(int i=0;i<=k;i++){
        profit[i][0]=0;
    }
    for(int i=1;i<=k;i++){
        int prev_diff=INT_MIN;
        for(int j=1;j<n;j++){
            prev_diff=max(prev_diff,profit[i-1][j-1]-price[j-1]);
            profit[i][j]=max(profit[i][j-1],prev_diff+price[j]);
        }
    }
    return profit[k][n-1];
}
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int k,n;
        cin>>k;
        cin>>n;
        int price[n];
        for(int i=0;i<n;i++){
            cin>>price[i];
        }
        int ans=profit(price,n,k);
        cout<<ans<<endl;
    }
	return 0;
}