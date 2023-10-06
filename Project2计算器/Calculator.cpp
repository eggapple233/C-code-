#include "iostream"
#include "vector"
#include "string"
#include "cmath"
#include "Calculator.h"

int Cal::priority(char a,char b)//-1是<  0是=   1是>   2是--- 
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
			mes+=string("运算符栈成功压入")+=temp+=string("\n");
			else
			mes+=string("运算符栈成功压入-\n");
			break;
		}
		case 0:{
			op.pop_back();
			string temp;
			temp=a;
			if(a!='@')
			mes+=string("运算符栈成功弹出")+=temp+=string("\n");
			else
			mes+=string("运算符栈成功弹出-\n");
			break;
		}
		case 1:{
			op.pop_back();
			string temp;
			temp=a;
			string temp2;
			temp2='-';
			
			if(a!='@')
			mes+=string("运算符栈成功弹出")+=temp+=string("\n"); 
			else
			mes+=string("运算符栈成功弹出")+=temp2+=string("\n"); 
			
			
			double num1=num.back();
			num.pop_back();
			string temp1;
			temp1=to_string(num1);
			mes+=string("运算数栈成功弹出")+=temp1+=string("\n"); 
			
			double num2=0;
			if(a!='@')
			{
				num2=num.back();
				num.pop_back();
				string temp2;
				temp2=to_string(num2);
				mes+=string("运算数栈成功弹出")+=temp2+=string("\n"); 
			}
			switch(a)
					{
						case '+':{
							double temp3=num1+num2;
							num.push_back(temp3);
							mes+=string("计算")+=to_string(num2)+=string("+")+=to_string(num1)+=string("  运算数栈成功压入")+=to_string(temp3)+=string("\n"); 
							break;
						}
						case '-':{
							double temp3=num2-num1;
							num.push_back(temp3);
							mes+=string("计算")+=to_string(num2)+=string("-")+=to_string(num1)+=string("  运算数栈成功压入")+=to_string(temp3)+=string("\n"); 
							break;
						}
						case '*':{
							double temp3=num2*num1;
							num.push_back(temp3);
							mes+=string("计算")+=to_string(num2)+=string("*")+=to_string(num1)+=string("  运算数栈成功压入")+=to_string(temp3)+=string("\n"); 
							break;
						}
						case '/':{
							if(num1==0)
							{
								throw(1);
							}
							double temp3=num2/num1;
							num.push_back(temp3);
							mes+=string("计算")+=to_string(num2)+=string("/")+=to_string(num1)+=string("  运算数栈成功压入")+=to_string(temp3)+=string("\n"); 
							break;
						}
						case '^':{
							double temp3=pow(num2,num1);
							num.push_back(temp3);
							mes+=string("计算")+=to_string(num2)+=string("^")+=to_string(num1)+=string("  运算数栈成功压入")+=to_string(temp3)+=string("\n"); 
							break;
						}
						case '@':{
							double temp3=num1*(-1);
							num.push_back(temp3);
							mes+=string("计算")+=string("-")+=to_string(num1)+=string("  运算数栈成功压入")+=to_string(temp3)+=string("\n"); 
							break;
						}
						default :{
							cout<<"非法字符！"<<endl;
							break;
						}
					}
			
			if(b!=')'&&b!='#'&&b!=']')
			{
				op.push_back(b);
				string temp4;
				temp4=b;
				mes+=string("运算符栈成功压入")+=temp4+=string("\n");
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

void Cal::run()//执行 
		{
			int len=exp.length();//表达式的长度
			int num1=0,num2=0;
			string temp;//临时变量，记录操作数
			
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
							mes+=string("运算数栈成功压入")+=temp+=string("\n"); 
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
			cout<<"最后的结果是："<<num.back()<<endl;
			 
		}

void Cal::print(string str)
		{
			cout<<"=================================="<<endl;
			cout<<"*第"<<cnt<<"次操作"<<endl;
			
			cout<<"运算符栈："; 
			for(auto cur:op){
				if(cur!='@')
				cout<<cur<<"   ";
				else
				cout<<'-'<<"   ";
			}
			cout<<endl;
			
			cout<<"运算数栈："; 
			for(auto cur:num){
				cout<<cur<<"   ";
			}
			cout<<endl;
			
			cout<<"读取到的字符："<<str<<endl;
			
			cout<<"执行的操作："<<mes<<endl;
			mes.clear();
//			switch(id){
//				case 0:{
//					cout<<"压入"<<str<<endl; 
//					break;
//				}
//				case 1:{
//					cout<<"弹出"<<str<<endl; 
//					break;
//				}
//				case 2:{
//					cout<<"计算"<<num1<<str<<num2<<endl; 
//					break;
//				}
//			}
			
			cout<<"=================================="<<endl;
		}
