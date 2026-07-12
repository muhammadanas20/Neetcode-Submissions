class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //using deque method
        deque<int> dq;  //store idx max to min
        vector <int> res;
        for(int i =0;i<nums.size();i++){
             //remove idx that are outside window
             while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
             }

             //remove idx whose value are smaller than nums[i]

             while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
             }

             //add current idx
             dq.push_back(i);
            //push the max of one complete window
             if(i >= k - 1){
               res.push_back(nums[dq.front()]);
             }
        }
        return res;
    }
};
