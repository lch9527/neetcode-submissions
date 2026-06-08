class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return true;
        }

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        Interval tmp = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (tmp.end > intervals[i].start) {
                return false;
            } else {
                tmp = intervals[i];
            }
        }

        return true;
    }
};