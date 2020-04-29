#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	list<int> dq[n];
	int total_card=0;
	for(int i=0;i<n;i++){
		int s;
		cin>>s;
		total_card+=s;
		list<int> input;
		for(int i=0;i<s;i++){
			int x;
			cin>>x;
			input.push_back(x);
		}
		dq[i]=input;
	}
	int c=0;
	int j=0;
	cout<<total_card<<endl;
	while(total_card){
		
		int maxV1=INT_MIN;
		int index1=-1;
		for(int i=0;i<n;i++){
			list<int> temp=dq[i];
			if(temp.empty())
				continue;
			if(temp.front()>maxV1){
				maxV1=temp.front();
				index1=i;
			}
		}
		if(index1==-1){
			break;
		}
		//cout<<maxV<<endl;
		c+=maxV1;
		
		dq[index1].pop_front();
		//Y=Y.pop_front();
		//dq[index1]=Y;
		total_card--;
		int maxV2=INT_MIN;
		int index2=-1;
		for(int i=0;i<n;i++){
			list<int> temp=dq[i];
			if(temp.empty())
				continue;
			if(temp.back()>maxV2){
				maxV2=temp.back();
				index2=i;
			}
		}
		if(index2==-1)
			break;
		j+=maxV2;
		cout<<"index2 is "<<index2<<endl;
		
		dq[index2].pop_back();
		//X=X.pop_back();
		//dq[index2]=X;
		total_card--;
		cout<<c<<" "<<j<<endl;
	}
	cout<<c<<j<<endl;
}