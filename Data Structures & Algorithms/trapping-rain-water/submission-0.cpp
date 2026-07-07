class Solution {
public:
    int trap(vector<int>& height) {
        // Edge case: If the array is empty, no water can be trapped.
        if (height.empty()) return 0;
        
        // Initialize two pointers at the extreme ends of the array.
        int left = 0;
        int right = height.size() - 1;
        
        // Track the highest bar seen so far from the left and right sides.
        int leftmax = height[left];
        int rightmax = height[right];
        
        // Variable to store the total trapped water.
        int res = 0;

        // Loop until the two pointers meet.
        while (left < right) {
            // The water level at any point is limited by the smaller of the two walls.
            // If the maximum wall on the left is smaller, processing the left side is safe.
            if (leftmax < rightmax) {
                left++; // Move the left pointer inward.
                
                // Update the maximum height seen from the left so far.
                leftmax = max(leftmax, height[left]);
                
                // Water trapped at the current position is the difference between 
                // the highest left wall and the current bar's height.
                res += leftmax - height[left]; 
            }
            // If the maximum wall on the right is smaller or equal, process the right side.
            else {
                right--; // Move the right pointer inward.
                
                // Update the maximum height seen from the right so far.
                rightmax = max(rightmax, height[right]);
                
                // Water trapped at the current position is the difference between 
                // the highest right wall and the current bar's height.
                res += rightmax - height[right];
            }
        }
        // Return the total volume of trapped water.
        return res;
    }
};
