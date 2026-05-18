#include<iostream>
#include<vector>
#include<climits>
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
   bool isValidBST(TreeNode* root){
    if(root==nullptr || root->left==nullptr && root->Right==nullptr)return true;
    if(root->left->val < root->val && root->Right->val > root->val)
    {
        return isValidBST(root->left) && isValidBST(root->Right);
    }
    else{
        return false;
    }
   }

   bool isvalidbinnarytree(TreeNode* root,int min ,int max)
   {
    if(root==nullptr)return true;
    if(root->val <= min ||
           root->val >= max)
        {
            return false;
        }
    return isvalidbinnarytree(root->left, min, root->val) &&
           isvalidbinnarytree(root->Right, root->val, max);
   }
 };
 int main()
 {
    vector<int> arr={5,2,6,1,3,4,7,-1,-1,-1,-1,-1,-1,-1};
    BinnaryTree tree;
    TreeNode* root=tree.BuildTree(arr,0);
    tree.Preorder(root);
    cout<<"null"<<endl;
    //cout<<tree.isValidBST(root);//?cout<<"true":cout<<"false";
    cout<<tree.isvalidbinnarytree(root,INT_MIN,INT_MAX);//?cout<<"true":
    cout<<endl;
    // vector<int>ans;
    // tree.Inorder(ans,root);
    // for(int i:ans)
    // {
    //     cout<<i<<"-->";
    // }
    // cout<<"null"<<endl;
 }
