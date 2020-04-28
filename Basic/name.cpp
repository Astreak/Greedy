#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
node* cll(){
	node *temp;
	temp=(node *)malloc(sizeof(node));
	int data;
	cout<<"ENter the value ";
	cin>>data;
	if(data ==-1000)
		return NULL;
	temp->data=data;
	cout<<"ENTer the lchild of "<<temp->data<<endl;
	temp->lchild=cll();
	cout<<"ENTer the rchild of "<<temp->data<<endl;
	temp->rchild=cll();
	return temp;


}
node *Node(int data){
	node *temp=(node *)malloc(sizeof(node));
	temp->data=data;
	temp->lchild=NULL;
	temp->rchild=NULL;
	return temp;

}

node *bst(node* root){
	
	if(root==NULL){
		int val;
		cout<<"ENTer the root data"<<endl;
		cin>>val;
		root=Node(val);
		
	}
	int data;
	cout<<"Enter the data"<<endl;
	cin>>data;
	if(data=-1000)
		return NULL;
	else{
		if(data<root->data){
			cout<<"ENTER ing in the left child "<<endl;
			root->lchild=bst(root->lchild);
		}
		else{
			cout<<"Entering in right child "<<endl;
			root->rchild=bst(root->rchild);
		}

	}

}











void inorder(node *root){
	if(root){
		inorder(root->lchild);
		cout<<root->data<<endl;
		inorder(root->rchild);
	}

}

void level_order(node *root){
	queue<node *> Q;
	Q.push(root);
	while(!Q.empty()){
		node* curr=Q.front();
		cout<<curr->data<<endl;
		if(curr->lchild){
			Q.push(curr->lchild);
		}
		if(curr->rchild){
			Q.push(curr->rchild);
		}
		Q.pop();

		
	}
}





int main(){
	node *root=NULL;
	root=bst(root);
	level_order(root);
	

}