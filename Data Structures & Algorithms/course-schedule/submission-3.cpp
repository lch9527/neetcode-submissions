class Solution {

private:
// course to the prerequisties
unordered_map<int,vector<int>> course_map;
// all visisted course in single dfs
unordered_set<int> visiting; 



public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(const auto& i : prerequisites){
            course_map[i[0]]. emplace_back(i[1]); 
        }

        for(int i = 0; i<numCourses; i++){
            if(!dfs(i)){
                return false;
            }
        }
        return true;
    }

    bool dfs(int& crs){
        if(visiting.count(crs)){
            return false;
        }

        if(course_map.empty()){
            return true;
        }
        
        visiting.insert(crs);

        for(auto& c: course_map[crs]){
            if(!dfs(c)){
                return false;
            }
        }

        visiting.erase(crs);
        course_map[crs].clear();
        return true;


    }
};
