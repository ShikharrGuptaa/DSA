class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int lastDay = days[n-1];
        vector<int> dp(lastDay+1, 0);
        unordered_map<int, bool> travelDay;

        for(int day : days){
            travelDay[day] = true;
        }


        dp[0] = 0;
        for(int i = 1; i <= lastDay; ++i){
            if(!travelDay[i]){
                dp[i] = dp[i-1];
            }
            else{
                int oneDayPass = costs[0] + dp[i-1];
                int svnDayPass = costs[1] + dp[max(0, i - 7)];
                int thyDayPass = costs[2] + dp[max(0, i - 30)];

                dp[i] = min({oneDayPass, svnDayPass, thyDayPass});
            }
        }

        return dp[lastDay];
    }
};