#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *next;
};
int fn(int n){
	if(n==1){
		return 1;
	}
	Node *last=(Node *)malloc(sizeof(struct Node));
	last->data=1;
	last->next=last;
	for(int i=2;i<=n;i++){
		Node *temp=(Node *)malloc(sizeof(struct Node));
		temp->data=i;
		temp->next=last->next;
		last->next=temp;
		last=temp;
	}
	Node *curr=last->next;
	Node *temp;
	while(curr->next!=curr){
		temp=curr->next;
		curr->next=temp->next;
		curr=curr->next;
		free(temp);

	}
	int res=curr->data;
	free(curr);
	return res;

}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
	int ans=fn(n);
	cout<<ans<<endl;
	}
	
}