//climbing stairs
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
    
    int a = 1, b = 2;
    for (int i = 3; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
    }
};

//maximum subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0 , maxSum = INT_MIN;

        for(int val: nums){
            curSum = curSum + val;
            maxSum = max(curSum,maxSum);

            if(curSum<0){
                curSum = 0;
            }
        }
        return maxSum;
    }
};



//unique paths
class Solution {
 public:
  int uniquePaths(int m, int n) {
    // dp[i][j] := the number of unique paths from (0, 0) to (i, j)
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    return dp[m - 1][n - 1];
  }
};


//coin change
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (const int coin : coins)
      for (int i = coin; i <= amount; ++i)
        dp[i] = min(dp[i], dp[i - coin] + 1);

    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};

//longest increasing subsequence 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;

        for (int num : nums) {
            auto it = lower_bound(lis.begin(), lis.end(), num);
            if (it == lis.end()) {
                lis.push_back(num);
            } else {
                *it = num;
            }
        }

        return lis.size();
    }
};
