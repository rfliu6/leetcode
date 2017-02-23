class Solution {
public:
    vector<TreeNode*> generateTrees(int n){
        vector<TreeNode*> result;
        if(n==0) return result;
        return generateTree(1,n);  
    }

    vector<TreeNode*> generateTree(int start, int end){
        vector<TreeNode*> left, right, result;
        if(start > end)
            result.push_back(NULL);      

        for(int i=start; i<=end; i++){
            left = generateTree(start, i-1);    //recursive
            right = generateTree(i+1, end);
            for(int j=0; j<left.size(); j++)
                for(int k=0; k<right.size(); k++){
                    TreeNode* tmp = new TreeNode(i);
                    tmp->left = left[j];
                    tmp->right = right[k];
                    result.push_back(tmp); 
                }
        }

        return result;
    }
};
