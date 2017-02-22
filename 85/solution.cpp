class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)
          return 0;
        int n = matrix[0].size();
        if(n == 0)
          return 0;

        int result = 0;
        int bound = INT_MAX, length = 0;
        
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
          if(matrix[i][0] == '1') 
            dp[i][0] = 1;
          for(int j=1; j<n; j++){
            if(matrix[i][j] == '1')
              dp[i][j] = dp[i][j-1]+1; 
          }
        }

        for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
            if(dp[j][i] != 0){
              length += 1;
              bound = min(bound, dp[j][i]);
              result = max(result, length*bound);
            }else{
              length = 0;
              bound = INT_MAX;
            }
          }
          length = 0;
          bound = INT_MAX;
        }

        return  result;



    }
};
