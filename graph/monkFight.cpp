#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long int data;
	Node *left,*right;
};
struct Node* new_node(int k){
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=k;
	temp->left=temp->right=NULL;
	return temp;
}
struct Node* insert(struct Node *root,int k){
	if(root==NULL){
		return new_node(k);
	}
	if(k>root->data){
		root->right=insert(root->right,k);
	}
	else{
		root->left=insert(root->left,k);
	}
	return root;
}
void inorder(struct Node *root,int *count){
	if(root==NULL){
		return;
	}
	inorder(root->left,count);
	(*count)++;
	inorder(root->right,count);
}
int height(struct Node *root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return 1;
	}
	int l=height(root->left);
	int r=height(root->right);
	if(l>r){
		return l+1;
	}
	else
		return r+1;
}
bool find(struct Node *root,int key){
	if(root==NULL){
		return false;
	}
	if(root->data==key){
		return true;
	}
	if(root->data < key){
		return find(root->right,key);
	}
	else
		return find(root->left,key);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		struct Node *root=NULL;
	int n,X;
	cin>>n>>X;
	for(int i=0;i<n;i++){
		long long int x;
		cin>>x;
		if(!find(root,x))
			root=insert(root,x);
	}
	int count=0;
	inorder(root,&count);
	if(count==X){
		cout<<"Good"<<endl;
	}
	else if(count<X){
		cout<<"Bad"<<endl;
	}
	else
		cout<<"Average"<<endl;
	}
	
	/*int ans=height(root);
	cout<<ans<<endl;*/
	//inorder(root);
}