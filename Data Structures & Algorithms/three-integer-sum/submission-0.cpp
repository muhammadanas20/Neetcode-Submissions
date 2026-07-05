class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        //necessary for two pointer
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            // if its greater than 0 isn sorted array than it wouldn't be adding to make 0
            if(nums[i] > 0) break;
            //skips duplicate if i same as prev than cause of duplicate results
            if( i > 0 && nums[i] == nums[i-1]) continue;

            //here is  two pointer approach
            int left = i+1;
            int right = n-1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    //found the triplets
                    res.push_back({nums[i],nums[left],nums[right]});

                    //skip duplicates of left i.e second and right i.e third
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;

                    left++;
                    right--;
                }
                else if(sum < 0){
                    left++; //sum is currently small
                }
                else{
                    right--;
                }
            }

        }
        return res;
    }
};
