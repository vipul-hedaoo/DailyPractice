#include<iostream>
#include<vector>
#include<map>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val)
    {
        this->val=val;
        left=nullptr;
        right=nullptr;
    }
};
// class TreeBuilder{
//     TreeNode* Builder(vector<int>arr,int index)
//     {
//         if(arr.size()<=index || arr[index]==-1) return nullptr;
//         TreeNode* node= new TreeNode(arr[index]);
//         node->left=Builder(arr,2*index+1);
//         node->right=Builder(arr,2*index+2);
//         return node;
//     }
// };

class TreeBuilder{
public:
      TreeNode* buildTree1(
    vector<int>& preorder,
    int prestart,
    int preend,
    vector<int>& inorder,
    int instart,
    int inend,
    map<int,int>& inmap
)
{
    if(prestart > preend || instart > inend)
        return nullptr;

    TreeNode* root = new TreeNode(preorder[prestart]);

    int inroot = inmap[root->val];
    int numleft = inroot - instart;

    root->left = buildTree1(
        preorder,
        prestart + 1,
        prestart + numleft,
        inorder,
        instart,
        inroot - 1,
        inmap
    );

    root->right = buildTree1(
        preorder,
        prestart + numleft + 1,
        preend,
        inorder,
        inroot + 1,
        inend,
        inmap
    );

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    map<int,int> inmap;

    for(int i = 0; i < inorder.size(); i++)
        inmap[inorder[i]] = i;

    return buildTree1(
        preorder,
        0,
        preorder.size() - 1,
        inorder,
        0,
        inorder.size() - 1,
        inmap
    );
}
};
int main()
{
    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};
    TreeBuilder b;
    TreeNode* Root=b.buildTree(preorder,inorder);
    cout<<Root->val;

}