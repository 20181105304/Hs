#include<stdio.h>

typedef struct Node{
	int Data;
	struct BiTrre *Left;
	struct BiTree *Right;
}BiTrre;

void CreatTrre( BiTrre BT );  //先序创树 
void ZhongTree( BiTrre BT );  //中序遍历
void xianTree( BiTrre BT );   //先序遍历
void houTree( BiTrre BT );    //后序遍历
void CenTrre( BiTrre BT );    //层序遍历
 

int main()
{
	
} 
