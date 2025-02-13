class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> groups;

        for(int i = 0; i < strs.size(); ++i){
            string key_string = strs[i];
            // Sorting key_string to make it a key
            sort(key_string.begin(), key_string.end());
            groups[key_string].push_back(strs[i]);
        }

        for(auto vec : groups){
            result.push_back(vec.second);
        }

        return result;
    }
};