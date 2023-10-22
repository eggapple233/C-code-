#include <iostream>
#include <vector> 
#include <map> 
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left,*right;
	TreeNode(int val):val(val), left(nullptr), right(nullptr) {}
};

TreeNode* reBuildTree(vector<int> pre, vector<int> mid, map<int,int> hash, int preL, int preR, int inL, int inR)
{
	if(preL>preR)
	return nullptr;
	
	TreeNode* root=new TreeNode(pre[preL]);
	root->left=reBuildTree(pre,mid,hash,preL+1,preL+hash[pre[preL]]-inL,inL,hash[pre[preL]]-1);
	root->right=reBuildTree(pre,mid,hash,preL+hash[pre[preL]]-inL+1,preR,hash[pre[preL]]+1,inR);
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
	print(root->right);
	cout<<root->val<<" ";
}

int main()
{
	int n;
	cin>>n;
	vector<int> pre(n), in(n);
	map<int,int> hash;
	for (int i = 0;i < n;i++)
		cin>>pre[i];
	for (int i = 0;i < n;i++)
	{
		cin>>in[i];
		hash[in[i]]=i;
	}
	
	TreeNode* root=reBuildTree(pre,in,hash,0,n-1,0,n-1);
	print(root);
}
