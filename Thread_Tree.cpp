#include<bits/stdc++.h>
using namespace std;
class threadnode{
	public:
		int val;
		threadnode *left,*right;
		bool lthread,rthread;
		threadnode():val(0),left(NULL),right(NULL),lthread(0),rthread(0){}
};
void plant(threadnode *tree);
void InThread(threadnode *tree,threadnode **pre);
void InsertLeft(threadnode *tree,threadnode* p);
void InsertRight(threadnode *tree,threadnode* p);
threadnode* FirstInOrder(threadnode *tree);
threadnode* FirstInOrder(threadnode *tree);
threadnode* LastInOrder(threadnode *tree);
threadnode* PreviousInOrder(threadnode *tree);
threadnode* NextInOrder(threadnode *tree);
void InOrder(threadnode *tree);
void RevInOrder(threadnode *tree);
int main(){
	threadnode *tree=new threadnode,*p=NULL,*will_be_insert_p,**pre;
	pre=&p;
	cout<<"input root:";
	cin>>tree->val;
	plant(tree);
	InThread(tree,pre);
	(*pre)->right=NULL;
	(*pre)->rthread=1;
}
void plant(threadnode *tree){
	int l,r;
	cout<<"input "<<tree->val<<" left:";
	cin>>l;
	if(l!=0){
		tree->left=new threadnode;
		tree->left->val=l;
		plant(tree->left);
		cout<<"left back to:"<<tree->val<<endl;
	}
	cout<<"input "<<tree->val<<" right:";
	cin>>r;
	if(r!=0){
		tree->right=new threadnode;
		tree->right->val=r;
		plant(tree->right);
		cout<<"right back to:"<<tree->val<<endl;
	}
}
void InThread(threadnode *tree,threadnode **pre){
	if(tree!=NULL){
		InThread(tree->left,pre);
		if(!tree->left){
			tree->left=*pre;
			tree->lthread=1;
		}
		if(*pre&&!(*pre)->right){
			(*pre)->right=tree;
			(*pre)->rthread=1;
		}
		*pre=tree;
		InThread(tree->right,pre);
	}
}
void InsertLeft(threadnode *tree,threadnode* p){
	p->left=tree->left;
	p->lthread=tree->lthread;
	p->right=tree;
	p->rthread=1;
	tree->left=p;
	tree->lthread=0;
	if(!p->lthread){
		threadnode *q=p->left;
		q=LastInOrder(q);
		q->right=p;
	}	
}
void InsertRight(threadnode *tree,threadnode* p){
	p->right=tree->right;
	p->rthread=tree->rthread;
	p->left=tree;
	p->lthread=1;
	tree->right=p;
	tree->rthread=0;
	if(!p->rthread){
		threadnode *q=p->right;
		q=FirstInOrder(q);
		q->left=p;
	}	
}
threadnode* FirstInOrder(threadnode *tree){
	while(!tree->lthread) tree=tree->left;
	return tree;
}
threadnode* LastInOrder(threadnode *tree){
	while(!tree->rthread) tree=tree->right;
	return tree;
}
threadnode* PreviousInOrder(threadnode *tree){
	if(tree->lthread) return tree->left;
	tree=tree->left;
	while(!tree->rthread) tree=tree->right;
	return tree;
}
threadnode* NextInOrder(threadnode *tree){
	if(tree->rthread) return tree->right;
	tree=tree->right;
	while(!tree->lthread) tree=tree->left;
	return tree;
}
void InOrder(threadnode *tree){
	threadnode *p=FirstInOrder(tree);
	while(p!=NULL){
		cout<<p->val;
		p=NextInOrder(p);
	}
}
void RevInOrder(threadnode *tree){
	threadnode *p=LastInOrder(tree);
	while(p!=NULL){
		cout<<p->val;
		p=PreviousInOrder(p);
	}
}
