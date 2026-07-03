class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Loop through each character of the first string
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            
            // Compare this character with the same position in all other strings
            for (int j = 1; j < strs.size(); j++) {
                // If a string is too short or character doesn't match, we are done
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};