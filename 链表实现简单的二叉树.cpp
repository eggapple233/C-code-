#include "iostream"
#include "string"
using namespace std; 

struct Btree{
	string val;
	Btree* left;
	Btree* right;
	
	Btree():val("."),left(nullptr),right(nullptr){}
	Btree(string x):val(x),left(nullptr),right(nullptr){}
};

struct node{
	Btree* val;
	node* next;
	
	node(){
		val=nullptr;
		next=nullptr;
	}
	node(Btree* x){
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
		
		void enqueue(Btree* root)
		{
				node* temp=new node(root);
				temp->next=nullptr;
				rear->next=temp;
				rear=temp;
				size++;
				//cout<<"successfully add "<<x<<" to the queue!"<<endl;

		}
		
		void dequeue()
		{
			if(!empty())
			{
				if(front->next==rear)
				rear=front;
				//cout<<"successfully delete "<<front->next->val<<" from the queue!"<<endl;
				node* temp=front->next;
				front->next=temp->next;
				delete temp; 
				size--;
				
			}
			else
			{
				//cout<<"sorry,the queue is empty!"<<endl;
			}
		}
		
		Btree* get_front()
		{
			return front->next->val;
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

	private:
		int size;
		node* front;
		node* rear;
};


Btree* CreateRoot()
{
	string x;
	cout<<"Please input the value of the root:"<<endl;
	cin>>x;
	Btree* root = new Btree(x);
	return root;
}


void CreateBtree(Btree*& root)
{
	if(root->val!=".")
	{
		string value;
		
		cout<<"Please input the left value:"<<endl;
		cin>>value;
		if(value!=".")
		{
			Btree* left=new Btree(value);
			root->left=left;
			CreateBtree(left);
		}
			
		cout<<"Please input the right value:"<<endl;
		cin>>value;
		if(value!=".")
		{
			Btree* right=new Btree(value);
			root->right=right;
			CreateBtree(right);
		}
	}
	return;
}

void Print1(Btree* root)
{
	if(root!=nullptr&&root->val!=".")
	{
		cout<<root->val<<" ";
		Print1(root->left);
		Print1(root->right);
	}
	return;
}

void Print2(Btree* root)
{
	if(root!=nullptr&&root->val!=".")
	{
		Print2(root->left);	
		cout<<root->val<<" ";
		Print2(root->right);
	}
	return;
}


void Print3(Btree* root)
{
	if(root!=nullptr&&root->val!=".")
	{
		Print3(root->left);
		Print3(root->right);
		cout<<root->val<<" ";
	}
	return;
}

void Print4(Btree* root)
{
	list queue;
	queue.enqueue(root);
	while(!queue.empty())
	{	
		Btree* temp=queue.get_front();
		cout<<temp->val<<" ";
		
		if(temp->left!=nullptr)
		{
			queue.enqueue(temp->left);
		}
		
		if(temp->right!=nullptr)
		{
			queue.enqueue(temp->right);
		}
		
		queue.dequeue();
	}
}

void DeleteBtree(Btree*& root)
{
	if(root->left!=nullptr)
	{
		DeleteBtree(root->left);
	}
	if(root->right!=nullptr)
	{
		DeleteBtree(root->right);
	}
	delete root;
	root=nullptr;
	return;
}

int main()
{   
    Btree* root=nullptr;
	int choose=0;
	cout<<"===================功能说明==================="<<endl;
	cout<<"0:退出使用"<<endl;
	cout<<"1:创建二叉树"<<endl;
	cout<<"2:先序打印二叉树"<<endl;
	cout<<"3:中序打印二叉树"<<endl;
	cout<<"4:后序打印二叉树"<<endl;
	cout<<"5:层序打印二叉树"<<endl;
	cout<<"6:删除二叉树"<<endl;
	cout<<"=============================================="<<endl;
	while(cin>>choose)
	{
		
		switch(choose)
		{
			case 0: goto end;
					break;

			case 1: if(root==nullptr)
					{
						root=CreateRoot();
						CreateBtree(root);
						cout<<"Successfully create the Btree!"<<endl<<endl;
					}
					else
					{
						cout<<"You have created a Btree, please delete it before create another one."<<endl;
						cout<<endl<<endl;
					}
					break;
					
			case 2: if(root!=nullptr)
					{
						if(root->val!=".")
						{
							Print1(root);
							cout<<endl<<endl;
						}
						else
						{
							cout<<"(The tree is empty :o )"<<endl;
						    cout<<endl<<endl;
						}
					}
					else
					{
						cout<<"You haven't created a Btree, please create it before print it."<<endl;
						cout<<endl<<endl;
					}
					break;
					
			case 3: if(root!=nullptr)
					{
						if(root->val!=".")
						{
							Print2(root);
							cout<<endl<<endl;
						}
						else
						{
							cout<<"(The tree is empty :o )"<<endl;
						    cout<<endl<<endl;
						}
					}
					else
					{
						cout<<"You haven't created a Btree, please create it before print it."<<endl;
						cout<<endl<<endl;
					}
					break;
					
			case 4: if(root!=nullptr)
					{
						if(root->val!=".")
						{
							Print3(root);
							cout<<endl<<endl;
						}
						else
						{
							cout<<"(The tree is empty :o )"<<endl;
						    cout<<endl<<endl;
						}
					}
					else
					{
						cout<<"You haven't created a Btree, please create it before print it."<<endl;
						cout<<endl<<endl;
					}
					break;
					
			case 5: if(root!=nullptr)
					{
						if(root->val!=".")
						{
							Print4(root);
							cout<<endl<<endl;
						}
						else
						{
							cout<<"(The tree is empty :o )"<<endl;
						    cout<<endl<<endl;
						}
					}
					else
					{
						cout<<"You haven't created a Btree, please create it before print it."<<endl;
						cout<<endl<<endl;
					}
					break;
			
			case 6: if(root!=nullptr)
					{
						DeleteBtree(root);
						cout<<"Successfully delete the Btree!"<<endl<<endl;
					}
					else
					{
						cout<<"You haven't created a Btree, please create it before delete it."<<endl;
						cout<<endl<<endl;
					}
					break;
				
			default:cout<<"Invalid Number!Please try again."<<endl;
					cout<<endl<<endl;
		}
		cout<<"===================功能说明==================="<<endl;
		cout<<"0:退出使用"<<endl;
		cout<<"1:创建二叉树"<<endl;
		cout<<"2:先序打印二叉树"<<endl;
		cout<<"3:中序打印二叉树"<<endl;
		cout<<"4:后序打印二叉树"<<endl;
		cout<<"5:层序打印二叉树"<<endl;
		cout<<"6:删除二叉树"<<endl;
		cout<<"=============================================="<<endl;
	}
	
	end:
		cout<<"see you next time :D";
}
