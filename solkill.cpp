#include<bits/stdc++.h>
using namespace std;
struct Node {
	long long int data;
	struct Node *next;
};
struct Node* newNode(long long int x){
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		/*struct Node *head=newNode(1);
		struct Node *curr=head;
		for(long long int i=2;i<=n;i++){
			struct Node *temp=newNode(i);
			curr->next=temp;
			temp->next=head;
			curr=temp;
		}
		//cout<<curr->data<<endl;
		curr=head;
		do{
			Node *temp=curr->next;
			curr->next=temp->next;
			curr=curr->next;
			free(temp);
		}while(curr->next!=curr);
		cout<<curr->data<<endl;
		*/
		for(int i=2;i<=n;i*=2){
		}

		i=i/2;
		int x=n-i;
		cout<<2*x+1<<endl;
	}
}