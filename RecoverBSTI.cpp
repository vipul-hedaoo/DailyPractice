#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

class TreeBuilder{
public:

    TreeNode* BuildTree(vector<int>& arr, int index)
    {
        if(index >= arr.size() || arr[index] == -1)
            return nullptr;

        TreeNode* node = new TreeNode(arr[index]);

        node->left  = BuildTree(arr, 2*index + 1);
        node->right = BuildTree(arr, 2*index + 2);

        return node;
    }

    void Recover(TreeNode* root,
                 TreeNode*& first,
                 TreeNode*& second,
                 TreeNode*& prev)
    {
        if(root == nullptr) return;

        Recover(root->left, first, second, prev);

        if(prev && root->val < prev->val)
        {
            if(first == nullptr)
                first = prev;

            second = root;
        }

        prev = root;

        Recover(root->right, first, second, prev);
    }

    void Inorder(TreeNode* root)
    {
        if(root == nullptr) return;

        Inorder(root->left);
        cout << root->val << " --> ";
        Inorder(root->right);
    }
};

int main()
{
    vector<int> arr = {3,1,4,-1,-1,2};

    TreeBuilder builder;
    TreeNode* root = builder.BuildTree(arr,0);

    cout << "Before Recover:\n";
    builder.Inorder(root);
    cout <<"null"<< endl;

    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    builder.Recover(root, first, second, prev);

    // ACTUAL FIX
    if(first && second)
        swap(first->val, second->val);

    cout << "After Recover:\n";
    builder.Inorder(root);
    cout<<"null"<<endl;
}