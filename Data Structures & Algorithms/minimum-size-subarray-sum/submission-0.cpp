class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int maxlen = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int sum = 0,j = i;
            while(j < n){
                 sum += nums[j];
                 if(sum >= target){
                    maxlen = min(maxlen,j-i+1);
                    break;
                 }
                 j++;
            }
        }
        return maxlen == INT_MAX ? 0 : maxlen;
    }
};