class Solution {
public:
    bool isValidBST(TreeNode* root) {
       TreeNode* pre = NULL;
       return inOrder(root, pre);
    }
      // in order traversal
    bool inOrder(TreeNode* root, TreeNode* &pre){       
    	if(root == NULL)	return true;          // if node = null return          
    		if(!inOrder(root->left, pre))         // inorder(node.left)
    			return false;                           
    	if(pre != NULL && pre->val >= root->val)     //visit(node)
    		return false;
    	pre = root;
    	return inOrder(root->right, pre);             //inorder(node.right
    }
};
