#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;

        for (auto &d : descriptions) {
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            if (!mp.count(parent))
                mp[parent] = new TreeNode(parent);

            if (!mp.count(child))
                mp[child] = new TreeNode(child);

            if (isLeft)
                mp[parent]->left = mp[child];
            else
                mp[parent]->right = mp[child];

            children.insert(child);
        }

        for (auto &d : descriptions) {
            int parent = d[0];
            if (!children.count(parent))
                return mp[parent];
        }

        return nullptr;
    }
};

void levelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }

    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> descriptions(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        cin >> descriptions[i][0]
            >> descriptions[i][1]
            >> descriptions[i][2];
    }

    Solution obj;
    TreeNode* root = obj.createBinaryTree(descriptions);

    cout << "Root: " << root->val << endl;

    cout << "Level Order Traversal: ";
    levelOrder(root);

    return 0;
}