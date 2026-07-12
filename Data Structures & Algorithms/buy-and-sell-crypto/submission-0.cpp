class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0; //buy day
        int r = 1; //sell day
        int maxP = 0; //initial for start

        while(r < prices.size()){
            if(prices[l] < prices[r]){
                int profit = prices[r] - prices[l]; //calc profit of this window
                maxP = max(maxP,profit); //selecting max one
            }else{
                l = r; //found the best less buy day
            }
            r++; //increase the window size
        }

        return maxP;
    }
};
