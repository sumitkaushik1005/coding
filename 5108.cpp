#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		int i,j;
		cin>>i>>j;
		int k=0;
		int n=0;
		int m=0;
		while((i/2)==(j/2)){
			k++;
			n++;
			m++;
			i=i/2;
			j=j/2;
		}
		while(i!=0){
			n++;
			i=i/2;
		}
		while(j!=0){
			m++;
			j=j/2;
		}
		cout<<n<<" "<<m<<" "<<k<<endl;
	}
}