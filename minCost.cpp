#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	priority_queue<int, vector<int> ,greater<int> > pq;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		pq.push(temp);
	}
	int cost=0;
	while(pq.size() > 1){
		int first=pq.top();
		pq.pop();
		int second=pq.top();
		pq.pop();
		cost+=(first+second);
		pq.push(first+second);
	}
	cout<<cost<<endl;
}