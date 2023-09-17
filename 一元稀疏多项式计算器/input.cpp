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
				cout<<"请输入多项式a的项数n (N>0)"<<endl;	
				
				start3://加法操作中，重新输入a的项数 
				cin>>temp;
				if(!check1(temp))
				{
					cout<<"输入数据有误(#4)，请重新输入并确保输入的是有效的项数n (N>0):"<<endl;
					cin.clear();
					cin.sync();
					goto start3;
				}
				n=stoi(temp);
				if(n<=0)
				{
					cout<<"输入数据有误(#4)，请重新输入并确保输入的是有效的项数n (N>0):"<<endl;
					cin.clear();
					cin.sync();
					goto start3;
				}
				cout<<"请输入多项式的系数和指数（示例：input>>2 3   即表示输入2*x^3）"<<endl;
				double ceo;
				double index;
				for(int i=0;i<n;i++)
				{
					start4://加法操作中，重新输入a的系数 
					cout<<"系数：";
					if(cin>>ceo)
					{	
						if(ceo==0)
						{
							cout<<"您不必输入系数为0的项（这并非错误，只是提示）"<<endl;
						}
						start5://加法操作中，重新输入a的指数 
						cout<<endl<<"指数：";
						cin>>temp;
						if(!check1(temp))
						{
							cout<<"输入数据有误(#6)，请重新输入并确保输入的是有效的项数n (N>=0):";
							cin.clear();
							cin.sync();
							goto start5;
						}
						else
						{
							index=stoi(temp);
							if(check2(arr1,index))
							{
								cout<<"输入数据重复(#7)，请重新输入并确保输入的是不重复的指数";
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
						cout<<"输入数据有误(#5)，请重新输入并确保输入的是有效的系数:"<<endl;
						cin.clear();
						cin.sync();
						goto start4;
					}
				}
				Poly main_poly(arr1);
				cout<<"输入完成，成功创建多项式："<<endl;
				main_poly.print2();
				cout<<"以 \"项数 {系数，指数}\" 形式表现为：";
				main_poly.print1();
				
				
				cout<<"请输入多项式b的项数n (N>0)"<<endl;	
				
				start6://加法操作中，重新输入b的项数 
				cin>>temp;
				if(!check1(temp))
				{
					cout<<"输入数据有误(#4)，请重新输入并确保输入的是有效的项数n (N>0):"<<endl;
					cin.clear();
					cin.sync();
					goto start6;
				}
				n=stoi(temp);
				if(n<=0)
				{
					cout<<"输入数据有误(#4)，请重新输入并确保输入的是有效的项数n (N>0):"<<endl;
					cin.clear();
					cin.sync();
					goto start6;
				}
				cout<<"请输入多项式的系数和指数（示例：input>>2 3   即表示输入2*x^3）"<<endl;

				for(int i=0;i<n;i++)
				{
					start7://加法操作中，重新输入b的系数 
					cout<<"系数：";
					if(cin>>ceo)
					{
						start8://加法操作中，重新输入b的指数 
						cout<<endl<<"指数：";
						cin>>temp;
						if(!check1(temp))
						{
							cout<<"输入数据有误(#6)，请重新输入并确保输入的是有效的项数n (N>=0):";
							cin.clear();
							cin.sync();
							goto start8;
						}
						else
						{
							index=stoi(temp);
							if(check2(arr2,index))
							{
								cout<<"输入数据重复(#7)，请重新输入并确保输入的是不重复的指数";
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
						cout<<"输入数据有误(#5)，请重新输入并确保输入的是有效的系数:"<<endl;
						cin.clear();
						cin.sync();
						goto start7;
					}
				}
				Poly sub_poly(arr2);
				cout<<"输入完成，成功创建多项式："<<endl;
				sub_poly.print2();
				cout<<"以 \"项数 {系数，指数}\" 形式表现为：";
				sub_poly.print1();
				
				if(id==1)
				{
				cout<<endl<<endl;
				Poly result=main_poly.add(sub_poly);
				cout<<"加法结果为："<<endl;
				result.print2();
				cout<<"以 \"项数 {系数，指数}\" 形式表现为：";
				result.print1();
				}
				else if(id==2)
				{
				cout<<endl<<endl;
				Poly result=main_poly.reduce(sub_poly);
				cout<<"减法结果为："<<endl;
				result.print2();
				cout<<"以 \"项数 {系数，指数}\" 形式表现为：";
				result.print1();
				}
				else if(id==3)
				{
				cout<<endl<<endl;
				Poly result=main_poly.mux(sub_poly);
				cout<<"乘法结果为："<<endl;
				result.print2();
				cout<<"以 \"项数 {系数，指数}\" 形式表现为：";
				result.print1();
				}
				
		}
		
		void input_2(int id){
				string temp;
				int n;
				vector<vector<double>> arr1,arr2;
				cout<<"请输入多项式的项数n (N>0)"<<endl;	
				
				start3://加法操作中，重新输入a的项数 
				cin>>temp;
				if(!check1(temp))
				{
					cout<<"输入数据有误(#4)，请重新输入并确保输入的是有效的项数n (N>0):"<<endl;
					cin.clear();
					cin.sync();
					goto start3;
				}
				n=stoi(temp);
				if(n<=0)
				{
					cout<<"输入数据有误(#4)，请重新输入并确保输入的是有效的项数n (N>0):"<<endl;
					cin.clear();
					cin.sync();
					goto start3;
				}
				cout<<"请输入多项式的系数和指数（示例：input>>2 3   即表示输入2*x^3）"<<endl;
				double ceo;
				double index;
				for(int i=0;i<n;i++)
				{
					start4://加法操作中，重新输入a的系数 
					cout<<"系数：";
					if(cin>>ceo)
					{	
						if(ceo==0)
						{
							cout<<"您不必输入系数为0的项（这并非错误，只是提示）"<<endl;
						}
						start5://加法操作中，重新输入a的指数 
						cout<<endl<<"指数：";
						cin>>temp;
						if(!check1(temp))
						{
							cout<<"输入数据有误(#6)，请重新输入并确保输入的是有效的项数n (N>=0):";
							cin.clear();
							cin.sync();
							goto start5;
						}
						else
						{
							index=stoi(temp);
							if(check2(arr1,index))
							{
								cout<<"输入数据重复(#7)，请重新输入并确保输入的是不重复的指数";
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
						cout<<"输入数据有误(#5)，请重新输入并确保输入的是有效的系数:"<<endl;
						cin.clear();
						cin.sync();
						goto start4;
					}
				}
				Poly main_poly(arr1);
				cout<<"输入完成，成功创建多项式："<<endl;
				main_poly.print2();
				cout<<"以 \"项数 {系数，指数}\" 形式表现为：";
				main_poly.print1();
				
				if(id==1)
				{
				cout<<endl<<endl;
				Poly result=main_poly.diff();
				cout<<"求导结果为："<<endl;
				result.print2();
				cout<<"以 \"项数 {系数，指数}\" 形式表现为：";
				result.print1();
				}
				else if(id==2)
				{
				start9://重新输入X的取值 
				double x;
				cout<<endl<<endl<<"请输入x的取值：";
				if(cin>>x)
				{
					cout<<endl<<endl;
					cout<<"计算x= "<<x<<" 时，多项式的值为："<<main_poly.cal(x)<<endl;
				}
				else
					{
						cout<<"输入数据有误(#8)，请重新输入并确保输入的是有效的x:"<<endl;
						cin.clear();
						cin.sync();
						goto start9;
					}
				
				}
		}
		
		
