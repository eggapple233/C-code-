#include "iostream"
#include "input.h"
#include "ctype.h"
#include "poly.h"
bool check1(string temp){
	int len=temp.length();
	int n=0;
	if(temp[0]=='-'&&len>=2)
		n=1;
	for(int i=n;i<len;i++)
		if(!isdigit(temp[i]))
		{
			return false;
		}
	return true;
} 

bool check2(vector<vector<double>> arr,int x){
	int len=arr.size();
	int n=0;
	for(auto i:arr)
	{
		if(i[1]==x)
		{
			return true;
		}
	}
	return false;
} 
		
		void input_1(int id){
				string temp;
				int n;
				vector<vector<double>> arr1,arr2;
				cout<<"���������ʽa������n (N>0)"<<endl;	
				
				start3://�ӷ������У���������a������ 
				cin>>temp;
				if(!check1(temp))
				{
					cout<<"������������(#4)�����������벢ȷ�����������Ч������n (N>0):"<<endl;
					cin.clear();
					cin.sync();
					goto start3;
				}
				n=stoi(temp);
				if(n<=0)
				{
					cout<<"������������(#4)�����������벢ȷ�����������Ч������n (N>0):"<<endl;
					cin.clear();
					cin.sync();
					goto start3;
				}
				cout<<"���������ʽ��ϵ����ָ����ʾ����input>>2 3   ����ʾ����2*x^3��"<<endl;
				double ceo;
				double index;
				for(int i=0;i<n;i++)
				{
					start4://�ӷ������У���������a��ϵ�� 
					cout<<"ϵ����";
					if(cin>>ceo)
					{	
						if(ceo==0)
						{
							cout<<"����������ϵ��Ϊ0����Ⲣ�Ǵ���ֻ����ʾ��"<<endl;
						}
						start5://�ӷ������У���������a��ָ�� 
						cout<<endl<<"ָ����";
						cin>>temp;
						if(!check1(temp))
						{
							cout<<"������������(#6)�����������벢ȷ�����������Ч������n (N>=0):";
							cin.clear();
							cin.sync();
							goto start5;
						}
						else
						{
							index=stoi(temp);
							if(check2(arr1,index))
							{
								cout<<"���������ظ�(#7)�����������벢ȷ��������ǲ��ظ���ָ��";
								cin.clear();
								cin.sync();
								goto start5;
							}
							arr1.push_back({ceo,index});
							cout<<"----------"<<endl;
						}
					}
					else
					{
						cout<<"������������(#5)�����������벢ȷ�����������Ч��ϵ��:"<<endl;
						cin.clear();
						cin.sync();
						goto start4;
					}
				}
				Poly main_poly(arr1);
				cout<<"������ɣ��ɹ���������ʽ��"<<endl;
				main_poly.print2();
				cout<<"�� \"���� {ϵ����ָ��}\" ��ʽ����Ϊ��";
				main_poly.print1();
				
				
				cout<<"���������ʽb������n (N>0)"<<endl;	
				
				start6://�ӷ������У���������b������ 
				cin>>temp;
				if(!check1(temp))
				{
					cout<<"������������(#4)�����������벢ȷ�����������Ч������n (N>0):"<<endl;
					cin.clear();
					cin.sync();
					goto start6;
				}
				n=stoi(temp);
				if(n<=0)
				{
					cout<<"������������(#4)�����������벢ȷ�����������Ч������n (N>0):"<<endl;
					cin.clear();
					cin.sync();
					goto start6;
				}
				cout<<"���������ʽ��ϵ����ָ����ʾ����input>>2 3   ����ʾ����2*x^3��"<<endl;

				for(int i=0;i<n;i++)
				{
					start7://�ӷ������У���������b��ϵ�� 
					cout<<"ϵ����";
					if(cin>>ceo)
					{
						start8://�ӷ������У���������b��ָ�� 
						cout<<endl<<"ָ����";
						cin>>temp;
						if(!check1(temp))
						{
							cout<<"������������(#6)�����������벢ȷ�����������Ч������n (N>=0):";
							cin.clear();
							cin.sync();
							goto start8;
						}
						else
						{
							index=stoi(temp);
							if(check2(arr2,index))
							{
								cout<<"���������ظ�(#7)�����������벢ȷ��������ǲ��ظ���ָ��";
								cin.clear();
								cin.sync();
								goto start8;
							}
							arr2.push_back({ceo,index});
							cout<<"----------"<<endl;
						}
					}
					else
					{
						cout<<"������������(#5)�����������벢ȷ�����������Ч��ϵ��:"<<endl;
						cin.clear();
						cin.sync();
						goto start7;
					}
				}
				Poly sub_poly(arr2);
				cout<<"������ɣ��ɹ���������ʽ��"<<endl;
				sub_poly.print2();
				cout<<"�� \"���� {ϵ����ָ��}\" ��ʽ����Ϊ��";
				sub_poly.print1();
				
				if(id==1)
				{
				cout<<endl<<endl;
				Poly result=main_poly.add(sub_poly);
				cout<<"�ӷ����Ϊ��"<<endl;
				result.print2();
				cout<<"�� \"���� {ϵ����ָ��}\" ��ʽ����Ϊ��";
				result.print1();
				}
				else if(id==2)
				{
				cout<<endl<<endl;
				Poly result=main_poly.reduce(sub_poly);
				cout<<"�������Ϊ��"<<endl;
				result.print2();
				cout<<"�� \"���� {ϵ����ָ��}\" ��ʽ����Ϊ��";
				result.print1();
				}
				else if(id==3)
				{
				cout<<endl<<endl;
				Poly result=main_poly.mux(sub_poly);
				cout<<"�˷����Ϊ��"<<endl;
				result.print2();
				cout<<"�� \"���� {ϵ����ָ��}\" ��ʽ����Ϊ��";
				result.print1();
				}
				
		}
		
		void input_2(int id){
				string temp;
				int n;
				vector<vector<double>> arr1,arr2;
				cout<<"���������ʽ������n (N>0)"<<endl;	
				
				start3://�ӷ������У���������a������ 
				cin>>temp;
				if(!check1(temp))
				{
					cout<<"������������(#4)�����������벢ȷ�����������Ч������n (N>0):"<<endl;
					cin.clear();
					cin.sync();
					goto start3;
				}
				n=stoi(temp);
				if(n<=0)
				{
					cout<<"������������(#4)�����������벢ȷ�����������Ч������n (N>0):"<<endl;
					cin.clear();
					cin.sync();
					goto start3;
				}
				cout<<"���������ʽ��ϵ����ָ����ʾ����input>>2 3   ����ʾ����2*x^3��"<<endl;
				double ceo;
				double index;
				for(int i=0;i<n;i++)
				{
					start4://�ӷ������У���������a��ϵ�� 
					cout<<"ϵ����";
					if(cin>>ceo)
					{	
						if(ceo==0)
						{
							cout<<"����������ϵ��Ϊ0����Ⲣ�Ǵ���ֻ����ʾ��"<<endl;
						}
						start5://�ӷ������У���������a��ָ�� 
						cout<<endl<<"ָ����";
						cin>>temp;
						if(!check1(temp))
						{
							cout<<"������������(#6)�����������벢ȷ�����������Ч������n (N>=0):";
							cin.clear();
							cin.sync();
							goto start5;
						}
						else
						{
							index=stoi(temp);
							if(check2(arr1,index))
							{
								cout<<"���������ظ�(#7)�����������벢ȷ��������ǲ��ظ���ָ��";
								cin.clear();
								cin.sync();
								goto start5;
							}
							arr1.push_back({ceo,index});
							cout<<"----------"<<endl;
						}
					}
					else
					{
						cout<<"������������(#5)�����������벢ȷ�����������Ч��ϵ��:"<<endl;
						cin.clear();
						cin.sync();
						goto start4;
					}
				}
				Poly main_poly(arr1);
				cout<<"������ɣ��ɹ���������ʽ��"<<endl;
				main_poly.print2();
				cout<<"�� \"���� {ϵ����ָ��}\" ��ʽ����Ϊ��";
				main_poly.print1();
				
				if(id==1)
				{
				cout<<endl<<endl;
				Poly result=main_poly.diff();
				cout<<"�󵼽��Ϊ��"<<endl;
				result.print2();
				cout<<"�� \"���� {ϵ����ָ��}\" ��ʽ����Ϊ��";
				result.print1();
				}
				else if(id==2)
				{
				start9://��������X��ȡֵ 
				double x;
				cout<<endl<<endl<<"������x��ȡֵ��";
				if(cin>>x)
				{
					cout<<endl<<endl;
					cout<<"����x= "<<x<<" ʱ������ʽ��ֵΪ��"<<main_poly.cal(x)<<endl;
				}
				else
					{
						cout<<"������������(#8)�����������벢ȷ�����������Ч��x:"<<endl;
						cin.clear();
						cin.sync();
						goto start9;
					}
				
				}
		}
		
		
