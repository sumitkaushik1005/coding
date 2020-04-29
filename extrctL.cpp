#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *left=NULL,*right=NULL;
};
struct Node *newNode(int k){
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=k;
	return temp;
}
void inorder(struct Node *root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
struct Node* extractL(struct Node *root,struct Node **head_ref){
	if(root==NULL){
		return NULL;
	}
	if(root->left==NULL && root->right==NULL){
		root->right=*head_ref;
		if((*head_ref)!=NULL){
			(*head_ref)->left=root;
		}
		*head_ref=root;
		return NULL;
		
	}
		root->right=extractL(root->right,head_ref);	
		root->left=extractL(root->left,head_ref);	
		return root;
	
	
}
void btToDll(struct Node *root,struct Node **head_ref){
	if(root==NULL){
		return;
	}
	btToDll(root->right,head_ref);
	root->right=*head_ref;
	if(*head_ref!=NULL){
		(*head_ref)->left=root;
	}
	*head_ref=root;
	btToDll(root->left,head_ref);
}
int h(struct Node *root){
	queue<struct Node*> q;
	q.push(root);
	q.push(NULL);
	int height=0;
	while(!q.empty()){
		struct Node *temp=q.front();
		q.pop();
		if(temp==NULL){
			height++;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
	return height;
}
int main(){
	struct Node *root;
	root=newNode(4);
	root->left=newNode(5);
	root->right=newNode(6);
	root->left->left=newNode(16);
	root->left->right=newNode(12);
	
	root->right->right=newNode(25);
	root->left->right->left=newNode(12);
	/*struct Node *head=NULL;
	extractL(root,&head);
	struct Node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
	temp=temp->right;
	}
	cout<<endl;
	inorder(root);

	//cout<<head->data<<" ";*/
	/*struct Node *head=NULL;
	btToDll(root,&head);
	struct Node *temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->right;
	}*/
	cout<<h(root);
}