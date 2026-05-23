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

    void levelOrderRec(TreeNode* root, int level, vector<vector<int>>& res) {
    if (root == nullptr) return;

    // Add a new level to the result if needed
    if (res.size() <= level)
        res.push_back({});
  
    // Add current node's data to its corresponding level
    res[level].push_back(root->val);

    // Recur for left and right children
    levelOrderRec(root->left, level + 1, res);
    levelOrderRec(root->right, level + 1, res);
}
};
int main()
{
    vector<int> array={3,9,20,-1,-1,15,7};
    TreeBuilder b;
    TreeNode* node=b.Builder(array,0);
    vector<vector<int>> levelOrder;
    b.levelOrderRec(node,0,levelOrder);
int j=1;
 for(auto& num : levelOrder)
{
    if(j%2==0)reverse(num.begin(),num.end());
    for(int i : num)
    {
        cout << i <<" ";
    }
    j++;    
}
}
