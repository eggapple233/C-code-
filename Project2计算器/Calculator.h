#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_
using namespace std;

class Cal{
	public:
		Cal(string exp){
			mes="";
			cnt=1; 
			exp+="#";
			this->exp=exp;
			op.push_back('#');
		}
		
		int priority(char a,char b);//判断优先级 
		void op_push(char b);//操作符入栈 
		void run();//执行计算 
		void print(string str);//输出各步骤结果 
	private:
		int cnt; //记录步骤数 
		string mes;//记录操作 
		string exp;//表达式 
		vector<char> op;//操作符 
		vector<double> num;//操作数
};

#endif	//_CALCULATOR_H_
