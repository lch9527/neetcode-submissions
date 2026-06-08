class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1){
            return 0;
        }
        int l = 0, r = 1, ans = 0;;
        while(r < prices.size()){
            if(prices[l] > prices[r]){
                l = r;
            }
            else{
                ans = max(ans, prices[r] - prices[l]);
                r++;
            }
        }
        return ans;
    }
};
