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

void BFS(int x, int n)
{
	int a[15],i=0,j=0,k,num;
	Visit[x]=1;
	a[i++]=x;
	
	while(i>j){
		num = a[j++];
		printf(" %d",num);
		for(k=0; k<n; k++){
			if(Visit[k]==0 && G[num][k]==1){
				Visit[k]=1;
				a[i++]=k;
			}
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
	
	for(i=0; i<n; i++){
		Visit[i]=0;
	}
	
	for(i=0; i<n; i++){
		if(Visit[i]==0){
			printf("{");
			BFS(i,n);
			printf(" }\n");
		}
	}
	return 0;
}
