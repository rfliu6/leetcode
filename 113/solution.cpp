// pass tmp by value
//By passing the value, the memory required grow exponentially with each tree level (1 vector->2 vectors->4 vectors->....) 
//and they all stay alive until the end of the recursion.

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<vector<int>> result;
    	vector<int> tmp;
    	if(root == NULL)
    		return result;
    	else
    		pathsum(root, sum, result, tmp);
    	return result;
    }

    void pathsum(TreeNode* root, int sum, vector<vector<int>> &result, vector<int> tmp){
    	tmp.push_back(root->val);
    	sum = sum - root->val;
    	if(root->left == NULL && root->right == NULL && sum == 0)
    		result.push_back(tmp);
    	if(root->left != NULL)
	    	pathsum(root->left, sum, result, tmp);
    	if(root->right != NULL)
	    	pathsum(root->right, sum, result, tmp);
    }
};

// pass by reference 
// pop at the end of each recursion
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<vector<int>> result;
    	vector<int> tmp;
    	if(root == NULL)
    		return result;
    	else
    		pathsum(root, sum, result, tmp);
    	return result;
    }

    void pathsum(TreeNode* root, int sum, vector<vector<int>> &result, vector<int> &tmp){
    	tmp.push_back(root->val);
    	sum = sum - root->val;
    	if(root->left == NULL && root->right == NULL && sum == 0)
    		result.push_back(tmp);
    	if(root->left != NULL)
	    	pathsum(root->left, sum, result, tmp);
    	if(root->right != NULL)
	    	pathsum(root->right, sum, result, tmp);
	    tmp.pop_back();
    }
};  
