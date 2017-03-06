class Solution {
public:
    int findRotateSteps(string ring, string key) {
        
        unordered_map<char, vector<int>>  mymap;
        int rsize = ring.size();
        int ksize = key.size();
        for(int i=0; i<ring.size(); i++)
            mymap[ring[i]].push_back(i);

        vector<vector<int>> dp(ksize, vector<int>(rsize, INT_MAX));
        for(auto k: mymap[key[0]])
            dp[0][k] = min(rsize-k, k);

        int result = INT_MAX;
        for(int i=1; i<ksize; i++)
            for(int j=0; j<rsize; j++){
                if(key[i] == ring[j]){
                    for(auto k: mymap[key[i-1]]){
                        int tmp = min((rsize+k-j)%rsize, (rsize+j-k)%rsize);
                        dp[i][j] = min(dp[i][j], dp[i-1][k]+tmp);
                    }
                    if(i == ksize-1)
                        result = min(result, dp[i][j]);
                }
            }

        return result+ksize;
    }
};
