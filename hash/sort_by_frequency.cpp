#include <map>
#include <vector>
#include <algorithm>

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	    if (a.second == b.second) return a.first < b.first;
	    return a.second > b.second;
    }

class Solution {
    std::map<char, int> m;
public:
    string frequencySort(string s) {
        for(int i = 0; i < s.length(); ++i) {
            auto result = m.insert(make_pair(s[i], 1));
            if(!result.second) {
                result.first -> second += 1;
            }
        }
        
        std::vector<std::pair<char, int>> vec(m.begin(), m.end());
        std::sort(vec.begin(), vec.end(), cmp);
        
        string answer;
        for(int i = 0; i < vec.size(); ++i) {
            for(int j = 0; j < vec[i].second; ++j) {
                answer.push_back(vec[i].first);
            }
        }
        
        return answer;
    }
    
};
