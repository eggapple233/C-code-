#include "iostream"
using namespace std;

struct node{
	int val;
	node* next;
	
	node(){
		val=0;
		next=nullptr;
	}
	node(int x){
		val=x;
		next=nullptr;
	}
};

class list{
	public:
		list(){
			size=0;
			front=new node;
			front->next=nullptr;
			rear=front;
		}
		
		~list(){
			node* temp=front;
			while(front!=nullptr)
			{
				temp=front;
				front=front->next;
				delete temp;
			}
		}
		
		void enqueue(int x)
		{
				node* temp=new node(x);
				temp->next=nullptr;
				rear->next=temp;
				rear=temp;
				size++;
				cout<<"successfully add "<<x<<" to the queue!"<<endl;

		}
		
		void dequeue()
		{
			if(!empty())
			{
				if(front->next==rear)
				rear=front;
				cout<<"successfully delete "<<front->next->val<<" from the queue!"<<endl;
				node* temp=front->next;
				front->next=temp->next;
				delete temp; 
				size--;
				
				
			}
			else
			{
				cout<<"sorry,the queue is empty!"<<endl;
			}
		}
		
		int get_front()
		{
			return front->next->val;
		}
		
		int get_rear()
		{
			return rear->val;
		}
		
		int get_size()
		{
			return size;
		}
		
		bool empty()
		{
			if(size!=0)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		
		void print()
		{
			if(empty())
			{
				cout<<"sorry,the queue is empty so can not print anything!"<<endl;
			}
			else
			{
				node* temp=front->next;
				cout<<"now print the queue from \"front\" to \"rear\": ";
				while(temp->next!=nullptr)
				{
					cout<<temp->val<<" -> ";
					temp=temp->next;
				}
				cout<<temp->val<<endl;
			}
		}
	private:
		int size;
		node* front;
		node* rear;
};

int main()
{
	list queue;
    int choose=0;
	cout<<"��ӭʹ�õ����ļ����ֶ��У�"<<endl;
	cout<<"ʹ��˵����Ŀǰֻ֧�ֵ���ϵͳ�����Ķ��У��޷��Լ���������"<<endl;
	cout<<"          ͬʱ��������Ԫ�ؽ�֧��int��"<<endl;
	cout<<"===================����˵��==================="<<endl;
	cout<<"0���˳�ʹ��"<<endl;
	cout<<"1����һ��Ԫ�ط������β��"<<endl;
	cout<<"2����һ��Ԫ�شӶ���ͷ������"<<endl;
	cout<<"3���鿴��ͷԪ��"<<endl;
	cout<<"4���鿴��βԪ��"<<endl;
	cout<<"5���鿴Ŀǰ����Ԫ���ܸ���"<<endl;
	cout<<"6����˳���ӡ��������Ԫ��"<<endl;
	cout<<"=============================================="<<endl;
	while(cin>>choose&&choose!=0)
	{
		switch(choose)
		{
			case 0 :goto end;
					break;
			case 1 :{
						int x;
						
						cout<<"PLEASE ENTER THE VALUE(INT) YOU WANT TO ENTER��";
						cin>>x;
						
						queue.enqueue(x);
						break;
						
					}
			case 2 :{
						queue.dequeue();
						break;
					}
			case 3 :{
						if(!queue.empty())
						cout<<"the front value of the queue is :"<<queue.get_front()<<endl;
						else
						cout<<"ERROR!THE QUEUE IS EMPTY!"<<endl;
						break;
					}
			case 4 :{
						if(!queue.empty())
						cout<<"the rear value of the queue is :"<<queue.get_rear()<<endl;
						else
						cout<<"ERROR!THE QUEUE IS EMPTY!"<<endl;
						break;
					}
			case 5 :{
						cout<<"the number of the values in the queue is :"<<queue.get_size()<<endl;
						break;
					}
			case 6 :{
						if(!queue.empty())
						queue.print();
						else
						cout<<"ERROR!THE QUEUE IS EMPTY!"<<endl;
						break;
					}
			default:{
				cout<<"PLEASE ENTER THE VALID NUMBER!"<<endl;
				break;
			}
		} 
	}
	end:
	cout<<"Have a nice day! :D ";	 
}
