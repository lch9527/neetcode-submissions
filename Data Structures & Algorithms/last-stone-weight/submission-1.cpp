class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> Sheap;

        for(int i : stones){
            Sheap.push(i);
        }

        while (Sheap.size() >= 2){
            int x = Sheap.top();
            Sheap.pop();
            int y = Sheap.top();
            Sheap.pop();
            if(x == y){
                continue;
            }
            else if(x < y){
                Sheap.push(y-x);
            }
            else{
                Sheap.push(x-y);
            }
        }

        return Sheap.empty()? 0 : Sheap.top();
    }
};
