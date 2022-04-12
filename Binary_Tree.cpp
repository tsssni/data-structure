#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int val;
		node *left,*right;
		node():val(0),left(NULL),right(NULL){}
};
void plant(node *tree){
	int l,r;
	cout<<"input "<<tree->val<<" left:";
	cin>>l;
	if(l!=0){
		tree->left=new node;
		tree->left->val=l;
		plant(tree->left);
		cout<<"left back to:"<<tree->val<<endl;
	}
	cout<<"input "<<tree->val<<" right:";
	cin>>r;
	if(r!=0){
		tree->right=new node;
		tree->right->val=r;
		plant(tree->right);
		cout<<"right back to:"<<tree->val<<endl;
	}
}
void PreOrder(node *tree){
	if(tree==NULL) return;
	cout<<tree->val<<" ";
	PreOrder(tree->left);
	PreOrder(tree->right);
}
void InOrder(node *tree){
	if(tree==NULL) return;
	InOrder(tree->left);
	cout<<tree->val<<" ";
	InOrder(tree->right);
}
void NorePreOrder(node *tree){
	stack<node*> s;
	node *p=tree;
	while(1){
		while(p!=NULL){
			cout<<p->val<<" ";
			s.push(p);
			p=p->left;
		}
		if(s.empty()) return;
		p=s.top();
		s.pop();
		p=p->right;
	}
}
void NoreInOrder(node *tree){
	stack<node*> s;
	node *p=tree;
	while(1){
		while(p!=NULL){
			s.push(p);
			p=p->left;
		}
		if(s.empty()) return;
		p=s.top();
		s.pop();
		cout<<p->val<<" ";
		p=p->right;
	}
}
void PostOrder(node* tree){
	if(tree==NULL) return;
	PostOrder(tree->left);
	PostOrder(tree->right);
	cout<<tree->val<<" ";
}
void NorePostOrder(node* tree){
	stack<pair<node*,int> > s;
	pair<node*,int> p;
	s.push(make_pair(tree,0));
	while(!s.empty()){
		p=s.top();
		s.pop();
		if(p.second==0){
			s.push(make_pair(p.first,1));
			if(p.first->left!=NULL) s.push(make_pair(p.first->left,0));
		}
		else if(p.second==1){
			s.push(make_pair(p.first,2));
			if(p.first->right!=NULL) s.push(make_pair(p.first->right,0));
		}
		else if(p.second==2) cout<<p.first->val<<" ";
	}
}
void LevelOrder(node *tree){
	queue<node*> q;
	node *p;
	q.push(tree);
	while(!q.empty()){
		p=q.front();
		q.pop();
		cout<<p->val<<" ";
		if(p->left!=NULL) q.push(p->left);
		if(p->right!=NULL) q.push(p->right);
	}
}
int n=0;
bool CreateBinTree(string s,node *tree){
	bool b;
	if(n>=s.length()||s[n]=='0'){
		delete tree;
		return false;
	}
	tree->val=s[n]-'0';
	n++;tree->left=new node;b=CreateBinTree(s,tree->left);
	if(!b) tree->left=NULL;
	n++;tree->right=new node;b=CreateBinTree(s,tree->right);
	if(!b) tree->right=NULL;
	return true;
}
void CopyTree(node *tree,node *p){
	node *l,*r;
	if(tree==NULL){
		p=NULL;
		return;
	}
	CopyTree(r->left,l);
	CopyTree(r->right,r);
	p=new node;
	p->val=tree->val;
	p->left=l;p->right=r;
}
node* Father(node *tree,int num){
	node *p=NULL;
	if(tree==NULL||num==0) return NULL;
	if((tree->left!=NULL&&tree->left->val==num)||(tree->right!=NULL&&tree->right->val==num)){
		return tree;
	}
	p=Father(tree->left,num);
	if(p!=NULL) return p;
	p=Father(tree->right,num);
	return p;
}
node* FindNode(node *tree,int num){
	node *p=NULL;
	if(tree==NULL||num==0) return NULL;
	if(tree->val==num){
		p=tree;
		return p;
	}
	p=FindNode(tree->left,num);
	if(p!=NULL) return p;
	p=FindNode(tree->right,num);
	return p;
}
void InsertLL(node *p,node *s){
	if(p==NULL||s==NULL) return;
	s->left=p->left;
	p->left=s;
}
void DeleteTree(node *tree){
	if(tree==NULL) return;
	DeleteTree(tree->left);
	DeleteTree(tree->right);
	delete tree;
}
void DeleteSubTree(node *tree,int num){
	node *f=Father(tree,num);
	if(f==NULL){
		cout<<"Can't Be Deleted!";
		return;
	}
	node *p;
	if(f->left->val==num){
		p=f->left;
		f->left=NULL;
	}
	else if(f->right->val==num){
		p=f->right;
		f->right=NULL;
	}
	DeleteTree(p);
	
}
int main(){
	node *tree=new node,*tree1;
	string s;
	cin>>s;
	CreateBinTree(s,tree);
	DeleteSubTree(tree,2);
	NorePreOrder(tree);
	return 0;
}
