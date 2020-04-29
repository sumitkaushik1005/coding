#include<bits/stdc++.h>
using namespace std;
#define N 0
#define E 1
#define S 2
#define W 3
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.length();
		int i=0;
		int dir=N;
		int x=0;
		int y=0;
		while(i<n){
			int c=s[i];
			if(c=='R'){
				dir=(dir+1)%4;
			}
			else if(c=='L'){
				dir=(dir+4-1)%4;
			}
			else{
				if(dir==N){
					y++;
				}
				else if(dir==S){
					y--;
				}
				else if(dir==E){
					x++;
				}
				else
					x--;
			}
			i++;
		}
		if(x==0 && y==0){
			cout<<"circular"<<endl;
		}
		else
			cout<<"Not circular"<<endl;
	}
}