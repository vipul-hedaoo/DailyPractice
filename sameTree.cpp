#include<iostream>
#include<vector>
#include<string>
using namespace std;
class TreeNode{
public:
    int val=0;
    TreeNode* left=nullptr;
    TreeNode* right=nullptr;

    TreeNode(int val){
        this->val=val;
        left=nullptr;
        right=nullptr;
    }
};
bool SameTree(TreeNode* root1,TreeNode* root2)
{
    if(root1==nullptr && root2==nullptr)
    {
        return true;
    }
    else if(root1==nullptr || root2==nullptr)
    {
        return false;
    }
    if(root1->val!=root2->val)
    {
        return false;
    }
    return SameTree(root1->left,root2->left) && SameTree(root1->right,root2->right);
}
class builder{
    public :
    TreeNode* buildTree(vector<int>& array, int index)
    {
        if(index>=array.size()|| array[index]==-1) return nullptr;
        TreeNode* node =new TreeNode(array[index]);
        node->left=buildTree(array,2*index+1);
        node->right=buildTree(array,2*index+2);
        return node;
    }
};
int main()
{
    vector<int> array={1,2,3};
    vector<int> array2={1,3,3};
    builder b;
    TreeNode* root1=b.buildTree(array,0);
    TreeNode* root2=b.buildTree(array2,0);
    cout<<SameTree(root1,root2)<<endl;
}