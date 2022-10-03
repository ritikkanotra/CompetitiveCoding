class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > um;
        for (string str: strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            um[temp].push_back(str);
        }
        vector<vector<string> > ans;
        for (auto p: um) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
