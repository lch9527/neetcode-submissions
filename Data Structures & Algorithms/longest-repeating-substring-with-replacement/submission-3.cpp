class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.length() < 1){
            return 0;
        }
        vector<int> count(26,0);

        int l = 0;
        int ans = 1;

        count[s[l] - 'A']++;

        for(int r = 1; r < s.length(); r++){
            count[s[r] - 'A'] ++;
            int maxFeq = *max_element(count.begin(),count.end());
            int ntr = (r-l+1) - maxFeq;
            if(ntr <= k){
                ans = max(ans, r-l+1);
                continue;
            }
            while((r-l+1) - maxFeq > k){
                count[s[l] - 'A'] --;
                l++;
                maxFeq = *max_element(count.begin(),count.end());
            }

            ans = max(ans, r-l+1);
        }

        return ans;
        


    }
};
