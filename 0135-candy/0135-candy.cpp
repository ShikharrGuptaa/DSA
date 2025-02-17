class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Left To Right Pass
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }
        // For Right -> Left
        for(int i = n-2; i >= 0; --i){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        int sum = 0;
        for(int &candy : candies){
            sum += candy;
        }

        return sum;
    }
};