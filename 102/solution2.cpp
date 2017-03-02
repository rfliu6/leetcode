class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> myqueue;
        if(root != NULL)
            myqueue.push(root);
        while(!myqueue.empty()){
        	vector<int> level;
        	int size = myqueue.size();
        	for(int i=0; i<size; i++){
        		TreeNode* tmp = myqueue.front();
        		myqueue.pop();
        		level.push_back(tmp->val);
        		if(tmp->left != NULL) myqueue.push(tmp->left);
        		if(tmp->right != NULL) myqueue.push(tmp->right);
        	}
        	result.push_back(level);
        }
        return result;
    }
};
