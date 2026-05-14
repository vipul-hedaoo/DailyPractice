#include<iostream>
#include<vector>
#include<string>
using namespace std;
class TreeNode{
public:
    int val=0;
    TreeNode* left=nullptr;
    TreeNode* Right=nullptr;

    TreeNode(int val){
      this->val = val;
      this->left = nullptr;
      this->Right = nullptr;
   }
 };
 class BinnaryTree{
    public:
   TreeNode* BuildTree(vector<int>& arr,int index){
    if(index>=arr.size()||arr[index]==-1)return nullptr;
    TreeNode* node=new TreeNode(arr[index]);
    node->left=BuildTree(arr,2*index+1);
    node->Right=BuildTree(arr,2*index+2);
    return node;
   }
   void Preorder(TreeNode* root){
    if(root==nullptr)return;
    cout<<root->val<<"-->";
    Preorder(root->left);
    Preorder(root->Right);
   }
   void Inorder(vector<int>& ans,TreeNode* root)
    {
        if(root==nullptr)return;
        Inorder(ans,root->left);
        ans.push_back(root->val);
        Inorder(ans,root->Right);
    }
 };
 int main()
 {
    vector<int> arr={1,2,3,4,5,6,7,-1,-1,-1,-1,-1,-1,-1,8};
    BinnaryTree tree;
    TreeNode* root=tree.BuildTree(arr,0);
    tree.Preorder(root);
    cout<<"null"<<endl;
    vector<int>ans;
    tree.Inorder(ans,root);
    for(int i:ans)
    {
        cout<<i<<"-->";
    }
    cout<<"null"<<endl;
 }
