#include<iostream>
#include<vector>
#include<map>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* buildTree(
    vector<int>& postorder,
    int postStart,
    int postEnd,
    vector<int>& inorder,
    int inStart,
    int inEnd,
    map<int,int>& inmap
)
{
    if(postStart < postEnd || inStart > inEnd)
        return nullptr;

    // root = current postorder
    TreeNode* root = new TreeNode(postorder[postStart]);

    int inRoot = inmap[root->val];
    int rightSize = inEnd - inRoot;

    // build RIGHT first
    root->right = buildTree(
        postorder,
        postStart - 1,
        postStart - rightSize,
        inorder,
        inRoot + 1,
        inEnd,
        inmap
    );

    // build LEFT
    root->left = buildTree(
        postorder,
        postStart - rightSize - 1,
        postEnd,
        inorder,
        inStart,
        inRoot - 1,
        inmap
    );

    return root;
}
void preorder(TreeNode* root)
{
    if(!root)return ;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right); 
}
int main()
{
    vector<int> inorder   = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    map<int,int> inmap;
    for(int i=0; i<inorder.size(); i++)
        inmap[inorder[i]] = i;

    TreeNode* root = buildTree(
        postorder,
        postorder.size()-1,
        0,
        inorder,
        0,
        inorder.size()-1,
        inmap
    );
    return root;
    
    // preorder(root);
}