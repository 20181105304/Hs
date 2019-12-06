#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;//必须写这个不然sort会抛出异常
struct excel{
 char id[11];//定义学生的学号
 char name[13];//定义学生的名字，按照字符串型
 int grades;//成绩是0-100所以用int型表示
};
struct excel strl[100005];//定义数组的大小
/*这个是按照id进行排序，为什么我这次用这个注释呢！因为我喜欢（^.^）*/
bool sortById(struct excel one,struct excel two){
 return strcmp(one.id,two.id)<0;
}
/*这个是按照name进行排序*/
bool sortByName(struct excel one,struct excel two){
 if(strcmp(one.name,two.name)==0){//到两个名字一样的时候
  return strcmp(one.id,two.id)<0;//返回id按照的是升序
 }
 else return strcmp(one.name,two.name)<0;//返回按照名字升序
}
/*这个是按照成绩进行排序（为什么有按照成绩排序这个东西啊！莫名的忧伤（宝宝不开心了!!））*/
bool sortByGrades(struct excel one,struct excel two){
  if(one.grades==two.grades){//到两个成绩一样的时候
  return strcmp(one.id,two.id)<0;//返回id按照的是升序
 }
  else return one.grades<two.grades;//返回按照成绩升序
}
int main(){
 
 
 int num=6,j=0;//定义一个用来记录学号的计数器
 int n,c;//定义一个用来存放多少行的n，和一个用来指定按照什么排序的c
 scanf("%d%d",&n,&c);
 int i=0;//定义我们的老朋友计数器i，初始化0
 if(n==0){
 return 0;//没有行返回0
 }
 while(n--){//y依次输入学号，名字，和成? ? ? ? scanf("%s %s %d",&strl[i].id,&strl[i].name,&strl[i].grades);
 scanf("%s %s %d",&strl[i].id,&strl[i].name,&strl[i].grades);
 i++;//计数器加一
 }
 n=i;//让n恢复成原来的样子，好像这句话在哪里见过，应该是魔法小樱。。。。。。。。
switch(c){//这里用switch，你不喜欢的话就自己换成if语句，反正我就用这个，你能把我怎么滴
 case 1:sort(strl,strl+n,sortById);//由于我不怎么会快排所以这里就直接用sort
break;
case 2:sort(strl,strl+n,sortByName);
break;
 case 3:sort(strl,strl+n,sortByGrades);
 break;
 default:
 break;
 }
 i=0;//计数器再次赋值为0
 n--;//最后一个不能有换行符
 while(n--){
 printf("%s %s %d\n",strl[i].id,strl[i].name,strl[i].grades);//打印输出
 i++;//计数器加一
 }
 printf("%s %s %d",strl[i].id,strl[i].name,strl[i].grades);//打印最后一个没有换行符的数据
 return 0;
}
