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
		Text(ifstream& inFile,int choose);//无自定义关键词
		Text(ifstream& inFile,ifstream& keyFile);//自定义关键词文件 
		
		void read1();//英语短文单词 
		void read2();//c语言程序保留字符串
		void read3();//自定义关键词 
		
		void analy(string s);//分析英语源文本 
		void kmp_analy(string s);//KMP算法匹配 
		
	private:
		set<string> dict;//分词表 
		unordered_map<string,set<int>> line;//记录出现的行数 
		unordered_map<string,int> freq;//记录出现的次数
		int total_line;//总行数
		int total_word;//总词数
		int key_count;//关键词数 
		int count;//总词数 
		ifstream* inFile;//暂存输入流 
		
		vector<int> get_next(string& pattern);
		void kmp(string& s,string& t);
};

#endif //_ANALY_H_
