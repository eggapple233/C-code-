#include "iostream"
#include "poly.h"
#include "cmath"

Poly::Poly():head(nullptr),n(0){}

Poly::Poly(term* p,int n):head(p),n(n){}

Poly::Poly(vector<vector<double>> arr):n(arr.size()){
	sort(arr.begin(),arr.end(),[](const vector<double>& a,const vector<double>& b){return a[1]>b[1];});
			
	head=new term(arr[0][0],arr[0][1],nullptr);
	auto temp1=head;
			
	for(int i=1;i<n;i++)
	{
		term* temp2=new term(arr[i][0],arr[i][1],nullptr);
		temp1->next=temp2;
		temp1=temp2;
	}
}

Poly::~Poly(){
	term* temp;
	while(head!=nullptr)
	{
		temp=head;
		head=head->next;
		delete temp;
	}
	head=nullptr;
}


void Poly::print1(){
	cout<<"n = "<<noshowpos<<n<<" ";
	int n=0;
	for(term* i=head;i!=nullptr;i=i->next,n++)
	{
		cout<<"{c"<<noshowpos<<n<<" = "<<i->coe<<", e"<<n<<" = "<<i->index<<"} ";
	}
	cout<<endl;
}

void Poly::print2(){
	if(head->coe>0)
	{
		if(head->index>0)
		cout<<noshowpos<<head->coe<<"*x^"<<head->index;
		else
		cout<<noshowpos<<head->coe<<"*x^"<<showpos<<head->index;
	}
	else if(head->coe<0)
	{
		if(head->index>0)
		cout<<showpos<<head->coe<<"*x^"<<noshowpos<<head->index;
		else
		cout<<showpos<<head->coe<<"*x^"<<head->index;
	}
	else 
	{
		int cnt=0;
		for(term* i=head->next;i!=nullptr;i=i->next)
		if(i->coe!=0)
			cnt++;
		
		if(cnt==0)
			cout<<0;
	}
	for(term* i=head->next;i!=nullptr;i=i->next)
	{
		if(i->coe!=0)
		{
			if(head->coe==0)
			{
				if(i->coe>0&&i->index<0)
				cout<<noshowpos<<i->coe<<"*x^"<<showpos<<i->index;
				else if(i->coe>0&&i->index>=0)
				cout<<noshowpos<<i->coe<<"*x^"<<i->index;
				else if(i->coe<0&&i->index<0)
				cout<<showpos<<i->coe<<"*x^"<<i->index;
				else
				cout<<showpos<<i->coe<<"*x^"<<noshowpos<<i->index;
			}
			else
			{
				if(i->coe>0&&i->index<0)
				cout<<showpos<<i->coe<<"*x^"<<i->index;
				else if(i->coe>0&&i->index>=0)
				cout<<showpos<<i->coe<<"*x^"<<noshowpos<<i->index;
				else if(i->coe<0&&i->index<0)
				cout<<showpos<<i->coe<<"*x^"<<i->index;
				else
				cout<<showpos<<i->coe<<"*x^"<<noshowpos<<i->index;
			}
		}
	}
	cout<<endl;
}

Poly Poly::add(Poly& other){
	term* p1=head,*p2=other.head;
	int n=0;
	term* pol3;
	if(p1->index>p2->index)
	{
		pol3=new term(p1->coe,p1->index,nullptr);
		p1=p1->next;
		n++;
	}
	else if(p1->index<p2->index)
	{
		pol3=new term(p2->coe,p2->index,nullptr);
		p2=p2->next;
		n++;
	}
	else
	{
		pol3=new term(p1->coe+p2->coe,p1->index,nullptr);
		p1=p1->next;
		p2=p2->next;
		n++;
	}
	term* temp=pol3;
	while(p1!=nullptr&&p2!=nullptr)
	{
		if(p1->index>p2->index)
		{
			term* temp2=new term(p1->coe,p1->index,nullptr);
			temp->next=temp2;
			temp=temp2;
			p1=p1->next;
			n++;
		}
		else if(p1->index<p2->index)
		{
			term* temp2=new term(p2->coe,p2->index,nullptr);
			temp->next=temp2;
			temp=temp2;
			p2=p2->next;
			n++;
		}
		else
		{
			term* temp2=new term(p1->coe+p2->coe,p1->index,nullptr);
			temp->next=temp2;
			temp=temp2;
			p1=p1->next;
			p2=p2->next;
			n++;
		}
	}
	while(p1!=nullptr)
	{
		term* temp2=new term(p1->coe,p1->index,nullptr);
		temp->next=temp2;
		temp=temp2;
		p1=p1->next;
		n++;
	}
	while(p2!=nullptr)
	{
		term* temp2=new term(p2->coe,p2->index,nullptr);
		temp->next=temp2;
		temp=temp2;
		p2=p2->next;
		n++;
	}
	temp->next=nullptr;
	return Poly(pol3,n);
}

Poly Poly::reduce(Poly& other){
	vector<vector<double>> arr1; 
	for(term* q=other.head;q!=nullptr;q=q->next)
	{
		arr1.push_back({q->coe,q->index});
	}
	Poly temp(arr1);
	for(term* p=temp.head;p!=nullptr;p=p->next)
	{
		p->coe*=(-1);
	}
	return this->add(temp);
}

Poly Poly::mux(Poly& other){
	vector<vector<double>> arr1,arr2;
	for(term* p=head;p!=nullptr;p=p->next)
	{
		for(term* q=other.head;q!=nullptr;q=q->next)
		{
			arr1.push_back({(p->coe)*(q->coe),(p->index)+(q->index)});
		}
	}
	sort(arr1.begin(),arr1.end(),[](const vector<double>& a,const vector<double>& b){return a[1]>=b[1];});
//	for(auto p1=arr1.begin();p1!=arr1.end();p1++)
//	{	
//		cout<<(*p1)[0]<<" "<<(*p1)[1]<<" ; ";
//	}
	for(auto p1=arr1.begin(),p2=p1+1;p2!=arr1.end();)
	{
		if((*p1)[1]==(*p2)[1]&&p2+1!=arr1.end())
		{
			(*p1)[0]+=(*p2)[0];
			p2++;
		}
		else if((*p1)[1]==(*p2)[1]&&p2+1==arr1.end())
		{
			(*p1)[0]+=(*p2)[0];
			p2++;
			arr2.push_back({(*p1)[0],(*p1)[1]});
		}
		else if((*p1)[1]!=(*p2)[1]&&p2+1==arr1.end())
		{
			arr2.push_back({(*p1)[0],(*p1)[1]});
			p1=p2;
			arr2.push_back({(*p1)[0],(*p1)[1]});
			p2++;
		}
		else if((*p1)[1]!=(*p2)[1]&&p2+1!=arr1.end())
		{
			arr2.push_back({(*p1)[0],(*p1)[1]});
			p1=p2;
			p2++;
		}
		
	}
//	for(auto p1=arr2.begin();p1!=arr2.end();p1++)
//	{	
//		cout<<(*p1)[0]<<" "<<(*p1)[1]<<" ; ";
//	}
	return Poly(arr2);
	
}

Poly Poly::diff(){
	vector<vector<double>> arr1; 
	for(term* q=head;q!=nullptr;q=q->next)
	{
		arr1.push_back({q->coe,q->index});
	}
	Poly temp(arr1);
	for(term* p=temp.head;p!=nullptr;p=p->next)
	{
		(p->coe)*=(p->index);
		(p->index)-=1;
	}
	return temp;
}

double Poly::cal(double x){
	double sum=0;
	for(term* p=head;p!=nullptr;p=p->next)
	{
		sum+=(p->coe)*(pow(x,p->index));
	}
	return sum;
}
