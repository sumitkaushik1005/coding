#include<bits/stdc++.h>
using namespace std;
int myComparator(string X,string Y){
	string XY=X.append(Y);
	string YX=Y.append(X);
	return XY.compare(YX)>0?1:0;
}
void printLargest(vector<string> arr){
	sort(arr.begin(),arr.end(),myComparator);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i];
	}
}
int main(){
	vector<string> arr;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		arr.push_back(s);
	}
	printLargest(arr);
}