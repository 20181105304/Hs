#include<stdio.h>  
  
#define inf 0xffffff  
  
int map[1005][1005],dis[1005],pre[1005];  
//map��������룬dis��δ����㵽�������룬pre��õ�ĸ����  
int i,j,n,m,x,y,z;  
  
void prim(){  
    for(i=1;i<=n;i++){  
        dis[i]=map[1][i];  
        pre[i]=-1; 
    }  
    dis[1]=0;  
    pre[1]=0;  
    int sum=0,flag,minn;  
    for(i=2;i<=n;i++){ 
        minn=inf;
        for(j=1;j<=n;j++){
            if(pre[j]==-1&&dis[j]<minn){
                flag=j;
                minn=dis[j];
            }
        }  
            pre[flag] = i;
            sum+=minn;
            for(j=1;j<=n;j++){
                if(pre[j]==-1&&dis[j]>map[flag][j])  
                //����δ����㵽����������̾���   
                dis[j]=map[flag][j];  
            }  
    }  
    if(sum>inf||sum<0) printf("-1\n");  //������ڲ���ͨ�ĵ㣬sum>inf ||sum<0(�ӷ�Խ��)  
    else printf("%d\n",sum);  
}   
  
int main(){  
    scanf("%d%d",&n,&m);
    for(i=0;i<1005;i++)  
    for(j=0;j<1005;j++)  
        map[i][j]=inf;  
    for(i=1;i<=m;i++){  
        scanf("%d%d%d",&x,&y,&z); 
		if(map[x][y]>z)  
        map[x][y]=map[y][x]=z;    
    }  
    prim();  
    return 0;  
}  
