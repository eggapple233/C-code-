#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ~TreeNode(){
    	if(left)
    		delete left;
    	if(right)
    		delete right;
	}
};

TreeNode* InsertBST(TreeNode* root, int val)
{
	if(!root)
	{
		root=new TreeNode(val);
		return root;
	}
		
	if(val<root->val)
		root->left=InsertBST(root->left, val);
	else
		root->right=InsertBST(root->right, val);
	return root;
}

TreeNode* BuildBST(TreeNode* root, vector<int> arr)
{
	for(auto cur:arr)
	{
		root=InsertBST(root,cur);
	}
	return root;
}

void print(TreeNode* root)
{
	if(!root)
	{
		cout<<"# ";
		return;
	}
	
	print(root->left);
	cout<<root->val<<" ";
	print(root->right);
	
}

int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	TreeNode* root=nullptr;
	for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
	root=BuildBST(root,arr);
	print(root);
	cout<<endl;
	print(root);
	delete root;
}
