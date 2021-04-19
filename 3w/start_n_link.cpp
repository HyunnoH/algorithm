#include <iostream>
#include <algorithm>
#include <vector>

bool is_picked[20];
int s[20][20];
int ans = 987654321;

void dfs(int curr_player, int cnt, int n) {
    if (cnt == n / 2) {
        std::vector<int> team_link, team_start;
        
        for(int i = 0; i < n; ++i) {
            if(is_picked[i]) team_start.push_back(i);
            else team_link.push_back(i);
        }
        
        int stat_start = 0, stat_link = 0;
        for(int i = 0; i < team_start.size(); ++i) {
            for(int j = i+1; j < team_link.size(); ++j) {
                int start_x = team_start[i], start_y = team_start[j];
                int link_x = team_link[i], link_y = team_link[j];
                stat_start += s[start_x][start_y] + s[start_y][start_x];
                stat_link += s[link_x][link_y] + s[link_y][link_x];
            }
        }
        
        int abs_stat = abs(stat_start - stat_link);
        ans = ans < abs_stat ? ans : abs_stat;
    }
    
    for(int i = curr_player + 1; i < n; ++i) {
        if(is_picked[i] == false) {
            is_picked[i] = true;
            dfs(i, cnt + 1, n);
            is_picked[i] = false;
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cin >> s[i][j];
        }
    }
    
    dfs(0, 0, n);
    
    std::cout << ans;
    
    return 0;
}
