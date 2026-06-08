class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        vector<int> tmp;
          if (intervals.empty()) {
            return res;
        }

        sort(intervals.begin(), intervals.end());

        tmp = intervals[0];

        for(int i = 0; i<intervals.size(); i++){
            if(tmp[1]>=intervals[i][0]){
                tmp = {min(tmp[0],intervals[i][0]),
                        max(tmp[1],intervals[i][1])};
            }
            else{
                res.push_back(tmp);
                tmp = intervals[i];
            }


        }
         res.push_back(tmp);

        return res;    
    }
};
