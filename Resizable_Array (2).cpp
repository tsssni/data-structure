#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		char val;
		node *left,*right;
		node():val(0),left(NULL),right(NULL){}
};
node* CreateExpressionTree(string str){
	node *p;
	stack<node*> s;
	for(int i=0;i<str.length();i++){
		p=new node;
		p->val=str[i];
		if(str[i]>='0'&&str[i]<='9') s.push(p);	
		else{
			p->right=s.top();s.pop();
			p->left=s.top();s.pop();
			s.push(p);
		} 
	}
	return p;
}
void PostOrder(node *tree){
	if(tree==NULL) return;
	PostOrder(tree->left);
	PostOrder(tree->right);
	cout<<tree->val; 
}
int main(){
	node *p;
	string str;
	cin>>str;
	p=CreateExpressionTree(str);
	PostOrder(p);
	return 0;
}

