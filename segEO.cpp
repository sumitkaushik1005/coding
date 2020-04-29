#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node *next;
};
void insert(struct Node **head,int k){
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=k;
	temp->next=*head;
	*head=temp;
}
void print(struct Node *head){
	struct Node* temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
void segEO(struct Node **head_ref){
	struct Node *curr=*head_ref;
	struct Node *evenS=NULL,*evenE=NULL,*oddS=NULL,*oddE=NULL;
	while(curr){
		int v=curr->data;
		if(v%2==0){
			if(evenS==NULL){
				evenS=curr;
				evenE=evenS;
			}
			else{
				evenE->next=curr;
				evenE=evenE->next;
			}
		}
		else{
			if(oddS==NULL){
				oddS=curr;
				oddE=oddS;
			}
			else{
				oddE->next=curr;
				oddE=oddE->next;
			}
		}
		curr=curr->next;
	}
	if(evenS==NULL || oddS==NULL){
		return;
	}
	evenE->next=oddS;
	oddE->next=NULL;
	*head_ref=evenS;
}
struct Node *unionF(struct Node *head1,struct Node *head2){
	struct Node *result=NULL;
	while(head1!=NULL && head2!=NULL){
		if(head1->data < head2->data ){
				if(result==NULL){
						result=head1;
				}else{
					struct Node *temp=head1;
					temp->next=result;
					result=temp;	
				}
				head1=head1->next;
		}
		else if(head1->data == head2->data){
				if(result==NULL){
					result=head1;
				}else{
					struct Node *temp=head1;
					temp->next=result;
					result=temp;
				}
				head1=head1->next;
				head2=head2->next;
		}
		else{
				if(result==NULL){
						result=head2;
				}else{
					struct Node *temp=head2;
					temp->next=result;
					result=temp;
				}
				head2=head2->next;
		}
	}
	return result;
}
int main(){
	int n;
	cin>>n;
	struct Node *head1=NULL;
	struct Node *head2=NULL;
	insert(&head1,4);
	insert(&head1,5);
	insert(&head1,1);
	insert(&head1,9);
	insert(&head2,6);
	insert(&head2,2);
	insert(&head2,1);
	insert(&head2,3);
	print(head1);
	//cout<<endl;
	print(head2);
	struct Node *result =unionF(head1,head2);
	cout<<endl;
	print(result);
	//segEO(&head);
	//print(head);
}