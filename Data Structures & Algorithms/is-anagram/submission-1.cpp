class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        vector <int> count(26,0);
        for(int i=0;i<s.length();i++){
           count[tolower(s[i]) - 'a'] ++;
           count[tolower(t[i]) - 'a'] --;
        }
        for(auto c :count){
            if(c != 0) return false;
        }
        return true;
    }
    
};
