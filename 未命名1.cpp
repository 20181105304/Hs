#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct node{
	char id[7];
	char name[9];
	int f;
}s[100001],temp;

bool com1(struct node a, struct node b){  // 比较学号 
	return strcmp(a.id, b.id)<0;
}

bool com2(struct node a, struct node b){  // 比较姓名 
	if(strcmp(a.name, b.name) == 0){
		return strcmp(a.id, b.id)<0;
	} 
	else{
		return strcmp(a.name, b.name)<0;
	}
}

bool com3(struct node a, struct node b){  // 比较成绩 
	if(a.f == b.f){
		return strcmp(a.id, b.id)<0;
	} 
	else{
		return a.f<b.f;
	}
}


int main()
{
	int n,c,i,j;
	scanf("%d %d",&n,&c);
	
	for(i=0; i<n; i++){
		scanf("%s %s %d",&s[i].id,&s[i].name,&s[i].f);
	}
	
	if(c==1){
		sort(s,s+n,com1);
	}
	
	if(c==2){
		sort(s,s+n,com2);
	}
	
	if(c==3){
		sort(s,s+n,com3);
	}
	
	for(i=0; i<n; i++){
		printf("%s %s %d\n",s[i].id,s[i].name,s[i].f);
	}
	return 0;
	
}
