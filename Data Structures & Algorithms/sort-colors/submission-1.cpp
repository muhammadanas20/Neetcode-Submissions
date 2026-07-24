class Solution { 
public: 
    void sortColors(vector<int>& nums) { 
        int low = 0; 
        int mid = 0; 
        int high = nums.size() - 1; 

       //Track mid instead of low
        while(mid <= high) { 
            if(nums[mid] == 0) { 
                // Swap 0 to the low region
                swap(nums[low], nums[mid]); 
                low++; 
                mid++; 
            } else if(nums[mid] == 1) { 
                // 1 is already in the correct middle section
                mid++; 
            } else { 
                // Swap 2 to the high region
                swap(nums[mid], nums[high]); 
                high--; 
                // Notice mid does NOT increment here; 
                // we must evaluate the swapped element next!
            } 
        } 
    } 
};
