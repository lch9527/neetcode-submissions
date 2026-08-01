class Solution {
public:

    string encode(vector<string>& strs) {
        string code;
        for(const string& str : strs){
            int length = str.size();
            code += to_string(length);
            code += "#";
            code += str;
        }
        return code;
    }

    vector<string> decode(string s) {
        vector <string> ans;
        int i = 0;

        while(i < s.size()){
            int j = i;
            string sl;
            while(s[j] != '#'){
                sl += s[j];
                j++;
            }
            int length = stoi(sl);

            string str = s.substr(j + 1, length);
            ans.push_back(str);

            i = j + length + 1;

        }

        return ans;
    }
};
 