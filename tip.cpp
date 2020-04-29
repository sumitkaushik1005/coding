#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> &p1,pair<int,int> &p2){
	int d1=abs(p1.first-p1.second);
	int d2=abs(p2.first-p2.second);
	if(d1>d2){
		return false; 
	}
	else
		return true;
}
int main(){
	int n,X,Y;
	cin>>n>>X>>Y;
	int andyT[n],bobT[n];
	for(int i=0;i<n;i++){
		cin>>andyT[i];
	}
	for(int j=0;j<n;j++){
		cin>>bobT[j];
	}

	vector<pair<int,int>> orders;
	for(int i=0;i<n;i++){
		orders.push_back(make_pair(andyT[i],bobT[i]));
	}
	sort(orders.begin(),orders.end(),cmp);
	/*for(int i=0;i<n;i++){
		cout<<orders[i].first<<" "<<orders[i].second<<endl;
	}*/
	int andyOrder=0;
	int bobOrder=0;
	int tipmoney=0;
	for(int i=0;i<n;i++){
		if(orders[i].first > orders[i].second){
			if(1+andyOrder<=X){
				tipmoney+=orders[i].first;
				andyOrder++;
			}
			else{
				tipmoney+=orders[i].second;
				bobOrder++;
			}
		}
		else{
			if(1+bobOrder<=Y){
				tipmoney+=orders[i].second;
				bobOrder++;
			}
			else{
				tipmoney+=orders[i].first;
				andyOrder++;
			}
			}
		//cout<<tipmoney<<" ";
	}
	cout<<tipmoney<<endl;
}