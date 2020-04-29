#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int leaderboard[n];
	for(int i=0;i<n;i++){
		cin>>leaderboard[i];
	}	
	int rank[n];
	for(int i=0;i<n;i++){
		if(i==0){
			rank[i]=1;
		}
		else{
			if(leaderboard[i]==leaderboard[i-1]){
				rank[i]=rank[i-1];
			}
			else{
				rank[i]=rank[i-1]+1;
			}
		}
	}
	int m;
	cin>>m;
	while(m--){
		int score;
		cin>>score;
		int i;
		for( i=0;i<n;i++){
			if(score>=leaderboard[i]){
				cout<<rank[i]<<endl;
				break;
			}
		}
		if(i==n){
			cout<<rank[i-1]+1<<endl;
		}
	}
	
}