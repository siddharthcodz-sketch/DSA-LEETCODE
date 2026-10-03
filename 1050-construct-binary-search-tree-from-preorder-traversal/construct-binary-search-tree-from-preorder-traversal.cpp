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
TreeNode* build(vector<int>& preorder, int start, int end) {
        // No values are left in this range, so no subtree exists.
        if (start > end) {
            return nullptr;
        }
 
        // The first value of this range is the subtree root.
        TreeNode* root = new TreeNode(preorder[start]);
 
        // Defines the search space for the first greater value.
        int left = start + 1;
        int right = end + 1;
 
        while (left < right) {
            int mid = left + (right - left) / 2;
 
            // A greater middle value may be the first right-subtree value.
            if (preorder[mid] > root->val) {
                right = mid;
            }
            // A smaller middle value still belongs to the left subtree.
            else {
                left = mid + 1;
            }
        }
 
        // Marks where the right subtree begins.
        int splitIndex = left;
 
        root->left = build(preorder, start + 1, splitIndex - 1);
        root->right = build(preorder, splitIndex, end);
 
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder,0,preorder.size()-1);
    }
};