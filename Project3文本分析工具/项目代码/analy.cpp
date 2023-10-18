#include "analy.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

vector<int> Text::get_next(string& t){
    int len=t.size();
    vector<int> next(len,0);
    for(int i=1,j=0;i<len;i++)
	{
        while(j>0&&t[i]!=t[j])
		{
            j=next[j-1];
        }
        if(t[i]==t[j]) {
            j++;
        }
        next[i]=j;
    }
    return next;
}

void Text::kmp(string& s,string& t){
    vector<int> next=get_next(t);
    int n=s.size();
    int m=t.size();
    for(int i=0,j=0;i<n;i++)
	{
        while(j>0&&s[i]!=t[j])
		{
            j=next[j-1];
        }
        if(s[i]==t[j])
		{
            j++;
        }
        if(j==m)
		{
			if(!freq[t])
			freq[t]=1;
			else
            freq[t]+=1;
            
            key_count+=1;
            line[t].insert(total_line-1);
            j=next[j-1];
        }
    }
}

Text::Text(ifstream& inFile,int choose):inFile(&inFile),total_line(1),total_word(0),count(0),key_count(0){
	if(choose==1)
	{
		string s,word;
		int i=0,j=0;
		ifstream inFile("cpp_reserved.txt");
		while(getline(inFile,s))
		{
			int len=s.length();
			for(i=0;i<len;)
			{
				while(i<len&&(s[i]==' '||s[i]=='\n'))
				{
					i++;
				}
				if(i==len)
				break;
				else
				{
					j=i;
					while(i<len&&s[i]!=' '&&s[i]!='\n')
					{
						i++;
					}
					word=s.substr(j,i-j);
					dict.insert(word);
//					cout<<word<<" ";
				}
			}
		}
	}
}

Text::Text(ifstream& inFile,ifstream& keyFile):inFile(&inFile),total_line(1),total_word(0),count(0),key_count(0){
		string s,word;
		int i=0,j=0;
		while(getline(keyFile,s))
		{
			int len=s.length();
			for(i=0;i<len;)
			{
				while(i<len&&(s[i]==' '||s[i]=='\n'))
				{
					i++;
				}
				if(i==len)
				break;
				else
				{
					j=i;
					while(i<len&&s[i]!=' '&&s[i]!='\n')
					{
						i++;
					}
					word=s.substr(j,i-j);
					dict.insert(word);
//					cout<<word<<" ";
				}
			}
		}
}
	
void Text::read1(){
	ofstream outFile("Running Log.txt");
	string s;//每次读取一行
	cout<<endl<<"成功读取以下内容："<<endl; 
	cout<<"--------------------------------------"<<endl;
	if(dict.size())
		for(auto cur:dict)
			freq[cur]=0;
	while(getline(*inFile,s,'\n'))
	{
		int temp=total_line++;
		cout<<"第"<<temp<<"行:"<<s<<endl;
		outFile<<"第"<<temp<<"行:"<<s<<endl;
		analy(s);
	}
	total_line--;
	cout<<"--------------------------------------"<<endl;
	outFile<<"--------------------------------------"<<endl;
	
	/*排序输出Top-K的单词*/ 
	vector<pair<string,int>> temp(freq.begin(),freq.end());
	sort(temp.begin(),temp.end(),[](const pair<string,int>& a, const pair<string,int>& b){return a.second>b.second;});
	cout<<"总词数："<<count<<endl; 
	outFile<<"总词数："<<count<<endl; 
	cout<<left<<setw(30)<<"单词"<<left<<setw(10)<<"出现次数"<<left<<setw(10)<<"出现行数"<<endl;
	outFile<<left<<setw(30)<<"单词"<<left<<setw(10)<<"出现次数"<<left<<setw(10)<<"出现行数"<<endl;
	for(auto cur:temp)
	{
		cout<<left<<setw(30)<<cur.first<<left<<setw(10)<<cur.second;
		outFile<<left<<setw(30)<<cur.first<<left<<setw(10)<<cur.second;
		for(auto cur2:line[cur.first])
		{
			cout<<cur2<<" ";
			outFile<<cur2<<" ";
		}
			
		cout<<endl;
		outFile<<endl;
	}
	cout<<"--------------------------------------"<<endl;
	outFile.close();
}


void Text::read2(){
	ofstream outFile("Running Log.txt");
	string s;//每次读取一行
	cout<<endl<<"成功读取以下内容："<<endl; 
	cout<<"--------------------------------------"<<endl;
	if(dict.size())
		for(auto cur:dict)
			freq[cur]=0;
	while(getline(*inFile,s,'\n'))
	{
		int temp=total_line++;
		cout<<"第"<<temp<<"行:"<<s<<endl;
		outFile<<"第"<<temp<<"行:"<<s<<endl;
		kmp_analy(s);
	}
	total_line--;
	cout<<"--------------------------------------"<<endl;
	outFile<<"--------------------------------------"<<endl;
	
	vector<pair<string,int>> temp(freq.begin(),freq.end());
	sort(temp.begin(),temp.end(),[](const pair<string,int>& a, const pair<string,int>& b){return a.second>b.second;});
	cout<<left<<setw(30)<<"保留字符串"<<left<<setw(10)<<"出现次数"<<left<<setw(10)<<"出现行数"<<endl;
	outFile<<left<<setw(30)<<"保留字符串"<<left<<setw(10)<<"出现次数"<<left<<setw(10)<<"出现行数"<<endl;
	for(auto cur:temp)
	{
		cout<<left<<setw(30)<<cur.first<<left<<setw(10)<<cur.second;
		outFile<<left<<setw(30)<<cur.first<<left<<setw(10)<<cur.second;
		for(auto cur2:line[cur.first])
		{
			cout<<cur2<<" ";
			outFile<<cur2<<" ";
		}
			
		cout<<endl;
		outFile<<endl;
	}
	cout<<"--------------------------------------"<<endl;
	outFile.close();
}

void Text::read3(){
	ofstream outFile("Running Log.txt");	
	string s;//每次读取一行
	cout<<endl<<"成功读取以下内容："<<endl; 
	cout<<"--------------------------------------"<<endl;
	if(dict.size())
		for(auto cur:dict)
			freq[cur]=0;
	while(getline(*inFile,s,'\n'))
	{
		int temp=total_line++;
		cout<<"第"<<temp<<"行:"<<s<<endl;
		outFile<<"第"<<temp<<"行:"<<s<<endl;
		int len=s.length();
		int i=0;
		kmp_analy(s);
	}
	total_line--;
	cout<<"--------------------------------------"<<endl;
	outFile<<"--------------------------------------"<<endl;
	
	cout<<"关键词出现次数："<<key_count<<endl;
	outFile<<"关键词出现次数："<<key_count<<endl;
	
	vector<pair<string,int>> temp(freq.begin(),freq.end());
	sort(temp.begin(),temp.end(),[](const pair<string,int>& a, const pair<string,int>& b){return a.second>b.second;});
	cout<<left<<setw(30)<<"关键词"<<left<<setw(10)<<"出现次数"<<left<<setw(10)<<"出现行数"<<endl;
	outFile<<left<<setw(30)<<"关键词"<<left<<setw(10)<<"出现次数"<<left<<setw(10)<<"出现行数"<<endl;
	for(auto cur:temp)
	{
		cout<<left<<setw(30)<<cur.first<<left<<setw(10)<<cur.second;
		outFile<<left<<setw(30)<<cur.first<<left<<setw(10)<<cur.second;
		for(auto cur2:line[cur.first])
		{
			cout<<cur2<<" ";
			outFile<<cur2<<" ";
		}
			
		cout<<endl;
		outFile<<endl;
	}
	cout<<"--------------------------------------"<<endl;
	outFile.close();
}


void Text::analy(string s){
	int len=s.length();
	int i=0,j=0;
	string word;
	for(i=0;i<len;i++)
		s[i]=tolower(s[i]);		
	for(i=0;i<len;)
	{
		while(i<len&&!isalnum(s[i]))
		{
			i++;
		}
		if(i==len)
		break;
		else
		{
			j=i;
			while(i<len&&isalnum(s[i]))
			{
				i++;
			}
			word=s.substr(j,i-j);
			if(freq[word])
				freq[word]+=1;
			else
				freq[word]=1;
			line[word].insert(total_line-1);
			count++;
		}
	}
}

void Text::kmp_analy(string s){
	int len=s.length();
	int i=0,j=0;
//	for(i=0;i<len;i++)
//		s[i]=tolower(s[i]);
	for(auto t:dict)
	{
		kmp(s,t);
	}
	
}


