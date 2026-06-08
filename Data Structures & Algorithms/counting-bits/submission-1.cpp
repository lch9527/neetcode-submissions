class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);

        for(int i = 1; i<=n; i++){
            for(int j = 0; j<31; j++){
                if((1<<j)&i){
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};
