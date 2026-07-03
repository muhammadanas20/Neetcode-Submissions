class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int n = nums.size();
        // Store pairs of {number, original_index}
        std::vector<std::pair<int, int>> sortedNums(n);
        for (int i = 0; i < n; i++) {
            sortedNums[i] = {nums[i], i};
        }
        
        // Sort based on the number value
        std::sort(sortedNums.begin(), sortedNums.end());
        
        int left = 0;
        int right = n - 1;
        
        while (left < right) {
            int sum = sortedNums[left].first + sortedNums[right].first;
            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                // Return the stored original indices
                int idx1 = sortedNums[left].second;
                int idx2 = sortedNums[right].second;
                return {std::min(idx1, idx2), std::max(idx1, idx2)};
            }
        }
        return {};
    }
};