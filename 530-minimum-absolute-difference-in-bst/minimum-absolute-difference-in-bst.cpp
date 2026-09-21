/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //a Concept: INORDER TRAVERSAL of BST always gives sorted arr;
    long long last =INT_MIN;
    long long diff = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr) return 0;

        getMinimumDifference(root->left);
        diff = min(diff,(root->val - last));
        last = root->val;
        getMinimumDifference(root->right);

        return diff;
    }
};