#include<bits/stdc++.h>
using namespace std;
struct Point{
	int x;
	int y;
};
int main(){
	int t;
	cin>>t;
	struct Point p[4];
	while(t--){
		for(int i=0;i<4;i++){
			int a,b;
			cin>>a>>b;
			p[i].x=a;
			p[i].y=b;
		}
		int width=min(p[1].x,p[3].x)-max(p[0].x,p[2].x);
		cout<<width<<endl;
		int height=min(p[1].y,p[3].y)-max(p[0].y,p[2].y);
		cout<<height<<endl;
	}
}