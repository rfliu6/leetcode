class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> myqueue;
        if(root != NULL)
            myqueue.push(root);
        int zigzag = 0;
        while(!myqueue.empty()){
        	int size = myqueue.size();
        	vector<int> level(size,0);
        	for(int i=0; i<size; i++){
        		TreeNode* tmp = myqueue.front();
        		myqueue.pop();
        		if(zigzag == 0) level[i] = tmp->val;
        		else level[size-1-i] = tmp->val;
        		if(tmp->left != NULL) myqueue.push(tmp->left);
        		if(tmp->right != NULL) myqueue.push(tmp->right);
        	}
        	result.push_back(level);
        	zigzag = (zigzag+1)%2;
        }
        return result;
    }
};
