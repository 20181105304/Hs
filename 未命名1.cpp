#include<stdio.h>
#define INF 99999
int G[1005][1005];
int pre[1005],dist[1005];


void Prim(int n)
{
	int i,j,flag,min,sum=0;
	
	for(i=1; i<=n; i++){
		dist[i] = G[1][i];
		pre[i] = -1;
	}
	
	dist[1]=0;
	pre[1]=0;
	
	for(i=1; i<=n; i++){
		min=INF;
		for(j=1; j<=n; j++){
			if(pre[j]==-1 && dist[j]<min){
			    flag=j;
			    min=dist[j];
		    }
		}
		
		pre[flag] = i;
		sum+=min;
		
		for(j=1; j<=n; j++){
			if(pre[j]==-1 && dist[j]>G[flag][j])
				dist[j]=G[flag][j];
			
		}
		
		
	}
	
	if(sum>INF || sum<0){
		printf("-1\n");
	}
	else{
		printf("%d\n",sum);
	}
	
}

int main()
{
	int n,m,i,j,a,b,w;
	scanf("%d %d",&n,&m);
	
	for(i=0; i<=n; i++){
		for(j=0; j<=n; j++){
			G[i][j]=INF;
		}
	}
	
	for(i=1; i<=m; i++){
		scanf("%d %d %d",&a,&b,&w);
//		if(G[a][b]>w){
			G[a][b]=G[b][a]=w;
//		}
		
	}
	Prim(n);
	
	return 0;
}
