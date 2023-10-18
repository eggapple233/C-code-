#ifndef _ANALY_H_
#define _ANALY_H_
#include <fstream>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

class Text{
	public: 
		Text(ifstream& inFile,int choose);//���Զ���ؼ���
		Text(ifstream& inFile,ifstream& keyFile);//�Զ���ؼ����ļ� 
		
		void read1();//Ӣ����ĵ��� 
		void read2();//c���Գ������ַ���
		void read3();//�Զ���ؼ��� 
		
		void analy(string s);//����Ӣ��Դ�ı� 
		void kmp_analy(string s);//KMP�㷨ƥ�� 
		
	private:
		set<string> dict;//�ִʱ� 
		unordered_map<string,set<int>> line;//��¼���ֵ����� 
		unordered_map<string,int> freq;//��¼���ֵĴ���
		int total_line;//������
		int total_word;//�ܴ���
		int key_count;//�ؼ����� 
		int count;//�ܴ��� 
		ifstream* inFile;//�ݴ������� 
		
		vector<int> get_next(string& pattern);
		void kmp(string& s,string& t);
};

#endif //_ANALY_H_
