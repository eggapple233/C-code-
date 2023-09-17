#ifndef _POLY_H_ 
#define _POLY_H_
#include "vector"
#include "algorithm"
using namespace std;

struct term{
	double coe;//ϵ�� 
	double index;//ָ��
	term* next;//ָ����һ�����ָ�� 
	
	term(double _coe,double _index,term* _next):coe(_coe),index(_index),next(_next){}
};//����ʽ����

class Poly{
	public:
		Poly();
		Poly(term* p,int n);//����ͷ�ڵ㴴������ʽ 
		Poly(vector<vector<double>> arr);//����һ������ʽ��������headΪͷ���������� 
		~Poly();
		
		void print1();//ֻ��ӡ��ϵ����ָ�� 
		void print2();//������˳���ӡ������ʽ
		Poly add(Poly& other);//����һ������ʽ��� 
		Poly reduce(Poly& other);//����һ������ʽ��� 
		Poly mux(Poly& other);//����һ������ʽ���
		Poly diff();//��
		double cal(double x);//�������x�¶���ʽ��ֵ
		
	private:
		term* head;//����ʽ�ĵ�һ���� 
		int n;//����ʽ������ 
};

#endif //_POLY_H_ 
