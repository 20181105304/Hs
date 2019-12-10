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


BiTree CreatTree()  // ������
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

void ZhongTree( BiTree BT )   // �������
{
	if(BT){
		ZhongTree( BT->Left );
		printf("%d ",BT->Data);
		ZhongTree( BT->Right );
	}
} 

void xianTree( BiTree BT )     // �������
{
	if(BT){
		printf("%d ",BT->Data);
		xianTree( BT->Left );
		xianTree( BT->Right );
	}
 } 

void houTree( BiTree BT )      // �������
{
	if(BT){
		houTree( BT->Left );
		houTree( BT->Right );
		printf("%d ",BT->Data);
	}
	
 } 

void CenTree( BiTree BT )      // �������
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

int  HeighTree(BiTree BT)     // �����߶�
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
bool NYTree( BiTree BT)      //�Ƿ����������
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

BiTree FindMax(BiTree BT)    // ����������������ֵ
{
	if(BT)  {
		while(BT->Right){
		   BT = BT->Right;
	    }
	    return BT;
	}
	
	
	return NULL;
} 
BiTree FindMin(BiTree BT)    // ���������������Сֵ 
{
	if(!BT->Left){
		return BT;
	}
	else{
		FindMin( BT->Left );
	}
	
} 

BiTree CharuTree(BiTree BT, int X)   // �����������������
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

BiTree Find(BiTree BT, int X)       // �������������Ҳ��� 
{
	if(!BT){
		printf("����ʧ�ܣ�");
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

BiTree Delete(BiTree BT, int X)     // ����������ɾ������ 
{
	BiTree T;
	if(!BT){
		printf("δ�ҵ�Ҫɾ��Ԫ�أ�"); 
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
	printf("�������ɹ�����ѡ����Ҫ�Ĳ�����\n");
	
	printf("\n  1.�������  2.�������\n  3.�������  4.�������\n  5.�����ĸ߶�  6.�Ƿ����������\n  7.����������������ֵ  8.���������������Сֵ\n  9.��X���������������  10.�ڶ����������в���X\n  11.�ڶ�����������ɾ��X");
	printf("  12.�˳�\n");
	printf("\n ��������ţ�"); 
	
	int num;
	scanf("%d",&num);
	
	switch (num){
	  case 1:
		printf("����������Ϊ��");
	    ZhongTree( BT );
	    break;
	  
	  case 2:
	  	printf("����������Ϊ��");
	    xianTree( BT );
	    break;
	    
	  case 3:
	  	printf("����������Ϊ��");
	    houTree( BT );
	    break;
	    
	  case 4:
	  	printf("����������Ϊ��");
	    CenTree( BT );
	    break;
	    
	  case 5:
	  	
	  	int H ;
		H = HeighTree(BT);
	  	if(H){
	  		printf("����Ϊ��%d\n",H);
		  }
		else{
		  	printf("����\n");
		  }
		break; 
		
	  case 6:
	  	bool st;
		st  = NYTree( BT );
	  	if(st == true){
	  		printf("�Ƕ���������\n");
	  		
		  }
		else{
			printf("���Ƕ���������\n"); 
		}
	    break;
		 
	  case 7:
	  	BiTree max;
	  	max = FindMax(BT);
	  	if(max){
	  		printf("�������ֵΪ��%d\n",max->Data);
		  }
		else{
			printf("����\n");
		}
	  	break;
	  	
	  case 8:
	  	BiTree min;
	  	min = FindMin(BT);
	  	if(min){
	  		printf("������СֵΪ��%d\n",min->Data);
		  }
		else{
			printf("����\n");
		}
	  	break;
	  	
	  case 9:
	  	int X;
	  	printf("������Ҫ���������"); 
	  	scanf("%d",&X);
	  	BT = CharuTree( BT, X);
	  	
	  	printf("����X������������Ϊ��");
		xianTree(BT); 
	  	
	  	break;
	  	
	  case 10:
	  	int x;
	  	BiTree T;
	  	printf("������Ҫ���ҵ�����");
		scanf("%d",&x);
		T = Find( BT, x);
		
		printf("���ҽ��Ϊ��%d",T->Data);
	  	break;
	  	
	  case 11:
	  	int num;
	  	printf("������Ҫɾ��������");
		scanf("%d",&num);
		Delete(BT, num);
		printf("ɾ��X����������Ϊ��");
		xianTree(BT); 
	  	break;
	  
	  default:
	  break;	    
	
	}
	
	return 0;
} 
