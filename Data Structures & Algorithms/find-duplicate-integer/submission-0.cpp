class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> numset;

        for(int i: nums){
            if(numset.find(i) == numset.end()){
                numset.insert(i);
            }
            else{
                return i;
            }
        }

        return 0;
    }
};
