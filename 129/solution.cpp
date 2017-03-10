class Solution {
public:
    int sumNumbers(TreeNode* root) {
  		int result = 0;
  		if(root == NULL)
  			return result;
  		sumnumber(root, 0, result);
  		return result;
    }

    void sumnumber(TreeNode* root, int tmp, int &result){
    	tmp = tmp*10 + root->val;
    	if(root->left == NULL && root->right == NULL)
    		result += tmp;
    	if(root->left != NULL)
    		sumnumber(root->left, tmp, result);
    	if(root->right != NULL)
    		sumnumber(root->right, tmp, result);
    }
};
