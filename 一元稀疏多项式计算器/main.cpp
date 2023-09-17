#include "iostream"
#include "poly.h"
#include "input.h"
#include "cstdio"
#include "ctype.h"
#include "windows.h"


int main()
{
	start1: //重新弹出功能说明框 
	string choose;
	cout<<endl<<endl; 
	cout<<"===============一元多项式计算器==============="<<endl;
	cout<<"=                                            ="<<endl;
	cout<<"===================功能说明==================="<<endl;
	cout<<"**********请输入正确的序号以执行操作**********"<<endl; 
	cout<<"* 0:退出使用                                 *"<<endl;
	cout<<"* 1:多项式加法                               *"<<endl;
	cout<<"* 2:多项式减法                               *"<<endl;
	cout<<"* 3:多项式乘法                               *"<<endl;
	cout<<"* 4:多项式求导                               *"<<endl;
	cout<<"* 5:多项式求值                               *"<<endl;
	cout<<"* 6:查看错误代码                             *"<<endl;
	cout<<"**********************************beta 1.0****"<<endl;
	cout<<"=============================================="<<endl;
	
	start2: //重新输入操作码 
	while(cin>>choose)
	{
		if(!check1(choose))
		{
			cout<<"输入参数有误(#3)，请重新输入并确保输入的是有效的序号:"<<endl; 
			cin.clear();
			cin.sync();
			goto start2;
		}
		else
		switch(stoi(choose))
		{
			case 0: {
				goto end;
				break;
			}
			case 1: {
				input_1(1);
				goto start1;
			}	
			case 2:{
				input_1(2);
				goto start1;
			}
			case 3:{
				input_1(3);
				goto start1;
			}
			case 4:{
				input_2(1);
				goto start1;
			}
			case 5:{
				input_2(2);
				goto start1;
			}
			case 6:{
				cout<<"======================================================="<<endl;
				cout<<"= 错误编号（#） |               错误原因              ="<<endl;
				cout<<"=-----------------------------------------------------="<<endl;
				cout<<"=    #1         |         操作代码为非法字符串        ="<<endl;
				cout<<"=-----------------------------------------------------="<<endl;
				cout<<"=    #2         |      操作代码不在功能范围（0~6）内  ="<<endl;
				cout<<"=-----------------------------------------------------="<<endl;
				cout<<"=    #3         |        操作代码为浮点数而非整数     ="<<endl;
				cout<<"=-----------------------------------------------------="<<endl;
				cout<<"=    #4         |       多项式的项数不是大于0的整数   ="<<endl;
				cout<<"=-----------------------------------------------------="<<endl;
				cout<<"=    #5         |        某一项的系数为非法字符串     ="<<endl;
				cout<<"=-----------------------------------------------------="<<endl;
				cout<<"=    #6         |          某一项的指数不是整数       ="<<endl;
				cout<<"=-----------------------------------------------------="<<endl;
				cout<<"=    #7         |          输入了已经输入过的指数     ="<<endl;
				cout<<"=-----------------------------------------------------="<<endl;
				cout<<"=    #8         |           输入的x为非法字符串       ="<<endl;
				cout<<"======================================================="<<endl;
				cout<<endl<<endl;
				cout<<">回车以继续";
				cin.clear();
				cin.sync();
				string n;
				if(getline(cin,n))
				goto start1;
				
			}
			default:{
				cout<<"输入参数有误(#2)，请重新输入并确保输入的是有效的序号:"<<endl; 
				goto start2;
			}
		}
	}
	cout<<"输入参数有误(#1)，请重新输入并确保输入的是有效的序号:"<<endl; 
	cin.clear();
	cin.sync();
	goto start2;
	
	end://退出使用 
	cout<<endl<<endl;
	cout<<"*-=-=-=-=-=-=-=-=感谢\2使用=-=-=-=-=-=-=-=-*"<<endl; 
	Sleep(2000);
	return 0;
}
