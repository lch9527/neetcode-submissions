class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end()); // max pile size

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canFinish(piles, mid, h)) {
                r = mid - 1;   // try smaller speed
            } else {
                l = mid + 1;   // need bigger speed
            }
        }

        return l; // l is the smallest speed that works
    }

private:
    bool canFinish(const vector<int>& piles, int rate, int h) {
        long long hours = 0;
        for (int pile : piles) {
            // ceil(pile / rate) = (pile + rate - 1) / rate
            hours += (pile + rate - 1) / rate;
            if (hours > h) return false; // early exit
        }
        return hours <= h;
    }
};
