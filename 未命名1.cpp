#include<stdio.h>

int G[1005][1005];

int BFS(int x, int n){
	int Visit[1005]={0},i=0,j=0,k;
	int num,count=1,l=0,temp,last,a[1005];
	
	last = x;
	Visit[x]=1;
	a[i++]=x;
	
	while(i>j) {
		num = a[j++];
		
		for(k=1; k<=n; k++){
			if(Visit[k]==0 && G[num][k]==1){
				Visit[k]=1;
				a[i++]=k;
				count++;
				temp=k;
			}
		}
		
		if(last == num){
			l++;
			last=temp;
		}
		
		if(l==6){
			break;
		}
		
	}
	
	return count;
}

int main()
{
	int n,m,a,b,i;
	scanf("%d %d",&n,&m);
	
	for(i=1; i<=m; i++){
		scanf("%d %d",&a,&b);
		G[a][b]=G[b][a]=1;
	}
	
	for(i=1; i<=n; i++){
		double z=BFS(i,n);
		printf("%d: %.2lf%%\n",i,z/n*100);
	}
	
} 
