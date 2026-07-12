class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //using hash map

        unordered_map<char,int> lastseen; //character and idx

        int left = 0;
        int maxlen = 0;

        for(int right = 0;right<s.length();right++){
            if(lastseen.count(s[right])){
                // if found
                left = max(left,lastseen[s[right]] + 1);  //last seen + 1 skips all left directly to that duplicate 
                //max using to keep left to move forward 
            }

            lastseen[s[right]] = right;  //inserting right char
            maxlen = max(maxlen,right-left+1);
        }
     return maxlen;
    }
};
