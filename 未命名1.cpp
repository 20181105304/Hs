#include <stdio.h>

//typedef enum {false, true} bool;
#define MaxVertexNum 10   /* ��󶥵�����Ϊ10 */
typedef int Vertex;       /* �ö����±��ʾ����,Ϊ���� */

/* �ڽӵ�Ķ��� */
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;        /* �ڽӵ��±� */
    PtrToAdjVNode Next; /* ָ����һ���ڽӵ��ָ�� */
};

/* �����ͷ���Ķ��� */
typedef struct Vnode{
    PtrToAdjVNode FirstEdge; /* �߱�ͷָ�� */
} AdjList[MaxVertexNum];     /* AdjList���ڽӱ����� */

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;     /* ������ */
    int Ne;     /* ����   */
    AdjList G;  /* �ڽӱ� */
};
typedef PtrToGNode LGraph; /* ���ڽӱ�ʽ�洢��ͼ���� */

bool Visited[MaxVertexNum]; /* ����ķ��ʱ�� */

LGraph CreateGraph(); /* ����ͼ���ҽ�Visited��ʼ��Ϊfalse������ʵ�֣�ϸ�ڲ��� */

void Visit( Vertex V )
{
    printf(" %d", V);
}

void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) );

int main()
{
    LGraph G;
    Vertex S;

    G = CreateGraph();
    scanf("%d", &S);
    printf("BFS from %d:", S);
    BFS(G, S, Visit);

    return 0;
}


void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
	
	int a[100],i=0,j=0;
	Vertex s;
	PtrToAdjVNode p;
	
	Visit(S);
	Visited[S] = true;
	
	a[i++] = S;
	
	while(i>j){
		p = Graph->G[a[j++]].FirstEdge;
		
		while(p){
			s = p->AdjV;
			if(!Visited[s]){
				Visit(s);
	            Visited[s] = true;
	            a[i++] = s;
			}
			p = p->Next;
		}
	}	
}
