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
		cout<<"*             ��ӭʹ�ü򵥼�����               *"<<endl;
		cout<<"*              ��������Ŀǰ֧��                *"<<endl;
		cout<<"*     + - * / ^ () [] -(��Ŀ��)����������      *"<<endl;
		cout<<"*                                              *"<<endl;
		cout<<"************************************************"<<endl;
		cout<<"��������ʽ������quit���˳���:"<<endl;
		while(cin>>input&&input!="quit")
		{
			Cal A(input);
			A.run();
			Sleep(2000);
			goto begin;	
		}
		cout<<"��лʹ��!"<<endl;
		Sleep(2000);
	}
	catch(int a)
	{
		if(a==1)
		cout<<endl<<"ERROR: ���ֳ���Ϊ0��"<<endl;
		else if(a==2)
		cout<<endl<<"ERROR: �����﷨����,��⵽�����ַ�"<<endl;
		else if(a==3)
		cout<<endl<<"ERROR: �����﷨�����������ƥ��"<<endl;
		
		Sleep(2000);
		goto begin;
	}
	catch(out_of_range& ERR)
	{
		cout<<endl<<"ERROR:�������ݹ��󳬳����㷶Χ"<<endl;
		
		Sleep(2000);
		goto begin;
	}
	
	
}

