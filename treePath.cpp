#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};
struct Node *pred=NULL;
vector<int> ans;
bool flag=false;
struct Node* insert(int d){
	struct Node *curr=(struct Node*)malloc(sizeof(struct Node));
	curr->data=d;
	curr->left=NULL;
	curr->right=NULL;
	return curr;
}
/*void inorder(struct Node *root,int v){
	if(root==NULL){
		return;
	}
	if(root->data==v){
		flag=true;
	}
	inorder(root->left,v);
	if(flag){
		cout<<root->data<<" ";
		flag=false;
	}
	
	inorder(root->right,v);
}
void  print(vector<int> ans){
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
void path(struct Node *root){
	if(root==NULL){
		return;
	}
	ans.push_back(root->data);
	if(root->left==NULL && root->right==NULL){
		print(ans);
	}
	path(root->left);
	path(root->right);
	ans.pop_back();


}
struct Node *mirror(struct Node *root){
	if(root==NULL){
		return root;
	}
	if(root->left==NULL && root->right==NULL){
		return root;
	}
	struct Node *left=mirror(root->left);
	struct Node *right=mirror(root->right);
	struct Node *temp=left;
	root->left=right;
	root->right=temp;
	return root;
}*/
void inorder(Node *root){
	if(root==NULL){
		return ;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	return;
}
int height(Node *root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return 0;
	}
	int l=height(root->left);
	int r=height(root->right);
	if(l>r){
		return l+1;
	}
	else
		return r+1;
}
Node *mirror(Node *root){
	if(root==NULL){
		return NULL;
	}
	if(root->left==NULL && root->right==NULL){
		return root;
	}
	Node *l=mirror(root->left);
	Node *r=mirror(root->right);
	root->left=r;
	root->right=l;
	return root;
}
Node *leavesToDLL(Node *root,Node **head){
	if(root==NULL){
		return NULL;
	}
	if(root->left==NULL && root->right==NULL){
		root->right=(*head);
		if((*head)!=NULL){
			(*head)->left=root;
		}
		*head=root;
		return NULL;

	}
	root->right=leavesToDLL(root->right,head);
	root->left=leavesToDLL(root->left,head);
	return root;
}
void treeToDLL(Node *root,Node **head){
	static Node *prev=NULL;
	if(root==NULL){
		return ;
	}
	treeToDLL(root->left,head);
	if(prev==NULL){
		*head=root;
	}
	else{
		root->left=prev;
		prev->right=root;
	}
	prev=root;
	treeToDLL(root->right,head);
}
Node *removeHN(Node *root){
	if(root==NULL){
		return NULL;
	}
	root->left=removeHN(root->left);
	root->right=removeHN(root->right);
	if(root->left==NULL && root->right==NULL){
		return root;
	}
	if(root->left==NULL){
		struct Node *new_node=root->right;
		free(root);
		return new_node;
	}
	if(root->right==NULL){
		struct Node *new_node=root->left;
		free(root);
		return new_node;
	}
	return root;
}
void maxNodeLevel(Node *root){
	queue<Node *> q;
	int a[1001];
	q.push(root);
	int ans;
	int level_no;
	int level=0;	
	while(1){
	int s=q.size();
	if(s==0)
		break;
	if(s>ans){
		ans=s;
		level_no=level;
	}
	int tempSum=0;
	while(s>0){
		Node *curr=q.front();
		tempSum+=curr->data;
		q.pop();
		if(curr->left)
			q.push(curr->left);
		if(curr->right)
			q.push(curr->right);
		s--;
	}
	a[level]=tempSum;
	level++;
	}
	cout<<"Number of nodes presents "<<ans<<" at "<<level_no<<" level"<<endl;
	for(int i=0;i<level;i++){
		cout<<a[i]<<" ";
	}
	
}
void fn(Node *root){
	if(root==NULL){
		return ;
	}
	if(root->left!=NULL && root->right!=NULL){
		fn(root->left);
		fn(root->right);
	}
	else if(root->left != NULL){
		cout<<root->left->data<<" ";
		fn(root->left);
	}
	else if(root->right!=NULL){
		cout<<root->right->data<<" ";
		fn(root->right);
	}

}
int main(){
	struct Node *root=NULL;
	root=insert(1);
	root->left=insert(2);
	root->right=insert(4);
	root->left->left=insert(5);
	root->left->right=insert(6);
	root->left->right->left=insert(9);
	root->right->right=insert(8);
	inorder(root);
	cout<<endl;
	//cout<<height(root)<<endl;
	//root=mirror(root);
	//inorder(root);
	//struct Node *head_ref=NULL;
	//leavesToDLL(root,&head_ref);
	/*treeToDLL(root,&head_ref);
	Node *curr=head_ref;
	while(curr!=NULL){
		cout<<curr->data<<" ";
		curr=curr->right;
	}*/
	//struct Node *new_root=removeHN(root);
	//inorder(new_root);
	//	path(root);
	//struct Node *mirror_root=mirror(root);
	//inorder(mirror_root);
	//inorder(root,1);
	//maxNodeLevel(root);
	fn(root);
}