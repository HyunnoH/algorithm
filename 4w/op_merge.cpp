#include <iostream>
#include <vector>
#include <algorithm>

int max_result = -123456789;
int min_result = 123456789;

int n;

int seq[12];

int op_plus, op_minus, op_mul, op_div;

void dfs(int plus, int minus, int mul, int div, int cnt, int sum) {
    if(cnt == n) {
        max_result = std::max(max_result, sum);
        min_result = std::min(min_result, sum);
    }
    
    if(plus > 0) {
        dfs(plus - 1, minus, mul, div, cnt + 1, sum + seq[cnt]);
    }
    if(minus > 0) {
        dfs(plus, minus - 1, mul, div, cnt + 1, sum - seq[cnt]);
    }
    if(mul > 0) {
        dfs(plus, minus, mul - 1, div, cnt + 1, sum * seq[cnt]);
    }
    if(div > 0) {
        dfs(plus, minus, mul, div - 1, cnt + 1, sum / seq[cnt]);
    }
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> seq[i];
    }
    std::cin >> op_plus >> op_minus >> op_mul >> op_div;
    
    dfs(op_plus, op_minus, op_mul, op_div, 1, seq[0]);
    
    std::cout << max_result << std::endl;
    std::cout << min_result << std::endl;
    
    return 0;
}
