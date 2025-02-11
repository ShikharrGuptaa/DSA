class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int m = part.size();

        for(char ch : s) {
            st.push(ch);

            
            if(st.size() >= m) {
                string temp = "";
                for(int i = m - 1; i >= 0; --i) {
                    if(st.top() != part[i]) {
                        while(temp.size()) { 
                            st.push(temp.back());
                            temp.pop_back();
                        }
                        break;
                    }
                    temp += st.top();
                    st.pop();
                }
            }
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
