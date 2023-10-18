#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include "analy.h"
using namespace std; 

int main()
{
	bool flag1=true;//判断 是否退出使用 
	int input1;//操作序号 
	int input2;//分词选择 
	string input3;//文件名字
	 
	ifstream inFile,keyFile; 
	while(flag1)
	{
	cout<<"===============简易版文本分析器==============="<<endl;
	cout<<"=                                            ="<<endl;
	cout<<"===================功能说明==================="<<endl;
	cout<<"*                                            *"<<endl; 
	cout<<"*  该分析器将会对源文本进行分析，并输出每个  *"<<endl;
	cout<<"*  词出现的频率，以及出现的行号（位于同一行  *"<<endl;
	cout<<"*  不会重复显示）等简易信息                  *"<<endl;
	cout<<"*                                            *"<<endl; 
	cout<<"===================操作序号==================="<<endl;
	cout<<"*                                            *"<<endl; 
	cout<<"*0：退出使用                                 *"<<endl;
	cout<<"*1：分析英文短文(适合带空格的文章)           *"<<endl;
	cout<<"*2：分析C语言程序代码(自带保留字符分析)      *"<<endl;
	cout<<"*3：分析其他（KMP算法分析文本）              *"<<endl; 
	cout<<"*                                            *"<<endl; 
	cout<<"=============================================="<<endl;
		cin>>input1;
		switch(input1)
		{
			case 0:{
				flag1=false;
				break;
			}
			case 1:{//1：分析英文短文(适合带空格的文章)    
				label1://label1
				cout<<"===================选择分词==================="<<endl;
				cout<<"*                                            *"<<endl; 
				cout<<"*0：默认选择所有单词（对所有单词进行分析）   *"<<endl;
				cout<<"*1：自定义关键词文件（只输出关键词）         *"<<endl;
				cout<<"*   请用空格隔开每个关键词                   *"<<endl;
				cout<<"=============================================="<<endl;
				
				cin>>input2;
				switch(input2)
				{
					case 0:{						
						label2://label2
						cout<<">>请输入文件名字(不在同一目录下时请输入路径)："<<endl;
						input3="";
						cin>>input3;
						input3+=".txt";
						
						inFile.open(input3);
						if(!inFile)
						{
							cout<<">>Error:未找到对应的文件"<<input3<<"，请确保路径正确且文件存在"<<endl;
							Sleep(500);
							goto label2;//to label2
						}
						
						Text text(inFile,0);//结果全保存在这个Text类里面 
						text.read1();
						inFile.close();
						cout<<"也可以到程序同级目录下Running Log.txt文件中查看"<<endl;
						Sleep(2000);
						break;
					}
					case 1:{
						label3://label3
						cout<<">>请输入需要分析的源文件名字(不在同一目录下时请输入路径)："<<endl;
						input3="";
						cin>>input3;
						input3+=".txt";
						
						inFile.open(input3);
						if(!inFile)
						{
							cout<<">>Error:未找到对应的文件"<<input3<<"，请确保路径正确且文件存在"<<endl;
							Sleep(500);
							goto label3;//to label3
						}
						
						label4: //label4
						cout<<">>请输入自定义了关键词的源文件名字(不在同一目录下时请输入路径)："<<endl;
						input3="";
						cin>>input3;
						input3+=".txt";
						
						keyFile.open(input3);
						if(!keyFile)
						{
							cout<<">>Error:未找到对应的文件"<<input3<<"，请确保路径正确且文件存在"<<endl;
							Sleep(500);
							goto label4;//to label4
						}
						
						Text text(inFile,keyFile);//结果全保存在这个Text类里面 
						text.read3();
						inFile.close();
						keyFile.close();
						cout<<"也可以到程序同级目录下Running Log.txt文件中查看"<<endl;
						Sleep(2000);
						break;
					}
					default:{
						cout<<">>错误的编号，请重新输入"<<endl;
						goto label1;//to label1
						break;
					}
				}
				break;
			}
			case 2:{//2：分析C语言程序代码(自带保留字符分析) 
				label5://label5
				cout<<"===================选择分词==================="<<endl;
				cout<<"*                                            *"<<endl; 
				cout<<"*0：默认分析代码中保留字符串和常见标识符     *"<<endl;
				cout<<"*1：自定义关键词文件（只输出关键词）         *"<<endl;
				cout<<"*   请用空格隔开每个关键词                   *"<<endl;
				cout<<"=============================================="<<endl;
				
				cin>>input2;
				switch(input2)
				{
					case 0:{						
						label6://label6
						cout<<">>请输入文件名字(不在同一目录下时请输入路径)："<<endl;
						input3="";
						cin>>input3;
						input3+=".txt";
						
						inFile.open(input3);
						if(!inFile)
						{
							cout<<">>Error:未找到对应的文件"<<input3<<"，请确保路径正确且文件存在"<<endl;
							Sleep(500);
							goto label6;//to label6
						}
						
						Text text(inFile,1);//结果全保存在这个Text类里面 
						text.read2();
						inFile.close();
						cout<<"也可以到程序同级目录下Running Log.txt文件中查看"<<endl;
						Sleep(2000);
						break;
					}
					case 1:{
						label7://label7
						cout<<">>请输入需要分析的源文件名字(不在同一目录下时请输入路径)："<<endl;
						input3="";
						cin>>input3;
						input3+=".txt";
						
						inFile.open(input3);
						if(!inFile)
						{
							cout<<">>Error:未找到对应的文件"<<input3<<"，请确保路径正确且文件存在"<<endl;
							Sleep(500);
							goto label7;//to label7
						}
						
						label8: //label8
						cout<<">>请输入自定义了关键词的源文件名字(不在同一目录下时请输入路径)："<<endl;
						input3="";
						cin>>input3;
						input3+=".txt";
						
						keyFile.open(input3);
						if(!keyFile)
						{
							cout<<">>Error:未找到对应的文件"<<input3<<"，请确保路径正确且文件存在"<<endl;
							Sleep(500);
							goto label8;//to label8
						}
						
						Text text(inFile,keyFile);//结果全保存在这个Text类里面 
						text.read2();
						inFile.close();
						keyFile.close();
						cout<<"也可以到程序同级目录下Running Log.txt文件中查看"<<endl;
						Sleep(2000);
						break;
					}
					default:{
						cout<<">>错误的编号，请重新输入"<<endl;
						goto label5;//to label5
						break;
					}
				 } 
				break;
			}
			case 3:{//3：分析其他（KMP算法分析文本）        
					label9://label9
						cout<<">>请输入需要分析的源文件名字(不在同一目录下时请输入路径)："<<endl;
						input3="";
						cin>>input3;
						input3+=".txt";
						
						inFile.open(input3);
						if(!inFile)
						{
							cout<<">>Error:未找到对应的文件"<<input3<<"，请确保路径正确且文件存在"<<endl;
							Sleep(500);
							goto label9;//to label9
						}
						
					label10: //label10
						cout<<">>请输入自定义了关键词的源文件名字(不在同一目录下时请输入路径)："<<endl;
						input3="";
						cin>>input3;
						input3+=".txt";
						
						keyFile.open(input3);
						if(!keyFile)
						{
							cout<<">>Error:未找到对应的文件"<<input3<<"，请确保路径正确且文件存在"<<endl;
							Sleep(500);
							goto label10;//to label10
						}
						
						Text text(inFile,keyFile);//结果全保存在这个Text类里面 
						text.read3();
						inFile.close();
						keyFile.close();
						cout<<"也可以到程序同级目录下Running Log.txt文件中查看"<<endl;
						Sleep(2000);
				break;
			}
			default:{
				cout<<">>错误的编号，请重新输入"<<endl;
						goto label5;
						break;
				break;
			}
		}
	}
	
	cout<<"----====成功退出  感谢使用====----"<<endl;
	Sleep(2000); 
	
	
	
	
}


