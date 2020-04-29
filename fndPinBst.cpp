#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node *left,*right;
};
Node* newNode(struct Node *root,int key){
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=key;
	temp->left=temp->right=NULL;
	return temp;
}
Node* insert(struct Node *root,int key){
	if(root==NULL){
		return newNode(root,key);
	}
	if(root->data<key){
		root->right=insert(root->right,key);
	}
	if(root->data>key){
		root->left=insert(root->left,key);
	}
	return root;
}
void inorder(struct Node *root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
bool fn(struct Node* root,int sum,unordered_set<int> &s){
	if(root==NULL){
		return false;
	}
	if(fn(root->left,sum,s)){
		return true;
	}
	if(s.find(sum-root->data)!=s.end()){
		cout<<sum-root->data<<" "<<root->data<<endl;
		return true;
	}
	else{
		s.insert(root->data);
	}
	return fn(root->right,sum,s);
}
void fndPair(struct Node* root,int sum){
	unordered_set<int> s;
	fn(root,sum,s);
}
int minV(struct Node *root){
	if(root==NULL){
		return -1;
	}
	if(root->left==NULL){
		return root->data;
	}
	else
		return minV(root->left);
}
int fn(struct Node *root){
	if(root==NULL){
		return 0;
	}
	queue<struct Node*> q;
	q.push(root);
	int level=0;
	int even=0,odd=0;
	while(!q.empty()){
		int size=q.size();
		struct Node *temp=q.front();
		q.pop();
		while(size--){
			if(level%2==0){
				even+=temp->data;
			}
			else{
				odd+=temp->data;
			}
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
		level++;
	}
	cout<<even-odd<<endl;
}
void leftView(struct Node *root){
	queue<struct Node *> q;
	cout<<root->data<<" ";
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		struct Node * temp=q.front();
		q.pop();
		if(temp==NULL){
			if(q.empty()){
				break;
			}
			if(!q.empty()){
				q.push(NULL);
			}
			struct Node *temp2=q.front();
			cout<<temp2->data;
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
}
void fn2(struct Node *root,map<int,int> *m,int level){
	if(root==NULL){
		return ;
	}
		
			m->insert(make_pair(level,(root->data)));
		
	fn2(root->left,m,level-1);
	fn2(root->right,m,level+1);
}
void topView(struct Node *root){
	map<int,int> m;
	fn2(root,&m,0);
	map<int,int>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
}
int fn1(struct Node *root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return 1;
	}
	int l=fn1(root->left);
	int r=fn1(root->right);
	if(l>r){
		return r+1;
	}
	else
		return l+1;
}
void sLvl(struct Node *root){
	stack<struct Node *> s1;
	stack<struct Node *> s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			struct Node *temp=s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			if(temp->right){
				s2.push(temp->right);
			}
			if(temp->left){
				s2.push(temp->left);
			}
		}
		while(!s2.empty()){
			struct Node *temp=s2.top();
			s2.pop();
			cout<<temp->data<<" ";
			if(temp->left){
				s1.push(temp->left);
			}
			if(temp->right){
				s1.push(temp->right);
			}
		}
	}

}
void fnS(struct Node *root,int sum){
	if(root==NULL){
		return ;
	}
	sum+=root->data;
	if(root->left==NULL && root->right==NULL){
		cout<<sum<<" ";
	}
	if(root->left){
		fnS(root->left,sum);
	}
	if(root->right){
		fnS(root->right,sum);
	}
}
void maxSumFn(struct Node *root,int sum,int *maxSum){
	if(root==NULL){
		return ;
	}
	sum+=root->data;
	if(root->left==NULL && root->right==NULL){
		if(*maxSum < sum){
			*maxSum=sum;
		}
		
	}
	maxSumFn(root->left,sum,maxSum);
	maxSumFn(root->right,sum,maxSum);
}
int main(){
	struct Node *root=NULL;
	root=insert(root,6);
	root=insert(root,8);
	root=insert(root,4);
	root=insert(root,3);
	root=insert(root,5);
	//root=insert(root,7);
	root=insert(root,9);
	//inorder(root);
	//fndPair(root,3);
	//cout<<minV(root)<<endl;
	//fn(root);
	//leftView(root);
	//topView(root);
	//int ans=fn1(root);
	//cout<<ans<<endl;
	//sLvl(root);
	//fnS(root,0);
	int maxSum=0;
	int sum=0;
	maxSumFn(root,sum,&maxSum);
	cout<<maxSum<<endl;
}