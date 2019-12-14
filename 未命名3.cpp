#include<stdio.h>
#define MAX 30005
int f[MAX]={0};
int getf(int v){
    if(f[v]==v)
    return v;
    else
    f[v]=getf(f[v]);
    return f[v];
}
void merge(int v,int u){
    int t1=getf(v);
    int t2=getf(u);
    if(t1!=t2);
    f[t2]=t1;
    return;
}
int main(void){
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    for(int i = 1; i <= n; ++i){
        f[i]=i;
    }
    for(int i = 1;i <= m; ++i){
        int p,p1,p2;
        scanf("%d",&p);
        scanf("%d",&p1);
        p -= 1;
        while(p>0){
            scanf("%d",&p2);
            merge(p1,p2);
            p--;
        }
    }
        int temp[MAX]={0};
        int max=-1;
        int t;
        for(int i = 1; i <= n; ++i){
            t=getf(i);
            temp[t]++;
            if(max<temp[t])
                max=temp[t];
        }
        printf("%d\n",max);
        return 0; 
    
} 
