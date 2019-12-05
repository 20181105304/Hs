#include<iostream>
#include<stack>
using namespace std;
stack<char>S;

struct Node{
	char Data;
	struct Node *Left;
	struct Node *Rigth; 
	
};
typedef struct Node* BiTree;

BiTree Creat_BT();
void Zhonxu(BiTree BT);

int main()
{
	BiTree BT = Creat_BT(); 
	Zhonxu(BT);
	cout<<endl;
	while(!S.empty()){
		cout << S.top();
		S.pop();
	}
	
}

BiTree Creat_BT()
{
	BiTree BT = new struct Node();
	char v;
	cin >> v;
	
	if(v != '#'){
		BT->Data=v;
		BT->Left=Creat_BT();
		BT->Rigth=Creat_BT();
	}
	else{
		return NULL;
	}
	
	return BT;
}

void Zhonxu(BiTree BT)
{
	if(BT){
	Zhonxu( BT->Left );
	cout << BT->Data;
	S.push(BT->Data);
	Zhonxu( BT->Rigth );
    }
}
