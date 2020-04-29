#include<bits/stdc++.h>
using namespace std;
int fn(string s){
	int i=0;
	int n=s.length();
	int number=0;
	while(i<n){
		int digit=s[i]-'0';
		number=number*10+digit;
		i++;
	}
	return number;
}
int main(){
	string s;
	cin>>s;
	int n=s.length();
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	dp[1]=((s[0]!='0')?1:0);

	for(int i=2;i<=n;i++){
		string s1=s.substr(i-1,1);
		//cout<<"substr"<<s1<<endl;
		string s2=s.substr(i-2,2);
		//cout<<"substr:"<<s2<<endl;
		int num1=fn(s1);
		//cout<<num1<<endl;
		int num2=fn(s2);
		//cout<<num2<<endl;
		if(num1>=1 && num1<=9){
			dp[i]+=dp[i-1];
		}
		if(num2>=10 && num2<=26){
			dp[i]+=dp[i-2];
		}
		//cout<<"state:"<<dp[i]<<" "<<endl;
	}
	cout<<dp[n]<<endl;
}