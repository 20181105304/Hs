#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int number;
	struct node *next;
} Node; 

int main()
{
	Node *head, *list, *p;
	int num,i;
	head=list=NULL;
	scanf("%d",&num);
	
	while(num != 0){
		
		p=(struct node*)malloc(sizeof(struct node));
		p->number=num;
		p->next=NULL;
		
		if(head==NULL){
			head=p;
		}
		else{
			list->next=p;
		}
		list=p;
		scanf("%d",&num);
		
	}
//	���� 
	Node *q;
	q=head;
	while(q != NULL){
		printf("%d ",q->number);
		q=q->next;
	}
	printf("\n");
	
//	�м����4��λ 
 
 
    Node *t,*temp;
	t=(Node*)malloc(sizeof(Node));
	scanf("%d",&t->number);
	temp=head;
	
	for(i=0; i<3; i++){
		if(temp->next!=NULL){
			temp=temp->next;
		}
	} 
	
	t->next=temp->next;
	temp->next=t;
	
	Node *r;
	r=head;
	while(r != NULL){
		printf("%d ",r->number);
		r=r->next;
	}
	
	
	return 0;
	
}


//    ɾ��

    Node *temp1,*z; 













 
 
