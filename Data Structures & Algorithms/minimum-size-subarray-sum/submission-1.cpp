class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen = INT_MAX;
        int n = nums.size();
        int l = 0;
        int total = 0;
        //sliding window
        for(int r = 0; r < n ; r++){
            total += nums[r]; //increase window from right side 
            while(total >= target){  //while target found
                minlen = min(r-l+1,minlen); //record their window len if min
                total -= nums[l]; //remove left by 1 shrink
                l++; //increase the index of left
            }
        }
        return minlen == INT_MAX ? 0 : minlen ;
    }
};