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
private:
    int result = 0;

    void solve(TreeNode* root, int minValue, int maxValue) {
        if(root == NULL) {
            return;
        }    

        result = max(result, max(abs(minValue - root->val), abs(maxValue - root->val)));
        minValue = min(minValue, root->val);
        maxValue = max(maxValue, root->val);
        solve(root->left, minValue, maxValue);
        solve(root->right, minValue, maxValue);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int minValue = root->val, maxValue = root->val;
        solve(root, minValue, maxValue);

        return result;
    }
};