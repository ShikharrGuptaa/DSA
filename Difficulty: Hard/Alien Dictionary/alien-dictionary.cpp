//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        // Adj List to form a graph
        vector<vector<int>> adjList(26);
        vector<bool> exists(26, false);
        vector<int> inDeg(26, 0);
        
        // Step 1 : Forming a Graph
        
        // Populate exists first;
        
        for(int i = 0; i < words.size(); ++i){
            for(auto ch : words[i]){
                exists[ch - 'a'] = true;
            }
        }
        
        for(int i = 0; i < words.size()-1; ++i){
            string text1 = words[i];
            string text2 = words[i+1];
            int ptr1 = 0, ptr2 = 0;
            
            while(ptr1 < text1.size() && ptr2 < text2.size() && text1[ptr1] == text2[ptr2]){
                ptr1++;
                ptr2++;
            }
            
            if(ptr1 < text1.size() && ptr2 < text2.size()){
                // Make graph
                adjList[text1[ptr1] - 'a'].push_back(text2[ptr2] - 'a');
                inDeg[text2[ptr2] - 'a']++;
            }
            // First is smaller and next one reached to it's end, the dict is wrong
            else if(ptr1 < text1.size() && ptr2 == text2.size()){
                return "";
            }
            
        }
        
        // Step 2 : Perorming Topo Now
        queue<int> q;
        for(int i = 0; i < 26; ++i){
            if(exists[i] && !inDeg[i]) q.push(i);
        }
        
        
        string order;
        // Forming and Order;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            order += (char)(node + 'a');
            
            for(auto adjNode : adjList[node]){
                inDeg[adjNode]--;
                if(!inDeg[adjNode]) q.push(adjNode);
            }
        }
        
        // Cheking if all is processed and any oetter still havibg inDeg
        for(int i = 0; i < 26; ++i){
            if(exists[i] && inDeg[i] > 0) return "";
        }
        
        return order;
    }
};



//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends