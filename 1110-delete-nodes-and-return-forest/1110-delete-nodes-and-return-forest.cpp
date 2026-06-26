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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root == NULL) {
            return {};
        }

        unordered_set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        queue<TreeNode*> q;
        q.push(root);

        while(q.empty() == false) {
            TreeNode* currentNode = q.front();
            q.pop();

            if(currentNode->left) {
                q.push(currentNode->left);

                if(st.count(currentNode->left->val)) {
                    currentNode->left = NULL;
                }
            }

            if(currentNode->right) {
                q.push(currentNode->right);

                if(st.count(currentNode->right->val)) {
                    currentNode->right = NULL;
                }
            }

            if(st.count(currentNode->val)) {
                if(currentNode->left) {
                    result.push_back(currentNode->left);
                }
                if(currentNode->right) {
                    result.push_back(currentNode->right);
                }
            } 
            else if(result.empty()) {
                result.push_back(currentNode);
            }
        }

        return result;
    }
};