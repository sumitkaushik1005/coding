#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *next;
};
void insert(struct Node **head,int k){
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=k;
	temp->next=*head;
	*head=temp;
}
void print(struct Node *head){
	struct Node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int addOne(struct Node *head){
	int carry=1;
	int sum=0;
	while(head){
		sum=carry+head->data;
		carry=sum/10;
		sum=sum%10;
		head->data=sum;
		head=head->next;
	}
	if(carry){
		insert(&head,carry);
	}
}
void rprint(struct Node *head){
	if(head->next!=NULL){
		rprint(head->next);
	}

	cout<<head->data;
	

}
struct Node* add(struct Node *head1,struct Node *head2,int *carry){
	if(head1==NULL){
		return NULL;
	}
	struct Node *result=(struct Node*)malloc(sizeof(struct Node *));
	int sum;
	result->next=add(head1->next,head2->next,carry);
	sum=*carry+head1->data+head2->data;
	*carry=sum/10;
	result->data=sum%10;
	return result;
}
int getSize(struct Node *head){
	struct Node *temp=head;
	int count=0;
	while(temp!=NULL){
		temp=temp->next;
		count++;
	}
	return count;
}
void addCarrytoR(struct Node *head1,struct Node *curr,int *carry,struct Node **result){
	int sum;
	if(head1!=curr){
		addCarrytoR(head1->next,curr,carry,result);
		sum=head1->data+*carry;
		*carry=sum/10;
		sum=sum%10;
		insert(&*result,sum);
	}
}
int main(){
	struct Node *head1=NULL,*head2=NULL;
	insert(&head1,9);
	insert(&head1,1);
	insert(&head1,9);

	insert(&head2,3);
	insert(&head2,7);
	int carry=0;
	int size1=getSize(head1);
	int size2=getSize(head2);
	struct Node *result=NULL;
	if(size1==size2){
		result = add(head1,head2,&carry);
	}else{
		int diff=size1-size2;
		if(size1<size2){
			struct Node *temp=head1;
			head1=head2;
			head2=temp;
		}
		struct Node *curr=head1;
		for(int i=0;i<diff;i++){
			curr=curr->next;
		}
		result = add(curr,head2,&carry);
		addCarrytoR(head1,curr,&carry,&result);

	}
	if(carry){
		insert(&result,carry);	
		}
	print(result);
	
}