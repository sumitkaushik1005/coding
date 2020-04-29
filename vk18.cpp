#include<bits/stdc++.h>
using namespace std;
int fnDmnd(int n){
	int even=0;
	int odd=0;
	while(n!=0){
		int digit=n%10;
		if(digit%2==0){
			even+=digit;
		}
		else
			odd+=digit;
		n=n/10;
	}
	return abs(even-odd);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=0;
		for(int i=0;i<n;i++){
			int row=0;
			for(int j=i;j<n;j++){
				int sum=i+j+2;
				row+=fnDmnd(sum);
			}
			int temp=fnDmnd(i+i+2);
			ans+=(row*2-temp);
		}
		cout<<ans<<endl;

	}
}