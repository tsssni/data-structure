#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *getodd( struct ListNode **L );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);

    return 0;
}
struct ListNode *readlist(){
	int num;
	struct ListNode *head,*last;
	head=last=(struct ListNode *)malloc(sizeof(struct ListNode));
	head->next=NULL;
	scanf("%d",&head->data);
	last=head;
	do{
		scanf("%d",&num);
		if(num!=-1){
			last->next=(struct ListNode *)malloc(sizeof(struct ListNode));
			last->next->data=num;
			last->next->next=NULL;
			last=last->next;
		}
	}while(num!=-1);
	return head;
}
struct ListNode *getodd( struct ListNode **L ){
	struct ListNode *p,*q,*r,*head,*last;
	head=last=NULL;
	for(p=*L;p;p=p->next){
		if((p->data)%2){
			if(!head){
				head=last=(struct ListNode *)malloc(sizeof(struct ListNode));
				head->data=last->data=p->data;
				head->next=last->next=NULL;
			}
			else{
				struct ListNode *o;
				o=(struct ListNode *)malloc(sizeof(struct ListNode));
				o->data=p->data;
				o->next=NULL;
				last->next=(struct ListNode *)malloc(sizeof(struct ListNode));
				last->next=o;
				last=last->next;
			}
		}
	}
	p=*L;
	while(p&&p->data%2){
		r=p;
		p=*L=p->next;
		free(r);
	}
	if(*L){
		do{
			if(p->data%2){
				r=p;
				q->next=p->next;
				p=p->next;
				free(r);
			}
			else{
				q=p;
				p=p->next;
			}
		}while(p);
	}
	return head;
}
