#include "iostream"
#include "vector"
#include "Windows.h"
#include "string"
#include "stdexcept"
#include "Calculator.h"
using namespace std;

int main()
{
	begin:
	string input;
	try{
		cout<<"************************************************"<<endl;
		cout<<"*             欢迎使用简单计算器               *"<<endl;
		cout<<"*              本计算器目前支持                *"<<endl;
		cout<<"*     + - * / ^ () [] -(单目减)的整数运算      *"<<endl;
		cout<<"*                                              *"<<endl;
		cout<<"************************************************"<<endl;
		cout<<"请输入表达式（输入quit以退出）:"<<endl;
		while(cin>>input&&input!="quit")
		{
			Cal A(input);
			A.run();
			Sleep(2000);
			goto begin;	
		}
		cout<<"感谢使用!"<<endl;
		Sleep(2000);
	}
	catch(int a)
	{
		if(a==1)
		cout<<endl<<"ERROR: 发现除数为0！"<<endl;
		else if(a==2)
		cout<<endl<<"ERROR: 输入语法有误,检测到错误字符"<<endl;
		else if(a==3)
		cout<<endl<<"ERROR: 输入语法有误，运算符不匹配"<<endl;
		
		Sleep(2000);
		goto begin;
	}
	catch(out_of_range& ERR)
	{
		cout<<endl<<"ERROR:输入数据过大超出计算范围"<<endl;
		
		Sleep(2000);
		goto begin;
	}
	
	
}

