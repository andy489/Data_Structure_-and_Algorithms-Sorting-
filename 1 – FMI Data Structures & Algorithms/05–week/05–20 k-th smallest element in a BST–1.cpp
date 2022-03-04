// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode *root, vector<int> &traversal) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left, traversal);
        traversal.push_back(root->val);
        inorder(root->right, traversal);
    }

    int kthSmallest(TreeNode *root, int k) {
        vector<int> traversal;
        inorder(root, traversal);

        return traversal[k - 1];
    }
};
