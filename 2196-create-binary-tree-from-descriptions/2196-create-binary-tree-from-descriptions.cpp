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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> mpp;
        unordered_set<int> children;

        for(auto it: descriptions) {
            int parent = it[0], child = it[1], isLeft = it[2];
            children.insert(child);
            TreeNode *parentNode, *childNode;

            if(mpp.find(parent) != mpp.end()) {
                parentNode = mpp[parent];
            }    
            else {
                parentNode = new TreeNode(parent);
                mpp[parent] = parentNode;
            }
            if(mpp.find(child) != mpp.end()) {
                childNode = mpp[child];
            }    
            else {
                childNode = new TreeNode(child);
                mpp[child] = childNode;
            }
            if(isLeft) {
                parentNode->left = childNode;
            }    
            else {
                parentNode->right = childNode;
            }    
        }

        for(auto [parent, node]: mpp) {
            if(children.find(parent) == children.end()) {
                return node;
            }    
        }
        
        return new TreeNode(-1);
    }
};