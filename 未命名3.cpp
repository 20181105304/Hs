#include<stdio.h>
int main()
{
	int n,a[1001],i;
	int p=0,t=0;
	scanf("%d",&n);
	
	for(i=1;i<=n; i++){
		a[i]=1;
	}
	
	if(n!=1){
		for(i=1; i<=n; i++){
			if(a[i]==1){
				p++;
			}
			
			if( p%3==0){
				a[i]=0;
				t++;
				
				if(t==n-1){
					break;
				}
				
			}
			
			if(i==n){
				i=0;
			}
		}
	}
	
	for(i=1;i<=n; i++){
		if(a[i]==1){
			printf("%d",i);
			break;
		}
	}
}
