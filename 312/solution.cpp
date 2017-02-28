class Solution {
public:
    int maxCoins(vector<int>& nums) {
       	int n = nums.size();
       	vector<int> num(n+2,1);
       	for(int i=0; i<n; i++)
       		num[i+1] = nums[i];  // num[0] = num[n+1] = 1

       	vector<vector<int>> dp(n+2, vector<int>(n+2,0));

       	for(int len=1; len<=n; len++){              
       		for(int start = 1; start<=n-len+1; s tart++){
       			int end = start+len-1;
       			for(int i=start; i<=end; i++){
       				dp[start][end] = max(dp[start][end],num[start-1]*num[i]*num[end+1]+dp[start][i-1]+dp[i+1][end]);
       			}                    //max value from (start to end), when len = 1, start = end, assume i is the last balloons
       		}
       	}
       	return dp[1][n];
    }
};
