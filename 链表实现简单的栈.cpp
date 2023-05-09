#include "iostream"
using namespace std;

/*
����һ���ڵ�node
����val��ֵ 
    next��ָ��ָ����һ���ڵ� 
��ʼ�� val��0��nextָ��� 
*/
struct node{
    int val;
    node* next;

    node()
    {
        val=0;
        next=nullptr;
    }
};

/*
����һ������list
�������г�Ա���� ��
	list������ʼ��
	��list�������нڵ㶼delete�ͷſռ�
	emtpy������������Ƿ�Ϊ�գ��շ���1���ǿշ���0
	push��int x����Ԫ��xѹ��ջ��
	peek��������ջ����Ԫ��
	pop��������ջ����Ԫ��
	print������ a->b->c->d�ĸ�ʽ�������Ԫ�أ�����a��ջ�� 
˽�г�Ա��
	head  ָ��ջ���ڵ�node��ָ�� 
	size  ջ��Ԫ�ظ��� 
*/ 
class list{
    public:
        list()
        {
            head=new node;//Ϊ headָ�����ռ䲢��ʼ��
            size=0;//��ʼջ��Ԫ�ظ���Ϊ0 
			//cout<<"successfully construct a new stack!" <<endl;
        }
		
        ~list()
        {
            node* temp=head->next;//������ʱָ��temp����delete 
            while(temp!=nullptr)
            {
                head->next=temp->next;
                delete temp;
                temp=head->next;
            } 
            delete head;//head�Լ�ҲҪdelete 
            //cout<<"successfully destroy a stack!" <<endl;
        }

        bool empty()
        {
            if(head->next==nullptr)	//�ж�ջ�Ƿ�Ϊ�գ���head��nextָ���ǲ���ָ��nullptr 
            return true;
            else
            return false;
        }

        void push(int x)
        {
            node* temp=new node;//������ʱ����temp����Ҫѹ��ջ��ֵx 
            temp->val=x;
            temp->next=head->next;//��temp��nextָ��ԭ����ջ������head->next�� 
            head->next=temp;//�µ�ջ��Ϊtemp����head->next=temp�� 
            cout<<"*successflly push "<<x<<" into the stack"<<endl;
            size++;
        }
        
        int peek()//����ջ��ֵval�����Ϊ���򷵻�-1 
        {
            if(head->next!=nullptr)
            return head->next->val;
            else
            return -1;
        }
        
        int search_size()//����ջԪ�ظ���
        {
            return size;
        }
        
        void pop()//����ջ��ֵ���ǵ�Ҫdelete�������Ľڵ� 
        {   
			cout<<"*successflly pop "<<head->next->val<<" out of the stack"<<endl;
            node* temp=head->next;
            head->next=temp->next;
            delete temp;
            size--;
        }
        
        void print()
        {
        	cout<<"*now print the stack starting with the top :"<<endl;
            node* temp=head->next;
            while(temp->next!=nullptr)
            {   
                cout<<temp->val<<"->";
                temp=temp->next;
            }
            cout<<temp->val<<endl;//���һ��ֵ��������� 
        }

    private:
        node* head;
        int size; 
};



int main()
{
	list stack;
    int choose=0;//��������
	cout<<"��ӭʹ�õ����ļ�����ջ��"<<endl;
	cout<<"ʹ��˵����Ŀǰֻ֧�ֵ���ϵͳ������ջ���޷��Լ�����ջ"<<endl;
	cout<<"          ͬʱ��ջ��Ԫ�ؽ�֧��int��"<<endl;
	cout<<"===================����˵��==================="<<endl;
	cout<<"0���˳�ʹ��"<<endl;
	cout<<"1��ѹջ����һ����Ԫ��xѹ��ջ����"<<endl;
	cout<<"2����������ջ��Ԫ�ص�����"<<endl;
	cout<<"3��ȡ��ջ��Ԫ��"<<endl;
	cout<<"4����ӡջ����ջ����ʼ��ӡ����Ԫ�أ�"<<endl;
	cout<<"5���鿴Ŀǰջ��Ԫ�ظ���"<<endl;
	cout<<"=============================================="<<endl;
	while(cin>>choose&&choose!=0)
	{
		switch(choose)
		{
			case 0 :goto end;
					break;
			case 1 :{
						int x;
						
						cout<<"PLEASE ENTER THE VALUE(INT) YOU WANT TO PUSH��";
						cin>>x;
						
						stack.push(x);
						break;
						
					}
			case 2 :{
						stack.pop();
						break;
					}
			case 3 :{
						if(!stack.empty())
						cout<<"the value of the top is :"<<stack.peek()<<endl;
						else
						cout<<"ERROR!THE STACK IS EMPTY!"<<endl;
						break;
					}
			case 4 :{
						if(!stack.empty())
						stack.print();
						else
						cout<<"ERROR!THE STACK IS EMPTY!"<<endl;
						break;
					}
			case 5 :{
						cout<<"the number of the values in the stack is :"<<stack.search_size()<<endl;
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
