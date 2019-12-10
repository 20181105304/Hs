#include<stdio.h>
#include<queue>
#include<malloc.h>
#include <math.h>
using namespace std;

typedef struct Node *Position;
typedef Position BiTree;
struct Node{
	int Data;
	BiTree Left;
	BiTree Right;
};
queue<BiTree>q;


BiTree CreatTree()  // 先序创树
{
	BiTree T;
	int num;
	scanf("%d",&num);
	
	if(num == 0){
		T = NULL;
	}
	else{
		T = (BiTree)malloc(sizeof(BiTree));
		T->Data=num;
		
		T->Left = CreatTree();
		T->Right = CreatTree();
	}
	
	return T;
}

void ZhongTree( BiTree BT )   // 中序遍历
{
	if(BT){
		ZhongTree( BT->Left );
		printf("%d ",BT->Data);
		ZhongTree( BT->Right );
	}
} 

void xianTree( BiTree BT )     // 先序遍历
{
	if(BT){
		printf("%d ",BT->Data);
		xianTree( BT->Left );
		xianTree( BT->Right );
	}
 } 

void houTree( BiTree BT )      // 后序遍历
{
	if(BT){
		houTree( BT->Left );
		houTree( BT->Right );
		printf("%d ",BT->Data);
	}
	
 } 

void CenTree( BiTree BT )      // 层序遍历
{
	BiTree T;
	
	if(BT){
		q.push(BT);
		while(!q.empty()){
			T = q.front();
			q.pop();
			printf("%d ",T->Data);
			
			if( T->Left )  q.push( T->Left );
			if( T->Right )  q.push( T->Right );
		}
		
	}

} 

int  HeighTree(BiTree BT)     // 求树高度
{
	int LH,RH,max;
	
	if(BT){
		LH = HeighTree( BT->Left );
		RH = HeighTree( BT->Right );
		
		max = LH > RH? LH:RH;
		return max+1;
	}
	else return 0;
} 
int temp = -1;
bool NYTree( BiTree BT)      //是否二叉搜索树
{
	
	if(BT == NULL){
		return true;
	}
	NYTree ( BT->Left );
	if(BT->Data<temp){
		return false;
	}
	else{
		temp=BT->Data;
	}
	NYTree ( BT->Right );
	
	return true;

	
	
} 

BiTree FindMax(BiTree BT)    // 求二叉搜索树中最大值
{
	if(BT)  {
		while(BT->Right){
		   BT = BT->Right;
	    }
	    return BT;
	}
	
	
	return NULL;
} 
BiTree FindMin(BiTree BT)    // 求二叉搜索树中最小值 
{
	if(!BT->Left){
		return BT;
	}
	else{
		FindMin( BT->Left );
	}
	
} 

BiTree CharuTree(BiTree BT, int X)   // 二叉搜索树插入操作
{
	if(!BT){
		BT = (BiTree)malloc(sizeof(BiTree));
		BT->Data = X;
		BT->Left=BT->Right=NULL;
	}
	else{
		if(X < BT->Data){
			BT->Left = CharuTree( BT->Left ,  X);
		}
		
		if(X > BT->Data){
			BT->Right = CharuTree( BT->Right , X);
		}
	}
	return BT;
} 

BiTree Find(BiTree BT, int X)       // 二叉搜索树查找操作 
{
	if(!BT){
		printf("查找失败！");
		return NULL; 
	}
	else{
		if(X < BT->Data){
			return Find( BT->Left, X);
		}
		else if(X > BT->Data){
			return Find(BT->Right, X);
		}
		else{
			return BT;
		}
	}
}

BiTree Delete(BiTree BT, int X)     // 二叉搜索树删除操作 
{
	BiTree T;
	if(!BT){
		printf("未找到要删除元素！"); 
		return NULL; 
	}
	else{
		
		if(X < BT->Data){
			BT->Left = Delete(BT->Left, X);
		}
		else if(X > BT->Data){
			BT->Right = Delete(BT->Right, X);
		}
		else{
			if(BT->Left && BT->Right){
				T = FindMin(BT->Right);
				BT->Data = T->Data;
				
				BT->Right = Delete(BT->Right, BT->Data);
			}
			
			else{
				T = BT;
				if(!BT->Left){
					BT = BT->Right;
				}
				else{
					BT=BT->Left;
					free(T);
				}
			}
		}
		
	}
	return BT;
}
 

int main()
{
	BiTree BT = CreatTree();     //1 2 3 4 0 0 0 5 0 0 6 0 7 9 0 0 8 0 0   //8 6 5 0 0 7 0 0 10 9 0 0 11 0 0
	printf("树创建成功，请选择需要的操作：\n");
	
	printf("\n  1.中序遍历  2.先序遍历\n  3.后序遍历  4.层序遍历\n  5.求树的高度  6.是否二叉搜索树\n  7.求二叉搜索树中最大值  8.求二叉搜索树中最小值\n  9.将X插入二叉搜索树中  10.在二叉搜索树中查找X\n  11.在二叉搜索树中删除X");
	printf("  12.退出\n");
	printf("\n 请输入序号："); 
	
	int num;
	scanf("%d",&num);
	
	switch (num){
	  case 1:
		printf("中序遍历结果为：");
	    ZhongTree( BT );
	    break;
	  
	  case 2:
	  	printf("先序遍历结果为：");
	    xianTree( BT );
	    break;
	    
	  case 3:
	  	printf("后序遍历结果为：");
	    houTree( BT );
	    break;
	    
	  case 4:
	  	printf("层序遍历结果为：");
	    CenTree( BT );
	    break;
	    
	  case 5:
	  	
	  	int H ;
		H = HeighTree(BT);
	  	if(H){
	  		printf("树高为：%d\n",H);
		  }
		else{
		  	printf("空树\n");
		  }
		break; 
		
	  case 6:
	  	bool st;
		st  = NYTree( BT );
	  	if(st == true){
	  		printf("是二叉搜素树\n");
	  		
		  }
		else{
			printf("不是二叉搜素树\n"); 
		}
	    break;
		 
	  case 7:
	  	BiTree max;
	  	max = FindMax(BT);
	  	if(max){
	  		printf("树中最大值为：%d\n",max->Data);
		  }
		else{
			printf("空树\n");
		}
	  	break;
	  	
	  case 8:
	  	BiTree min;
	  	min = FindMin(BT);
	  	if(min){
	  		printf("树中最小值为：%d\n",min->Data);
		  }
		else{
			printf("空树\n");
		}
	  	break;
	  	
	  case 9:
	  	int X;
	  	printf("请输入要插入的数："); 
	  	scanf("%d",&X);
	  	BT = CharuTree( BT, X);
	  	
	  	printf("插入X后先序遍历结果为：");
		xianTree(BT); 
	  	
	  	break;
	  	
	  case 10:
	  	int x;
	  	BiTree T;
	  	printf("请输入要查找的数：");
		scanf("%d",&x);
		T = Find( BT, x);
		
		printf("查找结果为：%d",T->Data);
	  	break;
	  	
	  case 11:
	  	int num;
	  	printf("请输入要删除的数：");
		scanf("%d",&num);
		Delete(BT, num);
		printf("删除X后先序序列为：");
		xianTree(BT); 
	  	break;
	  
	  default:
	  break;	    
	
	}
	
	return 0;
} 
