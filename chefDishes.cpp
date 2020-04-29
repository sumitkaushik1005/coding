#include<bits/stdc++.h>
using namespace std;
int fndType(string s){
	string arr[]={"FAT","FIBER","CARB"};
	size_t found=s.find(arr[0]);
	if(found!=string::npos){
		return 0;
	}
	found=s.find(arr[1]);
	if(found!=string::npos){
		return 1;
	}
	found=s.find(arr[2]);
	if(found!=string::npos){
		return 2;
	}
	return -1;
	
}
int main(){
	int n;
	cin>>n;
	vector<string> input;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		input.push_back(s);
	}
	int a[3];
	string ans;
	memset(a,0,sizeof(a));
	for(int i=0;i<input.size();i++){
		string in=input[i];
		int index=fndType(in);
		a[index]++;
		if(a[0]+a[1]+a[2]>=3){
			if(a[0]>=2 || a[1]>=2 || a[2]>=2){
				a[index]-=2;
				ans+="1";
				
					if(a[0]==1){
						a[0]--;
					}
					else if(a[1]==1){
						a[1]--;
					}
					else
						a[2]--;
				

			}
			else{
				ans+="0";
			}
		}
		else{
			ans+="0";
		}
	}
	cout<<ans<<endl;

}