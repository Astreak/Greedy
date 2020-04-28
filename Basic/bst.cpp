#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *lchild;
	node *rchild;

};
node * croot(int data){
	node *temp=(node *)malloc(sizeof(node));
	temp->data=data;
	temp->lchild=NULL;
	temp->rchild=NULL;
	return temp;
}
node *insert_bst(node *head,int data){
	if(head==NULL){
		head=croot(data);

	}
	else{
		if(data<=head->data){
			if(head->lchild){
				insert_bst(head->lchild,data);
			}
			else{
				head->lchild=croot(data);
			}
		}
		else{
			if(head->rchild){
				insert_bst(head->rchild,data);
			}
			else{
				head->rchild=croot(data);
			}


		}

	}
	return head;




}

// vector<int> inorder(node *head){
// 	vector<int> v;
// 	if(head){
// 		if(head->lchild)
// 			inorder(head->lchild);
// 		v.push_back(head->data);
// 		if(head->rchild)
// 			inorder(head->rchild);
// 	}
	
// 	return v;
// }

vector<int> inorder(node* head,vector<int>&v){
	if(head){
		if(head->lchild)
			inorder(head->lchild,v);
		v.push_back(head->data);
		if(head->rchild)
			inorder(head->rchild,v);
	}
	return v;
	



}








// void level(node *root){
// 	 // Base Case 
//     if (root == NULL)  return; 
  
//     // Create an empty queue for level order tarversal 
//     queue<node *> q; 
  
//     // Enqueue Root and initialize height 
//     q.push(root); 
  
//     while (q.empty() == false) 
//     { 
//         // Print front of queue and remove it from queue 
//         node *curr = q.front(); 
//         cout << curr->data << " "; 
//         q.pop(); 
  
//         /* Enqueue left child */
//         if (curr->lchild != NULL) 
//             q.push(curr->lchild); 
  
//         /*Enqueue right child */
//         if (curr->rchild != NULL) 
//             q.push(curr->rchild); 
//     } 


// }

void level(node *root){
	int n=0;
	if(root==NULL){
		return;
	}
	queue<node *>Q;
	Q.push(root);
	while(!Q.empty()){
		if(n%2==0){
		node *curr=Q.front();
		cout<<curr->data<<"\t";
		Q.pop();
		if(curr->lchild!=NULL)
			Q.push(curr->lchild);
		if(curr->rchild!=NULL)
			Q.push(curr->rchild);

		}
	
	else{
		node *curr=Q.front();
		cout<<curr->data<<"\t";
		Q.pop();
		if(curr->rchild!=NULL)
			Q.push(curr->rchild);
		if(curr->lchild!=NULL)
			Q.push(curr->lchild);

		}
	n++;
	}
	
}
node * search(node*head,int data){

	if(head){
		if(head->data>data){
			search(head->lchild,data);
		}
		else if(head->data< data){

			search(head->rchild,data);
		}
		else{
			return head;
		}

	}
	else{
		return NULL;
	}




}
int width(node*head){
	if(head){
		int lh=width(head->lchild);
		int rh=width(head->rchild);

		return lh+rh;	

	}
	else{
		return 0;
	}



}


bool check(node*head){
	if(head){
		if(head->lchild!=NULL && head->lchild->data>head->data){
			return true;
		}
		else{
			return check(head->lchild);
		}
		if(head->rchild!=NULL && head->rchild->data<=head->data){
			return true;
		}
		else{
			return check(head->rchild);
		}

		return false;
	}
	else{
		return true;
	}


}









int predecessor(node *head,int data){
	node* temp=(node* )malloc(sizeof(node));
	if(search(head,data)!=NULL){
		temp=search(head,data);
		node *curr=temp->lchild;
		if(curr){

		}
		





	}



}

//kth smallest element
int solution(node *root,int k){
	vector<int> v;
	vector<int> V=inorder(root,v);
	return V[k-1];




}












int  height(node *head){
	if(head==NULL){
		return 0;

	}
	else{
		int lh=height(head->lchild);
		int rh=height(head->rchild);
		if(lh>rh)
			return lh+1;
		else return rh+1;
	}



}
int  code(node *head,int &c){
	if(head){
		if((head->lchild && !head->rchild)||(head->rchild && !head->lchild)){
			c++;
			if(head->lchild)
				code(head->lchild,c);
			else
				code(head->rchild,c);
		}




	}
	return c;
}







int main(){
	node *root=NULL;
	int a[7];
	int c=0;
	for(int i=0;i<7;i++){
		cout<<"Enter the elemnst";
		cin>>a[i];
	}
	for(int x:a){
		root=insert_bst(root,x);

	}
	int j=height(root);
	cout<<j<<endl;
	int data=solution(root,2);
	cout<<data<<"\t";
	cout<<INT_MIN<<endl;
	cout<<check(root)<<endl;
	cout<<code(root,c)<<endl;



	
	

}