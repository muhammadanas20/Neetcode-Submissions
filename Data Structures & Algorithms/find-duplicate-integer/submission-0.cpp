class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //using Floyd's Tortoise and Hare (Cycle Detection)
        int fast = 0;
        int slow = 0;
        //find interesection point
        while(true){
         slow = nums[slow]; //move at 1x speed
         fast = nums[nums[fast]]; // move at 2x speed
         if( slow == fast) break;
        }
        // again now move both at 1x speed from interection and start to fin duplicate
        fast = 0;
        while(fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};
