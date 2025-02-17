class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (target > sum || target < -sum) return 0;

        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, -1)); // Offset Shifting
        return help(nums.size() - 1, target + sum, nums, dp, sum);
    }

    int help(int idx, int target, vector<int> &nums, vector<vector<int>> &dp, int sum) {
        if (idx < 0) {
            return (target == sum) ? 1 : 0;  // We succeed if target is zero (shifted by sum)
        }
        if (target < 0 || target > 2 * sum) return 0;

        if (dp[idx][target] != -1) return dp[idx][target];

        // Recursive case: include or exclude current number
        int include = 0, exclude = 0;

        // Include current number
        if (target - nums[idx] >= 0) {
            include = help(idx - 1, target - nums[idx], nums, dp, sum);  // Add the number
        }

        // Exclude current number
        if (target + nums[idx] <= 2 * sum) {
            exclude = help(idx - 1, target + nums[idx], nums, dp, sum);  // Subtract the number
        }

        // Save the result in dp
        return dp[idx][target] = include + exclude;
    }
};