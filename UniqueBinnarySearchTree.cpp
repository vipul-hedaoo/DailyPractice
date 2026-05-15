// #include<iostream>
// #include<vector>
// using namespace std;

// class TreeNode{
// public:

//     int val = 0;
//     TreeNode* left = nullptr;
//     TreeNode* Right = nullptr;

//     TreeNode(int val){
//         this->val = val;
//     }
// };

// class BinnaryTree{

// public:

//     void UniqueBinaryTree( int n,vector<vector<int>>& ans,vector<int>& temp,int num,TreeNode* root)
//     {
//         if(num > n)
//         {
//             ans.push_back(temp);
//             // return;
//         }
//         if(root->left == nullptr && num<=n)
//         {
//             root->left = new TreeNode(num);
//             temp.push_back(num);
//             UniqueBinaryTree(n,ans,temp,num + 1,root->left);
//             temp.pop_back();
//             // root= nullptr;
//             temp.push_back(-1);
//             UniqueBinaryTree(n,ans,temp,num-1,root->Right);
//         }
//         // num--;
//         if(root->Right == nullptr && num<=n)
//         {
//             root->Right = new TreeNode(num);
//             temp.push_back(num);
//             UniqueBinaryTree(n,ans,temp,num + 1,root->Right);
//             temp.pop_back();
//             root->Right = nullptr;
//             temp.push_back(-1);
//             UniqueBinaryTree(n,ans,temp,num+1,root->left);
//         }
//     }

//     void Preorder(TreeNode* root)
//     {
//         if(root == nullptr)
//             return;

//         cout << root->val << "-->";
//         Preorder(root->left);
//         Preorder(root->Right);
//     }
// };

// int main()
// {
//     vector<int> temp;

//     vector<vector<int>> ans;

//     BinnaryTree tree;

//     TreeNode* root = new TreeNode(1);

//     temp.push_back(1);

//     tree.UniqueBinaryTree(3, ans, temp, 2, root);

//     for(const auto& vec : ans)
//     {
//         for(int i : vec)
//         {
//             cout << i << "-->";
//         }

//         cout << "null" << endl;
//     }
// }




#include<iostream>
#include<vector>
using namespace std;

class TreeNode {

public:

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {

public:

    vector<TreeNode*> BuildTree(int start, int end)
    {
        vector<TreeNode*> trees;

        // Base case
        if(start > end)
        {
            trees.push_back(nullptr);
            return trees;
        }

        // Try every node as root
        for(int i = start; i <= end; i++)
        {
            // Generate all left subtrees
            vector<TreeNode*> leftTrees =
                BuildTree(start, i - 1);

            // Generate all right subtrees
            vector<TreeNode*> rightTrees =
                BuildTree(i + 1, end);

            // Combine all possibilities
            for(TreeNode* left : leftTrees)
            {
                for(TreeNode* right : rightTrees)
                {
                    TreeNode* root = new TreeNode(i);

                    root->left = left;
                    root->right = right;

                    trees.push_back(root);
                }
            }
        }

        return trees;
    }

    vector<TreeNode*> generateTrees(int n)
    {
        if(n == 0)
            return {};

        return BuildTree(1, n);
    }

    void Preorder(TreeNode* root)
    {
        if(root == nullptr)
        {
            cout << "null ";
            return;
        }

        cout << root->val << " ";

        Preorder(root->left);
        Preorder(root->right);
    }
};

int main()
{
    BinaryTree tree;

    vector<TreeNode*> ans =
        tree.generateTrees(3);

    int count = 1;

    for(TreeNode* root : ans)
    {
    
        tree.Preorder(root);

        cout << endl;
    }
}