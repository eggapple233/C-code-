#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include "analy.h"
using namespace std; 

int main()
{
	bool flag1=true;//�ж� �Ƿ��˳�ʹ�� 
	int input1;//������� 
	int input2;//�ִ�ѡ�� 
	string input3;//�ļ�����
	 
	ifstream inFile,keyFile; 
	while(flag1)
	{
	cout<<"===============���װ��ı�������==============="<<endl;
	cout<<"=                                            ="<<endl;
	cout<<"===================����˵��==================="<<endl;
	cout<<"*                                            *"<<endl; 
	cout<<"*  �÷����������Դ�ı����з����������ÿ��  *"<<endl;
	cout<<"*  �ʳ��ֵ�Ƶ�ʣ��Լ����ֵ��кţ�λ��ͬһ��  *"<<endl;
	cout<<"*  �����ظ���ʾ���ȼ�����Ϣ                  *"<<endl;
	cout<<"*                                            *"<<endl; 
	cout<<"===================�������==================="<<endl;
	cout<<"*                                            *"<<endl; 
	cout<<"*0���˳�ʹ��                                 *"<<endl;
	cout<<"*1������Ӣ�Ķ���(�ʺϴ��ո������)           *"<<endl;
	cout<<"*2������C���Գ������(�Դ������ַ�����)      *"<<endl;
	cout<<"*3������������KMP�㷨�����ı���              *"<<endl; 
	cout<<"*                                            *"<<endl; 
	cout<<"=============================================="<<endl;
		cin>>input1;
		switch(input1)
		{
			case 0:{
				flag1=false;
				break;
			}
			case 1:{//1������Ӣ�Ķ���(�ʺϴ��ո������)    
				label1://label1
				cout<<"===================ѡ��ִ�==================="<<endl;
				cout<<"*                                            *"<<endl; 
				cout<<"*0��Ĭ��ѡ�����е��ʣ������е��ʽ��з�����   *"<<endl;
				cout<<"*1���Զ���ؼ����ļ���ֻ����ؼ��ʣ�         *"<<endl;
				cout<<"*   ���ÿո����ÿ���ؼ���                   *"<<endl;
				cout<<"=============================================="<<endl;
				
				cin>>input2;
				switch(input2)
				{
					case 0:{						
						label2://label2
						cout<<">>�������ļ�����(����ͬһĿ¼��ʱ������·��)��"<<endl;
						input3="";
						cin>>input3;
						input3+=".txt";
						
						inFile.open(input3);
						if(!inFile)
						{
							cout<<">>Error:δ�ҵ���Ӧ���ļ�"<<input3<<"����ȷ��·����ȷ���ļ�����"<<endl;
							Sleep(500);
							goto label2;//to label2
						}
						
						Text text(inFile,0);//���ȫ���������Text������ 
						text.read1();
						inFile.close();
						cout<<"Ҳ���Ե�����ͬ��Ŀ¼��Running Log.txt�ļ��в鿴"<<endl;
						Sleep(2000);
						break;
					}
					case 1:{
						label3://label3
						cout<<">>��������Ҫ������Դ�ļ�����(����ͬһĿ¼��ʱ������·��)��"<<endl;
						input3="";
						cin>>input3;
						input3+=".txt";
						
						inFile.open(input3);
						if(!inFile)
						{
							cout<<">>Error:δ�ҵ���Ӧ���ļ�"<<input3<<"����ȷ��·����ȷ���ļ�����"<<endl;
							Sleep(500);
							goto label3;//to label3
						}
						
						label4: //label4
						cout<<">>�������Զ����˹ؼ��ʵ�Դ�ļ�����(����ͬһĿ¼��ʱ������·��)��"<<endl;
						input3="";
						cin>>input3;
						input3+=".txt";
						
						keyFile.open(input3);
						if(!keyFile)
						{
							cout<<">>Error:δ�ҵ���Ӧ���ļ�"<<input3<<"����ȷ��·����ȷ���ļ�����"<<endl;
							Sleep(500);
							goto label4;//to label4
						}
						
						Text text(inFile,keyFile);//���ȫ���������Text������ 
						text.read3();
						inFile.close();
						keyFile.close();
						cout<<"Ҳ���Ե�����ͬ��Ŀ¼��Running Log.txt�ļ��в鿴"<<endl;
						Sleep(2000);
						break;
					}
					default:{
						cout<<">>����ı�ţ�����������"<<endl;
						goto label1;//to label1
						break;
					}
				}
				break;
			}
			case 2:{//2������C���Գ������(�Դ������ַ�����) 
				label5://label5
				cout<<"===================ѡ��ִ�==================="<<endl;
				cout<<"*                                            *"<<endl; 
				cout<<"*0��Ĭ�Ϸ��������б����ַ����ͳ�����ʶ��     *"<<endl;
				cout<<"*1���Զ���ؼ����ļ���ֻ����ؼ��ʣ�         *"<<endl;
				cout<<"*   ���ÿո����ÿ���ؼ���                   *"<<endl;
				cout<<"=============================================="<<endl;
				
				cin>>input2;
				switch(input2)
				{
					case 0:{						
						label6://label6
						cout<<">>�������ļ�����(����ͬһĿ¼��ʱ������·��)��"<<endl;
						input3="";
						cin>>input3;
						input3+=".txt";
						
						inFile.open(input3);
						if(!inFile)
						{
							cout<<">>Error:δ�ҵ���Ӧ���ļ�"<<input3<<"����ȷ��·����ȷ���ļ�����"<<endl;
							Sleep(500);
							goto label6;//to label6
						}
						
						Text text(inFile,1);//���ȫ���������Text������ 
						text.read2();
						inFile.close();
						cout<<"Ҳ���Ե�����ͬ��Ŀ¼��Running Log.txt�ļ��в鿴"<<endl;
						Sleep(2000);
						break;
					}
					case 1:{
						label7://label7
						cout<<">>��������Ҫ������Դ�ļ�����(����ͬһĿ¼��ʱ������·��)��"<<endl;
						input3="";
						cin>>input3;
						input3+=".txt";
						
						inFile.open(input3);
						if(!inFile)
						{
							cout<<">>Error:δ�ҵ���Ӧ���ļ�"<<input3<<"����ȷ��·����ȷ���ļ�����"<<endl;
							Sleep(500);
							goto label7;//to label7
						}
						
						label8: //label8
						cout<<">>�������Զ����˹ؼ��ʵ�Դ�ļ�����(����ͬһĿ¼��ʱ������·��)��"<<endl;
						input3="";
						cin>>input3;
						input3+=".txt";
						
						keyFile.open(input3);
						if(!keyFile)
						{
							cout<<">>Error:δ�ҵ���Ӧ���ļ�"<<input3<<"����ȷ��·����ȷ���ļ�����"<<endl;
							Sleep(500);
							goto label8;//to label8
						}
						
						Text text(inFile,keyFile);//���ȫ���������Text������ 
						text.read2();
						inFile.close();
						keyFile.close();
						cout<<"Ҳ���Ե�����ͬ��Ŀ¼��Running Log.txt�ļ��в鿴"<<endl;
						Sleep(2000);
						break;
					}
					default:{
						cout<<">>����ı�ţ�����������"<<endl;
						goto label5;//to label5
						break;
					}
				 } 
				break;
			}
			case 3:{//3������������KMP�㷨�����ı���        
					label9://label9
						cout<<">>��������Ҫ������Դ�ļ�����(����ͬһĿ¼��ʱ������·��)��"<<endl;
						input3="";
						cin>>input3;
						input3+=".txt";
						
						inFile.open(input3);
						if(!inFile)
						{
							cout<<">>Error:δ�ҵ���Ӧ���ļ�"<<input3<<"����ȷ��·����ȷ���ļ�����"<<endl;
							Sleep(500);
							goto label9;//to label9
						}
						
					label10: //label10
						cout<<">>�������Զ����˹ؼ��ʵ�Դ�ļ�����(����ͬһĿ¼��ʱ������·��)��"<<endl;
						input3="";
						cin>>input3;
						input3+=".txt";
						
						keyFile.open(input3);
						if(!keyFile)
						{
							cout<<">>Error:δ�ҵ���Ӧ���ļ�"<<input3<<"����ȷ��·����ȷ���ļ�����"<<endl;
							Sleep(500);
							goto label10;//to label10
						}
						
						Text text(inFile,keyFile);//���ȫ���������Text������ 
						text.read3();
						inFile.close();
						keyFile.close();
						cout<<"Ҳ���Ե�����ͬ��Ŀ¼��Running Log.txt�ļ��в鿴"<<endl;
						Sleep(2000);
				break;
			}
			default:{
				cout<<">>����ı�ţ�����������"<<endl;
						goto label5;
						break;
				break;
			}
		}
	}
	
	cout<<"----====�ɹ��˳�  ��лʹ��====----"<<endl;
	Sleep(2000); 
	
	
	
	
}


