#include<iostream>
#include<queue>
#include<vector>
#include <algorithm>
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
class TreeBuilder{
    public:
    TreeNode* Builder(vector<int>& array,int index)
    {
        if(index >= array.size() || array[index]==-1) return nullptr;
        TreeNode* node=new TreeNode(array[index]);
        node->left=Builder(array,2*index+1);
        node->right=Builder(array,2*index+2);
        return node;
    }

    int maxdepth(TreeNode* root , int dep)
    {
        if(root==nullptr)return dep;
       return max(maxdepth(root->left,dep+1),maxdepth(root->right,dep+1));
    }
};
int main()
{
    vector<int> array={3,9,20,-1,-1,15,7};
    TreeBuilder b;
    TreeNode* node=b.Builder(array,0);
    cout<<b.maxdepth(node,0);
}