class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int first_pos = -1;
        int last_pos = -1;

        // Finding Last Occurence and if any found going to rightmost to it
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                last_pos = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid-1;
            }
        }

        // Found Last Occurence
        // Meaning the first occurence will be on left of this and keep going on left
        low = 0, high = last_pos;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                first_pos = mid;
                high = mid -1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid-1;
            }
        }

        return {first_pos, last_pos};

    }
};