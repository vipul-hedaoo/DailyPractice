#include<iostream>
#include<vector>
using namespace std;
class TreeNode{
public:
int val=0;
TreeNode* left=nullptr;
TreeNode* right=nullptr;
TreeNode(int val)
{
    this->val=val;
    left=nullptr;
    right=nullptr;
}
};
class TreeBuider{
 public:
 TreeNode* BuildTree(vector<int>& arr, int index)
 {
    if(index>=arr.size()|| arr[index]==-1) return nullptr;
    TreeNode* root= new TreeNode(arr[index]);
    root->left=BuildTree(arr,2*index+1);
    root->right=BuildTree(arr,2*index+2);
    return root;
 }
 bool isSimillar(TreeNode* root1,TreeNode* root2)
 {
    if(root1==nullptr && root2==nullptr) return true;
    if(root1==nullptr || root2==nullptr) return false;
    if(root1->val!=root2->val) return false;
    return isSimillar(root1->left, root2->right) &&
       isSimillar(root1->right, root2->left);
 }
  void Preorder(TreeNode* root){
    if(root==nullptr)return;
    cout<<root->val<<"-->";
    Preorder(root->left);
    Preorder(root->right);
   }
};


int main()
{
    vector<int> array={1,2,2,-1,4,-1,4};
    TreeBuider b;
    TreeNode* root=b.BuildTree(array,0);
    b.Preorder(root);
    cout<<"\n tree is"<<b.isSimillar(root->left,root->right);
}