#include "iostream"
using namespace std;

struct node{
    int val;//��ֵ 
    int pos;//�������еı�� 
    node* next;

    node()
    {
        pos=0;
        val=0;
        next=nullptr;
    }
};

class list{
    public:
        list()
        {
            head=new node;
        }

        ~list()
        {
            node* temp=head->next;
            while(temp!=nullptr)
            {
                head->next=temp->next;
                delete temp;
                temp=head->next;
            }
            delete head;
        }

        bool empty()
        {
            if(head->next==nullptr)
            return true;
            else
            return false;
        }

        void push(int x,int pos)
        {
            node* temp=new node;
            temp->val=x;
            temp->pos=pos;
            temp->next=head->next;
            head->next=temp;
            //cout<<"successflly push "<<x<<" into the stack"<<endl;
        }
        int peek()
        {
            if(head->next!=nullptr)
            return head->next->val;
            else
            return 100001;
        }
        int peek_pos()//����������� 
        {
            if(head->next!=nullptr)
            return head->next->pos;
            else
            return 0;
        }
        void pop()
        {
            node* temp=head->next;
            head->next=temp->next;
            delete temp;
            //cout<<"successflly pop"<<endl;
        }
        void print()
        {
            node* temp=head->next;
            while(temp!=nullptr)
            {   
                cout<<temp->val<<"->";
                temp=temp->next;
            }
            //cout<<"empty"<<endl;
        }

    private:
        node* head;
};



int main()
{
    int n;
    cin>>n;
    int* arr=new int[n];//��������ݴ������������� 
    int* ans=new int[n];//�����ݴ������������� 

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];//�������� 
    }

    
    list stack;

    for(int i=n-1;i>=0;i--) //����������������ݵ����� 
    {
        if(stack.empty())//Ϊ��ֱ��push�Ϳ����� 
        {
            stack.push(arr[i],i);
            ans[i]=0;//����ȻΪ0����Ϊ�ұߣ������Ǵ�����������ģ��������ٴ������ 
        }
        else if(arr[i]>=stack.peek())//�������Ԫ�ش���ջ��Ԫ�أ�˵�����ǵ����� 
        {
            while(arr[i]>=stack.peek())//�����Ƚϣ�ֱ��ջ��Ԫ�ش�������Ԫ�� 
									   //���������һ�����ֵ100001������ջΪ�յ�ʱ��
            {
                stack.pop();//���������޹ص����� 
            }

            if(stack.empty())//ͬ�ϣ����ȫ�������ˣ��Ϳ���ֱ��push�� 
            {
                ans[i]=0;
                stack.push(arr[i],i);
            }
            else//�����������������pos֮����Ǿ��루��Ϊ���ǵ�һ�����������ݴ�ģ� 
            {
                ans[i]=stack.peek_pos()-i;//�ȼ�����push����Ȼֻ��õ�0�� 
                stack.push(arr[i],i);
            }
        }
        else if(arr[i]<=stack.peek())//������������С��ջ����ֱ�Ӿ���1�� 
        {
            ans[i]=stack.peek_pos()-i;
            stack.push(arr[i],i);
            
        }
    }

    for(int i=0;i<n;i++)
        cout<<ans[i]<<endl;//����𰸾Ϳ����ˣ� 


    delete arr;
    delete ans;//new�Ķ�̬����һ��Ҫdelete�ͷţ�
	 
    return 0; 
}
