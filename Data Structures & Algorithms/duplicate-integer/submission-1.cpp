class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
     // Unordered set dynamically handles any integer value
        std::unordered_set<int> seen;
        
        for (int num : nums) {
            // If the number already exists in our set, it's a duplicate
            if (seen.count(num)) {
                return true;
            }
            // Otherwise, store it and keep checking
            seen.insert(num);
        }
        
        return false;
    }
};