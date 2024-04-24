#include<iostream>
#include<stack>
#include<queue>
using namespace std;
typedef char ElemType;
typedef struct Btree{
	ElemType data;
	Btree *lchild,*rchild;
}Btree ,*Bt;
void init(Bt &bt)
{
	bt=NULL;
}
void preCreate(Bt &bt)//递归 
{
	ElemType ch;
	cin>>ch;
	if(ch=='#')
	bt=NULL;
	else
	{
		bt=new Btree;
		bt->data=ch;
		preCreate(bt->lchild);
		preCreate(bt->rchild);
	}
	
}
void preorder(Bt bt)
{
	if(bt)
	{   cout<<bt->data<<' ';
		preorder(bt->lchild);
		preorder(bt->rchild);
	}
}
void postorder(Bt bt)
{
	if(bt)
	{   
		preorder(bt->lchild);
		preorder(bt->rchild);
		cout<<bt->data<<' ';
	}
}
void inorder(Bt bt)
{
	if(bt)
	{  
		preorder(bt->lchild);
		 cout<<bt->data<<' ';
		preorder(bt->rchild);
	}
}
int leaf(Bt bt)//寻找叶子结点个数 
{
	if(!bt)
	return 0;
	if(bt->lchild==NULL&&bt->rchild==NULL)
	return 1;
	return leaf(bt->lchild)+leaf(bt->rchild);
}
void leaf1(Bt bt,int &cnt)
{
	if(bt)
	{
		if(bt->lchild==NULL&&bt->rchild==NULL)
		cnt++;
		leaf1(bt->lchild,cnt);
		leaf1(bt->rchild,cnt);
	 } 
} 
int height(Bt bt)//二叉树高度 
{
	if(!bt)
	return 0;
	int lh=height(bt->lchild);
	int rh=height(bt->rchild);
	return (lh>=rh?lh:rh)+1;
}
void height1(Bt bt,int &h,int tmp)
{
	if(bt)
	{
		if(h<tmp) h=tmp;
		height1(bt->lchild,h,tmp+1);
		height1(bt->rchild,h,tmp+1);
	}
}
typedef struct 
{
	Btree *ptr;
	int task;
}selemType;//用栈实现非递归先，中，后序； 
void predisp(Bt bt) 
{
		stack<selemType> s;
		selemType e;
		Btree *p;
		if(bt)
		{
			e.ptr=bt;e.task=0;s.push(e);
		 } 
		 while(!s.empty())
		 {
		 	e=s.top();s.pop();
		 	p=e.ptr;
		 	if(e.task==1) cout<<p->data<<' ';
		 	else
		 	{
		 		if(p->rchild)
		 		{
		 			e.ptr=p->rchild;e.task=0;s.push(e);
		 			
				 }
				 if(p->lchild)
		 		{
		 			e.ptr=p->lchild;e.task=0;s.push(e);
		 			
				 }
				 e.ptr=p;e.task=1;s.push(e);
			 }
		 }
}
void indisp(Bt bt) 
{
		stack<selemType> s;
		selemType e;
		Btree *p;
		if(bt)
		{
			e.ptr=bt;e.task=0;s.push(e);
		 } 
		 while(!s.empty())
		 {
		 	e=s.top();s.pop();
		 	p=e.ptr;
		 	if(e.task==1) cout<<p->data<<' ';
		 	else
		 	{
		 		if(p->rchild)
		 		{
		 			e.ptr=p->rchild;e.task=0;s.push(e);
		 			
				 }
				 e.ptr=p;e.task=1;s.push(e);
				 if(p->lchild)
		 		{
		 			e.ptr=p->lchild;e.task=0;s.push(e);
		 			
				 }
				 
			 }
		 }
}
void predisp1(Bt bt)
{
	stack<Btree *> s;
	Btree *p=bt;
	while(!s.empty()||p)
	{
		if(p)
		{
			cout<<p->data<<' ';
			s.push(p);
			p=p->lchild;
		}
		else
		{
			p=s.top();
			s.pop();
			p=p->rchild;
			
		}
		
	}
}
void indisp1(Bt bt)
{
	stack<Btree *> s;
	Btree *p=bt;
	while(!s.empty()||p)
	{
		if(p)
		{
			s.push(p);
			p=p->lchild;
		}
		else
		{
			p=s.top();s.pop();
			cout<<p->data<<' ';
			p=p->rchild;
			
		}
	}
}
void postdisp(Bt bt)
{
	stack<Btree *> s;
	Btree *p=bt,*pre=NULL;
	while(!s.empty()||p)
	{
		if(p)
		{
			s.push(p);
			p=p->lchild;
		}
		else
		{
			p=s.top();
			if(p->rchild==NULL||pre==p->rchild)
			{
				s.pop();
				cout<<p->data<<' ';
				pre=p;
				p=NULL; 
			}
			else
			{
				p=p->rchild;
			}
		}
	}
}
void levelorder(Bt bt)//层次遍历 
{
	queue<Btree *> q;
	Btree *p=bt;
	if(p) q.push(p);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		cout<<p->data<<' ';
		if(p->lchild)
		q.push(p->lchild);
		if(p->rchild)
		q.push(p->rchild);
	}
}
int main()
{
	Btree *bt;
	init(bt);
	preCreate(bt);
	preorder(bt);
	cout<<'\n';
	predisp(bt);
	cout<<'\n';
	predisp1(bt);
	cout<<'\n';
	inorder(bt);
	cout<<'\n';
	indisp(bt);
	cout<<'\n';
	indisp1(bt);
	cout<<'\n';
	postorder(bt);
	cout<<'\n';
	postdisp(bt);
	cout<<'\n';
	levelorder(bt);
	cout<<'\n';
    cout<<height(bt);
	cout<<'\n';
	cout<<leaf(bt)<<'\n';
	return 0;
 } 
