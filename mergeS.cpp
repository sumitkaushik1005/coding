#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *next=NULL;
};
struct Node* push(struct Node *head,int key){
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=key;
	temp->next=head;
	head=temp;
	return head;
}
void print(struct Node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
void frontBackSplit(struct Node *source,struct Node **a, struct Node **b){
	struct Node *fast=source->next;
	struct Node *slow=source;
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			slow=slow->next;
			fast=fast->next;
		}
	}
	*a=source;
	*b=slow->next;
	slow->next=NULL;

}
struct Node* sortedMerge(struct Node *a,struct Node *b){
	struct Node *result=NULL;
	if(a==NULL){
		return b;
	}
	else if(b==NULL){
		return a;
	}
	if(a->data <= b->data){
		result=a;
		result->next=sortedMerge(a->next,b);
	}
	else{
		result=b;
		result->next=sortedMerge(a,b->next);
	}
	return result;
}
void mergeSort(struct Node **head){
	struct Node *head_ref=*head;
	struct Node *a,*b;
	if(head_ref==NULL || head_ref->next==NULL){
		return;
	}
	frontBackSplit(head_ref,&a,&b);
	//cout<<a->data<<" "<<b->data<<" ";
	mergeSort(&a);
	mergeSort(&b);
	*head = sortedMerge(a,b);
}
Node* reverse(Node *head){
	Node *curr=head;
	Node *prev=NULL;
	Node *next;
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}
bool isEven(int d){
	return d%2;
}
void absSorting(Node **head){
	Node *prev=(*head);
	Node *curr=(*head)->next;
	while(curr!=NULL){
		if(isEven(curr->data)){
		prev->next=curr->next;
		curr->next=*head;
		*head=curr;
		curr=prev;
	}
	else{
		prev=curr;
	}
	curr=curr->next;
	}
	
	
}
int main(){
	struct Node *head=NULL;
	head=push(head,1);
	head=push(head,2);
	head=push(head,3);
	head=push(head,4);
	head=push(head,7);
	head=push(head,9);
	head=push(head,10);
	head=reverse(head);
	absSorting(&head);
	//mergeSort(&head);
	//mergeSort(&head);

	print(head);
}