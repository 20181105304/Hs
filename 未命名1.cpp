#include<stdio.h>
#include<string.h>

struct node{
	char id[7];
	char name[9];
	int f;
}s[100001],temp;

int main()
{
	int n,c,i,j;
	scanf("%d %d",&n,&c);
	
	for(i=0; i<n; i++){
		scanf("%s %s %d",&s[i].id,&s[i].name,&s[i].f);
	}
	
	if(c==1){
		for(i=0; i<n-1; i++){
			for(j=i+1; j<n; j++){
				if(strcmp(s[i].id , s[j].id) > 0){
					temp=s[i];
					s[i]=s[j];
					s[j]=temp;
				}
			}
		}
	}
	
	if(c==2){
		for(i=0; i<n-1; i++){
			for(j=i+1; j<n; j++){
				if(strcmp(s[i].name , s[j].name) > 0){
					temp=s[i];
					s[i]=s[j];
					s[j]=temp;
				}
				
				if( strcmp(s[i].name , s[j].name) == 0 ){
					if(strcmp(s[i].id , s[j].id) > 0){
						temp=s[i];
					    s[i]=s[j];
					    s[j]=temp;
					}
				}
			}
		}
	}
	
	if(c==3){
		for(i=0; i<n-1; i++){
			for(j=i+1; j<n; j++){
				if(s[i].f > s[j].f){
					temp=s[i];
					s[i]=s[j];
					s[j]=temp;
				}
				
				if( s[i].f == s[j].f ){
					if(strcmp(s[i].id , s[j].id) > 0){
						temp=s[i];
					    s[i]=s[j];
					    s[j]=temp;
					}
				}
			}
		}
	}
	
	for(i=0; i<n; i++){
		printf("%s %s %d\n",s[i].id,s[i].name,s[i].f);
	}
	return 0;
	
}
