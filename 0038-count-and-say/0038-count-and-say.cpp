class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string RLE_Prev = countAndSay(n-1);
        string ans = "";
        int count = 1;

        for(int i = 0; i < RLE_Prev.size(); ++i){
            if(i+1 < RLE_Prev.size() && RLE_Prev[i] == RLE_Prev[i+1]){
                count++;
            }
            else{
                ans += to_string(count);
                ans += RLE_Prev[i];
                count = 1;
            }
        }

        return ans;
    }
};