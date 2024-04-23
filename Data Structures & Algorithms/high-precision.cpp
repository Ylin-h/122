/*输入值都为正整数，其中减法只能为大的数减去小的数*/ 
#include<iostream>
#include<cstring>
using namespace std;
const int len=1024;
int str1[len],str2[len],ans[len*2];
void mul(string x,string y)
{
	memset(str1,0,sizeof(str1));
	memset(str2,0,sizeof(str2));
	memset(ans,0,sizeof(ans));
	int xl=x.length();
	int yl=y.length();
	for(int i=0;i<xl;i++)
	{
		str1[i]=x[xl-i-1]-'0';
	}
	for(int i=0;i<yl;i++)
	{
		str2[i]=y[yl-i-1]-'0';
	}
	for(int i=0;i<xl;i++)
	for(int j=0;j<yl;j++)
	{
		ans[i+j]+=str1[i]*str2[j];
	}
	int cl=xl+yl;
	for(int i=0;i<cl;i++)
	{
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
	while(cl>1&&ans[cl-1]==0)
	cl--;
	for(int i=cl-1;i>=0;i--)
	cout<<ans[i];
	cout<<'\n';
}
void add(string x,string y)
{
	memset(str1,0,sizeof(str1));
	memset(str2,0,sizeof(str2));
	memset(ans,0,sizeof(ans));
	int xl=x.length();
	int yl=y.length();
	for(int i=0;i<xl;i++)
	{
		str1[i]=x[xl-i-1]-'0';
	}
	for(int i=0;i<yl;i++)
	{
		str2[i]=y[yl-i-1]-'0';
	}
	int cl=max(xl,yl)+1;
	int t=0;
	for(int i=0;i<cl;i++)
	{
//		ans[i]=str1[i]+str2[i]+t;
//		t=ans[i]/10;
//		ans[i]%=10;
		ans[i+1]+=(str1[i]+str2[i])/10;
		ans[i]+=(str1[i]+str2[i])%10;
	}
	while(cl>1&&ans[cl-1]==0)//去除前置0 
	cl--;
	for(int i=cl-1;i>=0;i--)
	cout<<ans[i];
	cout<<'\n';
}
void sub(string x,string y)
{
	memset(str1,0,sizeof(str1));
	memset(str2,0,sizeof(str2));
	memset(ans,0,sizeof(ans));
	int xl=x.length();
	int yl=y.length();
	for(int i=0;i<xl;i++)
	{
		str1[i]=x[xl-i-1]-'0';
	}
	for(int i=0;i<yl;i++)
	{
		str2[i]=y[yl-i-1]-'0';
	}
	int cl=max(xl,yl);
	int t=0;
	for(int i=0;i<cl;i++)
	{
		ans[i]=str1[i]-str2[i]-t;
		if(ans[i]<0)
		{
		t=1;
		ans[i]+=10;	
		}
		else
		t=0;
	}
	while(cl>1&&ans[cl-1]==0)//去除前置0 
	cl--;
	for(int i=cl-1;i>=0;i--)
	cout<<ans[i];
	cout<<'\n';
}
int main()
{
	int cnt;
	cnt=1;
	while(cnt--)
	{
	  string x,y;
	  cin>>x>>y;
	  mul(x,y);	
	  add(x,y);
	  sub(x,y);
	} 
	return 0;	
}
