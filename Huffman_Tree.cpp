#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;
struct node{
	int val;
	node *left,*right;
};
int n;
node* heap[100005]; 
void build(){
	for(int i=n/2;i>=1;i--){
		int parent=i,son=2*i;
		node *temp;
		while(son<=n){
			if(son<n&&heap[son]->val>heap[son+1]->val)
				son++;
			if(heap[parent]->val<heap[son]->val)
				break;
			else{
				temp=heap[son];
				heap[son]=heap[parent];
				heap[parent]=temp;
				parent=son;
				son=son*2;
			}
		}
	}
}
node* top(){
	int parent,son;
	node *min=heap[1],*temp;
	heap[1]=heap[n--];
	parent=1;son=2;
	while(son<=n){
		if(son<n&&heap[son]->val>heap[son+1]->val)
			son++;
		if(heap[parent]->val<=heap[son]->val)
			break;
		else{
			temp=heap[son];
			heap[son]=heap[parent];
			heap[parent]=temp;
		}
		parent=son;
		son*=2;
	}
	return min;
}
void insert(node *p){
	int son=n+1;
	node *temp;
	n++;
	heap[son]=p;
	for(int pr=n/2;pr>=1;pr/=2,son=pr){
		if(heap[pr]->val>=heap[son]->val){
			temp=heap[son];
			heap[son]=heap[pr];
			heap[pr]=temp;
		}
		else break;
	}
}
void LevelOrder(){
	int flag=0;
	node *p=heap[1];
	queue<node*> q;
	q.push(p);
	while(!q.empty()){
		p=q.front();
		q.pop();
		if(!flag){
			printf("%d",p->val);
			flag=1;
		}
		else printf(" %d",p->val);
		if(p->right->right) q.push(p->right);
		if(p->left->left) q.push(p->left);
	}
}
int main(){
	int sum=0;
	node *l,*r,*newp;
	scanf("%d",&n);
	if(n==0){
		printf("%d",0);
		return 0;
	}
	for(int i=1;i<=n;i++){
		heap[i]=(node*)malloc(sizeof(node));
		scanf("%d",&heap[i]->val);
		heap[i]->left=heap[i]->right=NULL;
	}
	build();
	while(n>1){
		l=top();
		r=top();
		newp=(node*)malloc(sizeof(node));
		newp->left=l;
		newp->right=r;
		newp->val=l->val+r->val;
		sum+=newp->val;
		insert(newp);
	}
	printf("%d\n",sum);
	LevelOrder();
	return 0;
}

