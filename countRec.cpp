#include<bits/stdc++.h>
using namespace std;
struct Point{
	int x;
	int y;
};
int main(){
	int n;
	cin>>n;
	struct Point points[n];
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		points[i].x=a;
		points[i].y=b;
	}
	map<pair<int,int>,int> count;
	int ans=0;
	for(Point p:points){
		for(Point above_p:points){
			if(p.x==above_p.x && p.y<above_p.y){
				//cout<<p.x<<" "<<above_p.x;
				pair<int,int> temp=make_pair(p.y,above_p.y);
				cout<<temp.first<<" "<<temp.second;
				ans+=count[temp];
				count[temp]+=1;
			}
		}
	}
	cout<<endl;
	cout<<ans;
}