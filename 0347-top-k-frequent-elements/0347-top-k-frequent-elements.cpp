class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Map to store elem -> frequency
        unordered_map<int, int> mp;

        for(int num : nums) 
            mp[num]++;
        
        // Forming a minHeap that'll store freq of elements along with their number
        // Goal is to make min heap of most frequencies
        // Why minHeap? because the least of those freauency already stored in minHeap would be on top and
        //  if anything comes more than the value stored in top deserves to be in minHeap so we can easily pop it, and can push the new greater value there, keeping the fact together that it needs only of k size so that we get k most frequent elements only
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