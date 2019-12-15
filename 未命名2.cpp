#include<iostream>
#include<queue>
using namespace std;
int g[10001][10001],v,e,x,y,i;
int bfs(int z)
{
    int i,vis[10001]={0};
    int last=z;//��¼ÿ������һ��Ԫ�أ��ò�ѹ��֮�󵯳�֮ǰ���£�last=temp��
    int tail;//���ڼ�¼ÿ��ѹ��ʱ�Ľ��
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
        if(last==z)     //һ��ȫ��������׼����ʼ����һ�㣺������(x)=��ǰ�����һ��Ԫ��(last) 
        {
            level++;
            last=tail;  //һ��ȫ��ѹ����󣬸���last
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
