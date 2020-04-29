#include<bits/stdc++.h>
using namespace std;
int countDiv(int n){
    int cnt=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(n/i==i){
                cnt++;
            }    
            else
                cnt+=2;
        }
    }
    return cnt;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int diff=abs(a-b);
        int divisors=countDiv(diff);
        cout<<divisors<<endl;
    }
}
