#include <string>
#include <vector>
#include <algorithm>

bool solution(std::vector<std::string> phone_book) {
    bool answer = true;
    
    std::sort(phone_book.begin(), phone_book.end());
    
    size_t vector_size = phone_book.size();
    
    for (size_t i = 0; i < vector_size - 1; ++i) {
        if (phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size())) {
            answer = false;
            break;
        }
    }
    return answer;
}
