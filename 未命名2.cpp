#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;//����д�����Ȼsort���׳��쳣
struct excel{
 char id[11];//����ѧ����ѧ��
 char name[13];//����ѧ�������֣������ַ�����
 int grades;//�ɼ���0-100������int�ͱ�ʾ
};
struct excel strl[100005];//��������Ĵ�С
/*����ǰ���id��������Ϊʲô����������ע���أ���Ϊ��ϲ����^.^��*/
bool sortById(struct excel one,struct excel two){
 return strcmp(one.id,two.id)<0;
}
/*����ǰ���name��������*/
bool sortByName(struct excel one,struct excel two){
 if(strcmp(one.name,two.name)==0){//����������һ����ʱ��
  return strcmp(one.id,two.id)<0;//����id���յ�������
 }
 else return strcmp(one.name,two.name)<0;//���ذ�����������
}
/*����ǰ��ճɼ���������Ϊʲô�а��ճɼ����������������Ī�������ˣ�������������!!����*/
bool sortByGrades(struct excel one,struct excel two){
  if(one.grades==two.grades){//�������ɼ�һ����ʱ��
  return strcmp(one.id,two.id)<0;//����id���յ�������
 }
  else return one.grades<two.grades;//���ذ��ճɼ�����
}
int main(){
 
 
 int num=6,j=0;//����һ��������¼ѧ�ŵļ�����
 int n,c;//����һ��������Ŷ����е�n����һ������ָ������ʲô�����c
 scanf("%d%d",&n,&c);
 int i=0;//�������ǵ������Ѽ�����i����ʼ��0
 if(n==0){
 return 0;//û���з���0
 }
 while(n--){//y��������ѧ�ţ����֣��ͳ�? ? ? ? scanf("%s %s %d",&strl[i].id,&strl[i].name,&strl[i].grades);
 scanf("%s %s %d",&strl[i].id,&strl[i].name,&strl[i].grades);
 i++;//��������һ
 }
 n=i;//��n�ָ���ԭ�������ӣ�������仰�����������Ӧ����ħ��Сӣ����������������
switch(c){//������switch���㲻ϲ���Ļ����Լ�����if��䣬�����Ҿ�����������ܰ�����ô��
 case 1:sort(strl,strl+n,sortById);//�����Ҳ���ô��������������ֱ����sort
break;
case 2:sort(strl,strl+n,sortByName);
break;
 case 3:sort(strl,strl+n,sortByGrades);
 break;
 default:
 break;
 }
 i=0;//�������ٴθ�ֵΪ0
 n--;//���һ�������л��з�
 while(n--){
 printf("%s %s %d\n",strl[i].id,strl[i].name,strl[i].grades);//��ӡ���
 i++;//��������һ
 }
 printf("%s %s %d",strl[i].id,strl[i].name,strl[i].grades);//��ӡ���һ��û�л��з�������
 return 0;
}
