#include <iostream>
#include <vector>
#include <algorithm>


int solution(const std::string& s, const char starts)
{
    auto flip = [](const char c) { return c == '0' ? '1' : '0';};

    int ans = 0;
    char current = starts;

    for(const auto& c : s)
    {
        if(current != c) ++ans;
        current = flip(current);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::string s = { "111110" };

    std::cout << std::min(solution(s, '0'), solution(s, '1')) << '\n';

    return 0;
}
