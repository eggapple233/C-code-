#include "iostream"
using namespace std;

struct node{
    int val;//数值 
    int pos;//在数组中的编号 
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
        int peek_pos()//方便计算距离的 
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
    int* arr=new int[n];//输入的数据存放在这个数组里 
    int* ans=new int[n];//答案数据存放在这个数组里 

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];//输入数据 
    }

    
    list stack;

    for(int i=n-1;i>=0;i--) //倒序历遍输入的数据的数组 
    {
        if(stack.empty())//为空直接push就可以了 
        {
            stack.push(arr[i],i);
            ans[i]=0;//答案自然为0，因为右边（我们是从右往左历遍的）不会有再大的数了 
        }
        else if(arr[i]>=stack.peek())//如果输入元素大于栈顶元素，说明不是单调的 
        {
            while(arr[i]>=stack.peek())//持续比较，直到栈顶元素大于输入元素 
									   //（这里会有一个最大值100001，就是栈为空的时候）
            {
                stack.pop();//弹出多余无关的数据 
            }

            if(stack.empty())//同上，如果全都弹完了，就可以直接push了 
            {
                ans[i]=0;
                stack.push(arr[i],i);
            }
            else//否则计算相邻两个的pos之差就是距离（因为这是第一个比输入数据大的） 
            {
                ans[i]=stack.peek_pos()-i;//先计算再push，不然只会得到0！ 
                stack.push(arr[i],i);
            }
        }
        else if(arr[i]<=stack.peek())//如果本来输入就小于栈顶，直接就是1了 
        {
            ans[i]=stack.peek_pos()-i;
            stack.push(arr[i],i);
            
        }
    }

    for(int i=0;i<n;i++)
        cout<<ans[i]<<endl;//输出答案就可以了！ 


    delete arr;
    delete ans;//new的动态数组一定要delete释放！
	 
    return 0; 
}
