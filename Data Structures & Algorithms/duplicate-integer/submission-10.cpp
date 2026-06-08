class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> nset;
        for(const int& i: nums){
            if (nset.find(i)==nset.end()){
                 nset.insert(i);
            }
            else{
                return true;
            }
           
        }
        return false;
    }
};