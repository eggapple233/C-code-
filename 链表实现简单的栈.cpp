#include "iostream"
using namespace std;

/*
创立一个节点node
其中val是值 
    next是指针指向下一个节点 
初始化 val是0，next指向空 
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
创立一个链表list
包括公有成员函数 ：
	list（）初始化
	！list（）所有节点都delete释放空间
	emtpy（）检测链表是否为空，空返回1，非空返回0
	push（int x）将元素x压入栈中
	peek（）返回栈顶的元素
	pop（）弹出栈顶的元素
	print（）按 a->b->c->d的格式输出所有元素，其中a是栈顶 
私有成员：
	head  指向栈顶节点node的指针 
	size  栈内元素个数 
*/ 
class list{
    public:
        list()
        {
            head=new node;//为 head指针分配空间并初始化
            size=0;//初始栈内元素个数为0 
			//cout<<"successfully construct a new stack!" <<endl;
        }
		
        ~list()
        {
            node* temp=head->next;//创建临时指针temp方便delete 
            while(temp!=nullptr)
            {
                head->next=temp->next;
                delete temp;
                temp=head->next;
            } 
            delete head;//head自己也要delete 
            //cout<<"successfully destroy a stack!" <<endl;
        }

        bool empty()
        {
            if(head->next==nullptr)	//判断栈是否为空，即head的next指针是不是指向nullptr 
            return true;
            else
            return false;
        }

        void push(int x)
        {
            node* temp=new node;//创建临时变量temp保存要压入栈的值x 
            temp->val=x;
            temp->next=head->next;//将temp的next指向原来的栈顶（即head->next） 
            head->next=temp;//新的栈顶为temp即（head->next=temp） 
            cout<<"*successflly push "<<x<<" into the stack"<<endl;
            size++;
        }
        
        int peek()//返回栈顶值val，如果为空则返回-1 
        {
            if(head->next!=nullptr)
            return head->next->val;
            else
            return -1;
        }
        
        int search_size()//返回栈元素个数
        {
            return size;
        }
        
        void pop()//弹出栈顶值，记得要delete掉弹出的节点 
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
            cout<<temp->val<<endl;//最后一个值单独打出来 
        }

    private:
        node* head;
        int size; 
};



int main()
{
	list stack;
    int choose=0;//操作代号
	cout<<"欢迎使用蛋果的简单数字栈！"<<endl;
	cout<<"使用说明：目前只支持单个系统给定的栈，无法自己创建栈"<<endl;
	cout<<"          同时，栈内元素仅支持int！"<<endl;
	cout<<"===================功能说明==================="<<endl;
	cout<<"0：退出使用"<<endl;
	cout<<"1：压栈（将一个新元素x压入栈顶）"<<endl;
	cout<<"2：弹出（将栈顶元素弹出）"<<endl;
	cout<<"3：取出栈顶元素"<<endl;
	cout<<"4：打印栈（从栈顶开始打印所有元素）"<<endl;
	cout<<"5：查看目前栈内元素个数"<<endl;
	cout<<"=============================================="<<endl;
	while(cin>>choose&&choose!=0)
	{
		switch(choose)
		{
			case 0 :goto end;
					break;
			case 1 :{
						int x;
						
						cout<<"PLEASE ENTER THE VALUE(INT) YOU WANT TO PUSH：";
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
