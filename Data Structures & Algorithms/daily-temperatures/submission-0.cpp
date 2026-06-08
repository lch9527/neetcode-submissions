class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans (temperatures.size(),0); 
        stack<pair<int,int>> st;
        //first: num second: index 

        for(int i = 0; i<temperatures.size(); i++){
            while(!st.empty() && st.top().first < temperatures[i]){
                int prevIndex = st.top().second;
                st.pop();
                ans[prevIndex] = i - prevIndex;
            }
            st.push({temperatures[i], i});

        }
        return ans;

    }
};
