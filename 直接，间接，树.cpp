#include <stdio.h>
#include <malloc.h>

 void swap(int x,int y)
 {
 	int t;
 	t=x;
 	x=y;
 	y=t;
 }
 void swap1(int *x,int *y)
 {
 	int *t;
 	t=x;
 	x=y;
 	y=t;
 }
 void swap2(int *x,int *y)
 {
 	int t;
 	t=*x;
 	*x=*y;
 	*y=t;
 }
 
 void swap3(int &x,int &y)
 {
 	int t;
 	t=x;
 	x=y;
 	y=t;
 }

typedef struct Node
  {
    int data;
    struct Node * LChild;
    struct Node * RChild;
  }
  BiTNode, *BiTree;
  
  void CreateBiTree(BiTree *bt)
{ 
   int ch;
   scanf("%d",&ch);
   if(ch==0) 
     *bt=NULL;
   else
    {
      *bt=(BiTree)malloc(sizeof(BiTNode));
      (*bt)->data=ch;
      CreateBiTree(&((*bt)->LChild));
      CreateBiTree(&((*bt)->RChild));
    }
} 

  BiTree InsertBiTree(BiTree bt,int e)
{ 
   //BiTree f,p;
   BiTNode *s,*f,*p;
   s=(BiTNode*)malloc(sizeof(BiTNode));
   s->data=e;
   s->LChild=NULL;
   s->RChild=NULL;
   if(bt==NULL)
     {
     	return s;
	 }
   f=NULL;
   p=bt;
   while(p!=NULL)
     {
     	f=p;
     	if(p->data>e)
     	  p=p->LChild;
     	else
     	  p=p->RChild;
	 }
   if(f->data>e)
     f->LChild=s;
   else
     f->RChild=s;	 
   return bt;
}  

  

void PrintTree(BiTree bt, int nLayer)  /* 按竖向树状打印的二叉树 */
{
  if(bt ==NULL) 
    return;
  PrintTree(bt ->RChild,  nLayer+1);
  for(int i=0;i<nLayer;i++)
  {
     printf("   ");  
  }
  printf("%d\n",bt->data);
    
  PrintTree(bt ->LChild ,  nLayer+1);
} 


  	int pathdata[100];
  	int pathlevel[100];
 

int main()
{
    struct Node BiTNode,*bt;
    bt=NULL;
    
    bt=InsertBiTree(bt,47);
    PrintTree(bt, 1);
    bt=InsertBiTree(bt,12);
    bt=InsertBiTree(bt,17);
    bt=InsertBiTree(bt,8);
    bt=InsertBiTree(bt,6);
	bt=InsertBiTree(bt,28);
	bt=InsertBiTree(bt,25);
    bt=InsertBiTree(bt,56);
	bt=InsertBiTree(bt,89);
    printf(" \n InsertBiTree(&bt,47)\n");
    PrintTree(bt, 1);
    InsertBiTree(bt,101);
    printf("\n InsertBiTree(&bt,101) \n");
    PrintTree(bt, 1);
    
  /*  
    int i=3,j=5;
    printf("1    i=%d  j=%d\n",i,j);
    swap(i,j);
    printf("2    i=%d  j=%d\n",i,j);
    swap1(&i,&j);
    printf("3    i=%d  j=%d\n",i,j);
    swap2(&i,&j);
    printf("4    i=%d  j=%d\n",i,j);
    swap3(i,j);
    printf("4    i=%d  j=%d\n",i,j);
   */
    return 0;
}

