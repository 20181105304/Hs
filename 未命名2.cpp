#include<iostream>
#include<queue>
using namespace std;
int g[10001][10001],v,e,x,y,i;
int bfs(int z)
{
    int i,vis[10001]={0};
    int last=z;//记录每层的最后一个元素：该层压入之后弹出之前更新：last=temp；
    int tail;//用于记录每层压入时的结点
    int level=0;
    int count=1;
    queue<int>q;
    q.push(z);
    vis[z]=1;
    while(!q.empty())
    {
        z=q.front();
        q.pop();
        for(i=1;i<=v;i++)
        {
            if(g[z][i]==1 && vis[i]==0)
            {
                count++;
                vis[i]=1;
                q.push(i);
                tail=i;
            }
        }
        if(last==z)     //一层全部弹出，准备开始弹下一层：弹出的(x)=当前层最后一个元素(last) 
        {
            level++;
            last=tail;  //一层全都压入完后，更新last
        }
        if(level==6) break;
    }
    return count;
}
int main()
{
    cin>>v>>e;
    while(e--)
    {
        cin>>x>>y;
        g[x][y]=g[y][x]=1;
    }
    for(i=1;i<=v;i++)
    {
        double n=v;
        double m=bfs(i);
        printf("%d: %.2f%%\n",i,m/n*100);
    }
    return 0;
}
