#include "iostream"
using namespace std;

bool empty(int head,int tail);
bool full(int head,int tail,int size);

void enqueue(int x,int queue[],int& head,int& tail,int size)
{
	if(!full(head,tail,size))
	{
		if(tail<size-1)
		{
			queue[tail++]=x;
			cout<<"successfully push "<<x<<" in the tail"<<endl;
		}
		else
		{
			queue[tail]=x;
			tail=0;
			cout<<"successfully push "<<x<<" in the tail"<<endl;
		}
	}
	else
	{
		cout<<"sorry,the queue is full now!"<<endl;
	}
}

void dequeue(int queue[],int& head,int& tail,int size)
{
		if(head<size-1)
		{
			head++;
			cout<<"successfully pop "<<queue[head-1]<<" in the tail"<<endl;
		}
		else
		{
			head=(head+1)%size;
			cout<<"successfully pop "<<queue[size-1]<<" in the tail"<<endl;
		}
}

void print(int queue[],int head,int tail,int size)
{
		cout<<"now print the whole queue : ";
		if(tail>head)
		{
			for(int i=head;i<tail-1;i++)
			{
				cout<<queue[i]<<" -> ";
			}
			cout<<queue[tail-1]<<endl;
		}
		else if(tail==0)
		{
			for(int i=head;i<size-1;i++)
			{
				cout<<queue[i]<<" -> ";
			}
			cout<<queue[size-1]<<endl;
		}
		else
		{
			for(int i=head;i<size;i++)
			{
				cout<<queue[i]<<" -> ";
			}
			for(int i=0;i<tail-1;i++)
			{
				cout<<queue[i]<<" -> ";
			}
			cout<<queue[tail-1]<<endl;
		}
}

bool empty(int head,int tail)
{
	if(head==tail)
	return true;
	else
	return false;
}

bool full(int head,int tail,int size)
{
	if((tail+1)%size==head)
	return true;
	else
	return false;
}

int get_head(int queue[],int head)
{
	return queue[head];
}

int get_tail(int queue[],int tail,int size)
{
	if(tail!=0)
	{
		return queue[tail-1];	
	}
	else
	{
		return queue[size-1];
	}
	
}


int main()
{
	int size=0;
    int choose=0;//操作代号
	cout<<"欢迎使用蛋果的简单循环数字队列！"<<endl;
	cout<<"使用说明:栈内元素仅支持int！"<<endl;
	start:
	cout<<"请输入数字队列大小（1~500000）：";
	cin>>size;
	
	if(size<=0||size>500000)
	{
		cout<<"INVALID NUMBER!"<<endl;
		goto start;
	}
	
	int queue[++size];
	int head=0,tail=0;
	cout<<"成功创建队列！"<<endl<<endl;
	
	cout<<"===================功能说明==================="<<endl;
	cout<<"0：退出使用"<<endl;
	cout<<"1：将新元素置于队尾"<<endl;
	cout<<"2：将队头元素弹出"<<endl;
	cout<<"3：查看队头元素"<<endl;
	cout<<"4：查看队尾元素"<<endl;
	cout<<"5：打印队列所有元素"<<endl;
	cout<<"=============================================="<<endl;
	while(cin>>choose&&choose!=0)
	{
		switch(choose)
		{
			case 0 :goto end;
					break;
			case 1 :{
						if(!full(head,tail,size))
						{
							int x;
							cout<<"PLEASE ENTER THE VALUE(INT) YOU WANT TO PUSH：";
							cin>>x;
							enqueue(x,queue,head,tail,size);
						}
						else
						cout<<"ERROR!THE QUEUE IS FULL!"<<endl;
						break;
					}
			case 2 :{
						if(!empty(head,tail))
						dequeue(queue,head,tail,size);
						else
						cout<<"ERROR!THE QUEUE IS EMPTY!"<<endl;
						break;
					}
			case 4 :{
						if(!empty(head,tail))
						cout<<"the value of the tail is :"<<get_tail(queue,tail,size)<<endl;
						else
						cout<<"ERROR!THE QUEUE IS EMPTY!"<<endl;
						break;
					}
			case 3 :{
						if(!empty(head,tail))
						cout<<"the value of the head is :"<<get_head(queue,head)<<endl;
						else
						cout<<"ERROR!THE QUEUE IS EMPTY!"<<endl;
						break;
					}
			case 5 :{
						if(!empty(head,tail))
						print(queue,head,tail,size);
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
