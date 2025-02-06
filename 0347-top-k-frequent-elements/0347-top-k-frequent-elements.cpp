class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Map to store elem -> frequency
        unordered_map<int, int> mp;

        for(int num : nums) 
            mp[num]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto &entry : mp){
            pq.push({entry.second, entry.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int>ans(k);

        for(int i = k-1; i >= 0; --i){
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};