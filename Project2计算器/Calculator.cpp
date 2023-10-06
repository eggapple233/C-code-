#include "iostream"
#include "vector"
#include "string"
#include "cmath"
#include "Calculator.h"

int Cal::priority(char a,char b)//-1��<  0��=   1��>   2��--- 
{
	if(a=='+'||a=='-')
	{
		if(b=='*'||b=='/'||b=='('||b=='^'||b=='@'||b=='[')
		return -1;
		return 1; 
	}
	else if(a=='*'||a=='/')
	{
		if(b=='('||b=='^'||b=='@'||b=='[')
		return -1;
		return 1; 
	}
	else if(a=='(')
	{
		if(b==')')
		return 0;
		else if(b=='#')
		return 2;
		return -1; 
	}
	else if(a==')')
	{
		if(b=='(')
		return 2;
		return 1; 
	}
	else if(a=='[')
	{
		if(b==']')
		return 0;
		else if(b=='#')
		return 2;
		return -1; 
	}
	else if(a==']')
	{
		if(b=='[')
		return 2;
		return 1; 
	}
	else if(a=='#')
	{
		if(b==')')
		return 2;
		else if(b=='#')
		return 0;
		return -1; 
	}
	else if(a=='^')
	{
		if(b=='^'||b=='('||b=='@'||b=='[')
		return -1;
		return 1; 
	}
	else if(a=='@')
	{
		if(b=='('||b=='[')
		return -1;
		return 1; 
	}
}


void Cal::op_push(char b){
	start:
	char a=op.back();
	switch(priority(a,b)){
		case -1:{
			op.push_back(b);
			string temp;
			temp=b;
			if(b!='@')
			mes+=string("�����ջ�ɹ�ѹ��")+=temp+=string("\n");
			else
			mes+=string("�����ջ�ɹ�ѹ��-\n");
			break;
		}
		case 0:{
			op.pop_back();
			string temp;
			temp=a;
			if(a!='@')
			mes+=string("�����ջ�ɹ�����")+=temp+=string("\n");
			else
			mes+=string("�����ջ�ɹ�����-\n");
			break;
		}
		case 1:{
			op.pop_back();
			string temp;
			temp=a;
			string temp2;
			temp2='-';
			
			if(a!='@')
			mes+=string("�����ջ�ɹ�����")+=temp+=string("\n"); 
			else
			mes+=string("�����ջ�ɹ�����")+=temp2+=string("\n"); 
			
			
			double num1=num.back();
			num.pop_back();
			string temp1;
			temp1=to_string(num1);
			mes+=string("������ջ�ɹ�����")+=temp1+=string("\n"); 
			
			double num2=0;
			if(a!='@')
			{
				num2=num.back();
				num.pop_back();
				string temp2;
				temp2=to_string(num2);
				mes+=string("������ջ�ɹ�����")+=temp2+=string("\n"); 
			}
			switch(a)
					{
						case '+':{
							double temp3=num1+num2;
							num.push_back(temp3);
							mes+=string("����")+=to_string(num2)+=string("+")+=to_string(num1)+=string("  ������ջ�ɹ�ѹ��")+=to_string(temp3)+=string("\n"); 
							break;
						}
						case '-':{
							double temp3=num2-num1;
							num.push_back(temp3);
							mes+=string("����")+=to_string(num2)+=string("-")+=to_string(num1)+=string("  ������ջ�ɹ�ѹ��")+=to_string(temp3)+=string("\n"); 
							break;
						}
						case '*':{
							double temp3=num2*num1;
							num.push_back(temp3);
							mes+=string("����")+=to_string(num2)+=string("*")+=to_string(num1)+=string("  ������ջ�ɹ�ѹ��")+=to_string(temp3)+=string("\n"); 
							break;
						}
						case '/':{
							if(num1==0)
							{
								throw(1);
							}
							double temp3=num2/num1;
							num.push_back(temp3);
							mes+=string("����")+=to_string(num2)+=string("/")+=to_string(num1)+=string("  ������ջ�ɹ�ѹ��")+=to_string(temp3)+=string("\n"); 
							break;
						}
						case '^':{
							double temp3=pow(num2,num1);
							num.push_back(temp3);
							mes+=string("����")+=to_string(num2)+=string("^")+=to_string(num1)+=string("  ������ջ�ɹ�ѹ��")+=to_string(temp3)+=string("\n"); 
							break;
						}
						case '@':{
							double temp3=num1*(-1);
							num.push_back(temp3);
							mes+=string("����")+=string("-")+=to_string(num1)+=string("  ������ջ�ɹ�ѹ��")+=to_string(temp3)+=string("\n"); 
							break;
						}
						default :{
							cout<<"�Ƿ��ַ���"<<endl;
							break;
						}
					}
			
			if(b!=')'&&b!='#'&&b!=']')
			{
				op.push_back(b);
				string temp4;
				temp4=b;
				mes+=string("�����ջ�ɹ�ѹ��")+=temp4+=string("\n");
			}
			else
			{
				goto start;
			}
			break;
		}
		default :{
			throw(3);
			break;
		}
	}
}

void Cal::run()//ִ�� 
		{
			int len=exp.length();//���ʽ�ĳ���
			int num1=0,num2=0;
			string temp;//��ʱ��������¼������
			
			for(int i=0;i<len;i++)
			{
				if(exp[i]>='0'&&exp[i]<='9')
				{
					for(int j=i;j<len;j++)
					{
						if(j==len-1||exp[j+1]<'0'||exp[j+1]>'9')
						{
							temp=exp.substr(i,j-i+1);
							num.push_back(stoi(temp));
							mes+=string("������ջ�ɹ�ѹ��")+=temp+=string("\n"); 
							print(temp);
							cnt++;
							i=j;
							break;
						}
					}
				}
				else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='('||exp[i]==')'||exp[i]=='^'||exp[i]=='#'||exp[i]=='['||exp[i]==']')
				{
					if(exp[i]=='+'&&(i==0||exp[i-1]=='+'||exp[i-1]=='-'||exp[i-1]=='*'||exp[i-1]=='/'||exp[i-1]=='('||exp[i-1]=='['||exp[i-1]=='^'))
					{
						throw(3);
					}
					else if(exp[i]=='*'&&(i==0||exp[i-1]=='+'||exp[i-1]=='-'||exp[i-1]=='*'||exp[i-1]=='/'||exp[i-1]=='('||exp[i-1]=='['||exp[i-1]=='^'))
					{
						throw(3);
					}
					else if(exp[i]=='/'&&(i==0||exp[i-1]=='+'||exp[i-1]=='-'||exp[i-1]=='*'||exp[i-1]=='/'||exp[i-1]=='('||exp[i-1]=='['||exp[i-1]=='^'))
					{
						throw(3);
					}else if(exp[i]=='^'&&(i==0||exp[i-1]=='+'||exp[i-1]=='-'||exp[i-1]=='*'||exp[i-1]=='/'||exp[i-1]=='('||exp[i-1]=='['||exp[i-1]=='^'))
					{
						throw(3);
					}
					else if(exp[i]=='-'&&(i==0||(exp[i-1]<'0'||exp[i-1]>'9')&&exp[i-1]!=']'&&exp[i-1]!=')'))
					{
						temp=exp[i];
						op_push('@');
						print(temp);
						cnt++;	
					}
					else
					{
						temp=exp[i];
						op_push(exp[i]);
						print(temp);
						cnt++;						
					}
				}
				else
				throw(2);
			}
			cout<<"���Ľ���ǣ�"<<num.back()<<endl;
			 
		}

void Cal::print(string str)
		{
			cout<<"=================================="<<endl;
			cout<<"*��"<<cnt<<"�β���"<<endl;
			
			cout<<"�����ջ��"; 
			for(auto cur:op){
				if(cur!='@')
				cout<<cur<<"   ";
				else
				cout<<'-'<<"   ";
			}
			cout<<endl;
			
			cout<<"������ջ��"; 
			for(auto cur:num){
				cout<<cur<<"   ";
			}
			cout<<endl;
			
			cout<<"��ȡ�����ַ���"<<str<<endl;
			
			cout<<"ִ�еĲ�����"<<mes<<endl;
			mes.clear();
//			switch(id){
//				case 0:{
//					cout<<"ѹ��"<<str<<endl; 
//					break;
//				}
//				case 1:{
//					cout<<"����"<<str<<endl; 
//					break;
//				}
//				case 2:{
//					cout<<"����"<<num1<<str<<num2<<endl; 
//					break;
//				}
//			}
			
			cout<<"=================================="<<endl;
		}
