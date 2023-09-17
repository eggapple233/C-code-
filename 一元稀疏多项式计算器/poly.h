#ifndef _POLY_H_ 
#define _POLY_H_
#include "vector"
#include "algorithm"
using namespace std;

struct term{
	double coe;//系数 
	double index;//指数
	term* next;//指向下一个项的指针 
	
	term(double _coe,double _index,term* _next):coe(_coe),index(_index),next(_next){}
};//多项式的项

class Poly{
	public:
		Poly();
		Poly(term* p,int n);//利用头节点创建多项式 
		Poly(vector<vector<double>> arr);//创建一个多项式，保存在head为头结点的链表中 
		~Poly();
		
		void print1();//只打印出系数和指数 
		void print2();//按降幂顺序打印出多项式
		Poly add(Poly& other);//与另一个多项式相加 
		Poly reduce(Poly& other);//与另一个多项式相减 
		Poly mux(Poly& other);//与另一个多项式相乘
		Poly diff();//求导
		double cal(double x);//计算给定x下多项式的值
		
	private:
		term* head;//多项式的第一个项 
		int n;//多项式的项数 
};

#endif //_POLY_H_ 
