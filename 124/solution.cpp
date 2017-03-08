class Solution {
public:
    int result = INT_MIN;

    int maxPath(TreeNode* root){
        if(root == NULL)
            return 0;
        int left = maxPath(root->left);
        int right = maxPath(root->right);
        result = max(result, left+right+root->val);   //update max result
        return max(max(left, right)+root->val,0);     //return maxpath start at current root, if the value is <0, we return 0
                                                      //don't choose the path
    } 


    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left = maxPath(root->left);
        int right = maxPath(root->right);
        return max(result, left+right+root->val);    // don't have max(0, )here
    }
};
