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
    // TreeNode* prev = nullptr;
    // void flatten(TreeNode* root) {
    //     if(root==nullptr) return;

    //     flatten(root->right);
    //     flatten(root->left);
    //     root->right = prev;
    //     root->left = nullptr;
    //     prev = root;
    // }
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left != nullptr) {

                // Find predecessor (rightmost node of left subtree)
                TreeNode* pre = curr->left;
                while (pre->right != nullptr) {
                    pre = pre->right;
                }

                // Connect predecessor's right to current's right
                pre->right = curr->right;

                // Move left subtree to the right
                curr->right = curr->left;
                curr->left = nullptr;
            }

            // Move forward
            curr = curr->right;
        }
    }
};
