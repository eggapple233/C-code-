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
		
		int priority(char a,char b);//�ж����ȼ� 
		void op_push(char b);//��������ջ 
		void run();//ִ�м��� 
		void print(string str);//����������� 
	private:
		int cnt; //��¼������ 
		string mes;//��¼���� 
		string exp;//���ʽ 
		vector<char> op;//������ 
		vector<double> num;//������
};

#endif	//_CALCULATOR_H_
