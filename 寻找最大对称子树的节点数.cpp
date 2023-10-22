#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode* left,TreeNode* right)
{
    if(!left&&!right)
    return true;
    if(!left||!right)
    return false;

    return left->val==right->val&&isSymmetric(left->left,right->right)&&isSymmetric(left->right,right->left);
}   

int findnumber(TreeNode* root)
{
    if(!root)
    return 0;
    return findnumber(root->left)+findnumber(root->right)+1;
}

int findmax(TreeNode* root)
{
    if(isSymmetric(root,root))
        return findnumber(root);
    else
        return max(findmax(root->left), findmax(root->right));
}

void print(TreeNode* root)
{
    if(!root)
    {
        cout<<"# ";
        return;
    }
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

int main()
{
    int n;
    cin>>n;
    int arr[n]={};
    TreeNode* nodearr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        nodearr[i]=new TreeNode(arr[i]);
    }
    int ri,li;
    for(int i=0;i<n;i++)
    {
        cin>>li>>ri;
        if(li!=-1)
        {
            nodearr[i]->left=nodearr[li-1];
        }
        if(ri!=-1)
        {
            nodearr[i]->right=nodearr[ri-1];
        }
    }
    TreeNode* root=nodearr[0];
    // print(root);
    cout<<findmax(root);
}
