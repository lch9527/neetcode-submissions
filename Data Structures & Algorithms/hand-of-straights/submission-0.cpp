class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> count;

        for(const int& i : hand){
            count[i]++;
        }

        

        while(!count.empty()){
            int minnum = count.begin()->first;

            for(int i = 0; i<groupSize; i++){
                if(count.find(minnum+i) == count.end()){
                    return false;
                }

                count[minnum+i]--;

                if(count[minnum+i] == 0){
                    count.erase(minnum+i);
                }
            }
        }

        return true;
    }
};
