class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int maxp = 0;

        while(r < prices.size()){
            int buy = prices[l];
            if (buy > prices[r]){
                l = r;
            }
            else{
                maxp = max(maxp, prices[r] - prices[l]);
            }
            r++;

        }


        return maxp;
    }
};
