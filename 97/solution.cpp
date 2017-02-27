class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() == 0 || s2.size() ==0 || s3.size() == 0)
            return (s1+s2).compare(s3)==0;
        int m = s1.size(), n = s2.size();
        if(m+n != s3.size())
            return false;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        if(s1[0] == s3[0])
            dp[1][0] = 1;
        for(int i=2; i<=m; i++)
            if(dp[i-1][0]==1 && s1[i-1] == s3[i-1])
                dp[i][0] = 1;
        if(s2[0] == s3[0])
            dp[0][1] = 1;
        for(int i=2; i<=n; i++)
            if(dp[0][i-1]==1 && s2[i-1] == s3[i-1])
                dp[0][i] = 1;
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++){
                if(dp[i-1][j]==1 && s1[i-1]==s3[i+j-1])
                    dp[i][j] = 1;
                if(dp[i][j-1]==1 && s2[j-1]==s3[i+j-1])
                    dp[i][j] = 1;
            }
        return dp[m][n];
    }
};
