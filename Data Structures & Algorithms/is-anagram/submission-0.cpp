class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){return false;}

        unordered_map<char,int> s_count;
        unordered_map<char,int> t_count;

        for (int i=0; i < s.size(); i++){
            s_count[s[i]]++;
            t_count[t[i]]++;
        }
            cout<< s[0] <<s_count[s[0]];

        for (int i=0; i<s_count.size(); i++){
            //cout<< s_count[i];
            if(s_count[i] != t_count[i]){
                return false;
            }
        }
        return true;
    }
};
