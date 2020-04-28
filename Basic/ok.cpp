#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
	node *prev;
};

node* cll(node* head,int data){
	
	node* temp;
	node* p;
	temp=(node *)malloc(sizeof(node));
	if (head==NULL){
		temp->data=data;
		temp->next=NULL;
		head=temp;
	}
	else{
		p=head;
		while(p->next)
			p=p->next;
		temp->data=data;
		p->next=temp;
		temp->prev=p;
		temp->next=NULL;

	}
	return head;

}

node * delete_all(node *head,int value){
	node *p=head;
	
	while(p->next){
		node*temp=(node *)malloc(sizeof(node));
		if(p->next->data==value){
			temp=p->next;
			p->next=temp->next;
			free(temp);
			
		}
		p=p->next;


	}
	
	return head;
}

auto intersection(node* head1,node* head2){
	node* p=head1;
	node* q=head2;
	vector<int>V;
	node* res=(node *)malloc(sizeof(node));
	while(p){
		while(q){
			if(p->data==q->data){
				V.push_back(p->data);
				break;
			}
		}
	}
	return V;



}



void print(node*head){
	node*p=head;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	
}

node * duplicates(node * head){
	node* res=NULL;
	node *p;
	p=head;
	map<int,int> d;
	bool temp=false;
	vector<int> v;
	while(p){
		temp=false;
		for (auto x:v){
			if (x==p->data){
				temp=true;
				d[x]++;
			}
		}
		if(!temp){
			v.push_back(p->data);
		}
		
		p=p->next;
	}
	for(auto j:v){
		res=cll(res,j);
	}
	for(auto i=d.begin();i!=d.end();i++){
		cout<<"YOu have used "<<i->first<<"-----"<<i->second<<" Times extra\n";
	}
	return res;


}







node* delete_beg(node *head){
	node*temp=(node *)malloc(sizeof(node));
	temp=head;
	head=temp->next;

	free(temp);
	return head;


}

node* Nth(node*head,int n){
	node* p;
	p=head;
	node* temp=(node *)malloc(sizeof(node));
	int c=0;
	while(p){
		p=p->next;
		c++;
	}
	if(n==c){
		return delete_beg(head);
	}
	int len=c-n;
	p=head;

	while(len-1)
	{
		p=p->next;
		len--;

	}
	temp=p->next;
	p->next=temp->next;
	free(temp);
	return head;



}
node* reverse(node *head){
	if(head){
		node* prev=head;
		node* curr=prev->next;
		while(head!=NULL){
			head=head->next;
			curr->next=prev;
			prev=curr;
			curr=head;

		}


		head=prev;

	}
	return head;

}	







node* merge(node * head,node*root){
	node* store=NULL;
	node *temp=(node *)malloc(sizeof(node));
	node *p;
	node* q;
	node *point;
	p=head;
	q=root;
	while(p){
		while(q){
			if(p->data<q->data){
				store=cll(store,p->data);
				break;
			}
			else{
				store=cll(store,q->data);
			}
			q=q->next;
		}
		if(q){
			p=p->next;
		}
		else{
			store=cll(store,p->data);
			p=p->next;
		}

	}
	while(p){
		store=cll(store,p->data);
		p=p->next;
	}
	while(q){
		store=cll(store,q->data);
		q=q->next;
	}
	return store;
		
		
}







int main(){
	node* head1=NULL;
	node * head2=NULL;
	head1=cll(head1,95);
	head1=cll(head1,95);
	head1=cll(head1,120);
	head1=cll(head1,120);
	head2=cll(head2,120);
	head2=cll(head2,800);
	head2=cll(head2,8000);
	head2=cll(head2,8000);
	auto y=intersection(head1,head2);
	for(int x:y){
		cout<<"The points of intersection are "<<x<<endl;
	}
	print(head1);
}