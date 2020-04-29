#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node *left,*right;
};
struct Node* insert(int key){
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node*));
	temp->data=key;
	temp->left=temp->right=NULL;
	return temp;
}
void fn1(struct Node *root,struct Node **head){
	if(root==NULL){
		return;
	}
	static struct Node *prev=NULL;
	fn1(root->left,head);
	if(prev==NULL){
		*head=root;
	}
	else{
		root->left=prev;
		prev->right=root;
	}
	prev=root;
	fn1(root->right,head);
}
void inorder(struct Node *root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
struct Node* btToDllUtil(struct Node* root){
	if(root==NULL){
		return root;
	}
	if(root->left!=NULL){
		struct Node *left=btToDllUtil(root->left);
			
		for(;left->right!=NULL; left=left->right);

		left->right=root;
		root->left=left;

	}
	if(root->right!=NULL){
		struct Node *right=btToDllUtil(root->right);
		
		for(;right->left!=NULL; right=right->left);

		right->left=root;
		root->right=right;

	}
	return root;
}
struct Node* fn2(struct Node* root){
	struct Node *head=btToDllUtil(root);
	while(head->left!=NULL){
		head=head->left;
	}
	return head;
}
void print(int *a,int i ){
	for(int j=0;j<i;j++){
		cout<<a[j]<<" ";
	}
}
void fn3(struct Node *root,int *a,int i){
	if(root==NULL){
		return;
	}
	a[i]=root->data;
	i++;
	if(root->left==NULL && root->right==NULL){
		print(a,i);
		cout<<endl;
	}
	else{
		fn3(root->left,a,i);
	fn3(root->right,a,i);
	}
	
}
void fn4(struct Node *root){
	if(root==NULL){
		return ;
	}
	if(root->left==NULL && root->right==NULL){
		return ;
	}
	if(root->left!=NULL && root->right==NULL){
		cout<<root->left->data<<" ";
		fn4(root->left);
	}
	if(root->right!=NULL &&root->left==NULL){
		cout<<root->right->data<<" ";
		fn4(root->right);
	}

		fn4(root->left);
		fn4(root->right);
	
	
}
int fn5(struct Node *root,int *res){
	if(root==NULL){
		return INT_MAX;
	}
	if(root->left==NULL && root->right==NULL){
		return root->data;
	}
	int value=min(fn5(root->left,res),fn5(root->right,res));
	*res=max(*res,root->data-value);
	return min(root->data,value);

}
int main(){
	struct Node *root=NULL;
	root=insert(8);
	root->left=insert(3);
	root->right=insert(10);
	root->left->right=insert(6);
	root->right->right=insert(14);
	root->left->right->right=insert(1);
	root->left->right->left=insert(2);
	//inorder(root);
	/*struct Node *head=NULL;
	fn1(root,&head);
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->right;
	}*/
	/*struct Node *head=fn2(root);
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->right;
	}*/
	//int a[6];
	//int i=0;
	//fn3(root,a,i);
	fn4(root);
	//int res=INT_MIN;
	//fn5(root,&res);
	//cout<<res<<endl;
}
