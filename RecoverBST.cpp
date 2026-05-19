#include<iostream>
#include<vector>
#include<string>
using namespace std;
class TreeNode{
public:
int val;
TreeNode* left;
TreeNode* Right;
TreeNode(int val){
    this->val=val;
    this->left=nullptr;
    this->Right=nullptr;
}
};
class TreeBuilder{
    public:
    TreeNode* BuildTree(vector<int>& arr,int index){
        if(index>=arr.size()||arr[index]==-1)return nullptr;
        TreeNode* node=new TreeNode(arr[index]);
        node->left=BuildTree(arr,2*index+1);
        node->Right=BuildTree(arr,2*index+2);
        return node;
    }
    
    
    TreeNode* Recover(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& prev){
        if(root==nullptr)return nullptr;
        Recover(root->left, first, second, prev);
        if(prev!=nullptr && root->val < prev->val)
        {
            if(first==nullptr)first=prev;
            second=root;
        }
        prev=root;
        Recover(root->Right, first, second, prev );
        return root;        
    }
    void Inorder(TreeNode* root){
        if(root==nullptr)
        {
            cout<<"null-->";
            return;
        }
        Inorder(root->left);
        cout<<root->val<<"-->";
        Inorder(root->Right);
    }
};
int main()
{
    vector<int> arr={3,1,4,2};
    TreeBuilder builder;
    TreeNode* root=builder.BuildTree(arr,0);
    builder.Inorder(root);
    cout<<endl;
    TreeNode* first=nullptr;
    TreeNode* second=nullptr;
    TreeNode* prev=nullptr;
    TreeNode* root1=builder.Recover(root, first, second, prev);
    builder.Inorder(root1);
}   