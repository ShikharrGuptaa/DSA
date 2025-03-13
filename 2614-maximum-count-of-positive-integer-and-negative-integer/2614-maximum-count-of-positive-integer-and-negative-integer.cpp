class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        // Finding index of first Positive num;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > 0){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        int posiNums = n - left;
        left = 0;
        right = n-1;

        // Finding last neg idx
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < 0){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        int negNums = right + 1; // Adding one since it's index, not nums

        return max(posiNums, negNums);
    }
};