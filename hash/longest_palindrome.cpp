#include <map>

class Solution {
    std::map<char, char> m;
public:
    int longestPalindrome(string s) {
        for(int i = 0; i < s.length(); ++i) {
            if(m.find(s[i]) == m.end()) {
                m.insert(make_pair(s[i], s[i]));
            } else {
                m.erase(s[i]);
            }
        }
        if(m.size() == 0 || m.size() == 1) {
            return s.length();
        }
        return s.length() - m.size() + 1;
    }
};
