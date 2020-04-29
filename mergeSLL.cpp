#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *next;
};
Node *insert(struct Node *h,int k){
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node *));
	temp->data=k;
	temp->next=h;
	h=temp;
	return h; 
}
void print(struct Node *head){
	struct Node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
void split(struct Node *head_ref,struct Node **a,struct Node **b){
	struct Node *slow=head_ref;
	struct Node *fast=slow->next;
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			slow=slow->next;
			fast=fast->next;
		}
	}
	*a=head_ref;
	*b=slow->next;
	slow->next=NULL;
}
struct Node *sortedMerge(struct Node *a,struct Node *b){
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
	struct Node *result;
	if(a->data<b->data){
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
	if(head_ref==NULL || head_ref->next==NULL){
		return;
	}
	struct Node *a;
	struct Node *b;
	split(head_ref,&a,&b);
	mergeSort(&a);
	mergeSort(&b);
	*head=sortedMerge(a,b);
}
int main(){
	struct Node *head=NULL;
	head=insert(head,4);
	head=insert(head,5);
	head=insert(head,1);
	head=insert(head,12);
	head=insert(head,52);

	mergeSort(&head);
		print(head);
}