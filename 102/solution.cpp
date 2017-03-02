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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelorder(root, result, 0);
        return result;
    }

    void levelorder(TreeNode* root, vector<vector<int>> &result, int depth){
    	if(root == NULL) return;
    	if(depth == result.size())
    		result.push_back(vector<int>());
    	result[depth].push_back(root->val);
    	levelorder(root->left, result, depth+1);
    	levelorder(root->right, result, depth+1);
    }
};
