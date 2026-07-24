class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle empty vector safely
        
        int insertPos = 1; // Tracks where the next unique element should go
        
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is different from the previous one, it's unique
            if (nums[i] != nums[i - 1]) {
                nums[insertPos] = nums[i]; // Move it to the correct boundary position
                insertPos++; // Expand unique element boundary
            }
        }
        
        return insertPos; // Return total number of unique elements
    }
};
