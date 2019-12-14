#include<stdio.h>
int Visit[15] = {0};
int G[15][15];

void DFS(int x, int n)
{
	int i;
	Visit[x] = 1;
	printf(" %d",x);
	
	for(i=0; i<n; i++){
		if(G[x][i] == 1 && Visit[i] == 0){
			DFS(i, n);
		}
	}
}

int main()
{
	int n,m,i,a,b;
	scanf("%d %d",&n,&m);
	 
	for(i=0; i<m; i++) {
		scanf("%d %d",&a,&b);
		G[a][b] = G[b][a] = 1;
	}
	
	for(i=0; i<n; i++){
		
		if(Visit[i] == 0){
			printf("{");
			DFS(i, n);
			printf("}\n");
		}
	} 
	
}
