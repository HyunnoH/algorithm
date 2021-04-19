#include <iostream>
#include <string>
#include <deque>

int main() {
    int n, k;
    
    std::cin >> n >> k;
    
    std::string s;
    std::cin >> s;
    std::deque<char> deq;
    
    for(int i = 0; i < s.length(); ++i) {
        while(k && !deq.empty() && deq.back() < s[i]) {
            deq.pop_back();
            --k;
        }
        deq.push_back(s[i]);
    }
    
    for(int i = 0; i < deq.size() - k; ++i) {
        std::cout << deq[i];
    }
}
