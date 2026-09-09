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
    unordered_map<TreeNode*, TreeNode*> parent;

    void inOrder(TreeNode* root) {
        if (!root) return;

        if (root->left != NULL) {
            parent[root->left] = root;
            inOrder(root->left);
        }

        if (root->right != NULL) {
            parent[root->right] = root;
            inOrder(root->right);
        }
    }

    void BFS(TreeNode* root, TreeNode* target, int k, vector<int>& result) {
        if (root == NULL) return;

        queue<TreeNode*> q;
        q.push(target);

        unordered_set<TreeNode*> visited;
        visited.insert(target);

        while (!q.empty()) {

            if (k == 0) break;

            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                // Left
                if (temp->left != nullptr &&
                    !visited.count(temp->left)) {

                    q.push(temp->left);
                    visited.insert(temp->left);
                }

                // Right
                if (temp->right != nullptr &&
                    !visited.count(temp->right)) {

                    q.push(temp->right);
                    visited.insert(temp->right);
                }

                // Parent
                if (parent.count(temp) &&
                    !visited.count(parent[temp])) {

                    q.push(parent[temp]);
                    visited.insert(parent[temp]);
                }
            }

            k--;
        }

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            result.push_back(temp->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;

        inOrder(root);

        BFS(root, target, k, result);

        return result;
    }
};