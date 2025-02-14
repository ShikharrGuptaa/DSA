class Solution {
private:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    int countVowelSubstrings(string word) {
        if(word.size() < 5) return 0;
        int count = 0;

        // Outer Loop to Keep Len in Check
        for(int idx = 0; idx < word.size() - 4; ++idx){
            unordered_set<char> uniqueVowel;

            for(int i = idx; i < word.size(); ++i){
                char ch = word[i];

                if(isVowel(ch)){
                    uniqueVowel.insert(ch);

                    if(uniqueVowel.size() == 5) ++count;
                }
                else{
                    break;
                }
            }
        }

        return count;


    }
};