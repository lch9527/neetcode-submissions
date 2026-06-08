class Solution {
public:
    bool isabletoeat(const vector<int>& piles, int rate, int h) {
        long long time = 0;

        for (int pile : piles) {
            time += (pile + rate - 1) / rate;

            if (time > h) {
                return false;
            }
        }

        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isabletoeat(piles, mid, h)) {
                ans = mid;
                r = mid - 1; // try smaller speed
            } else {
                l = mid + 1; // need bigger speed
            }
        }

        return ans;
    }
};