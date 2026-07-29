class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        // Handle cases where k is greater than the array size
        k = k % n; 
        
        // 1. Reverse the entire array
        reverse(nums, 0, n - 1);
        
        // 2. Reverse the first k elements
        reverse(nums, 0, k - 1);
        
        // 3. Reverse the remaining n - k elements
        reverse(nums, k, n - 1);
    }

private:
    // Helper function using two pointers to reverse a sub-array in-place
    void reverse(std::vector<int>& nums, int left, int right) {
        while (left < right) {
            std::swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};