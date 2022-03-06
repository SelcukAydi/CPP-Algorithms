#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>


int solution(std::string& str)
{
    int ans = INT_MAX;
    const std::string vowels = { "AEIOU" };

    for(int i = 0; i < 26; ++i)
    {
        char c = 65 + i;
        int cost = 0;
        bool isVowel = vowels.find(c) == std::string::npos ? false : true;

        for(const auto& l : str)
        {
            bool isConsonant = vowels.find(l) == std::string::npos ? false : true;

            if(l == c) continue;

            if(isConsonant ^ isVowel)
            {
                ++cost;
            }
            else
            {
                cost += 2;
            }
        }

        ans = std::min(ans, cost);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::string s1 = { "ABC" };
    std::string s2 = { "F" };
    std::string s3 = { "BANANA" };
    std::string s4 = { "FBHC" };
    std::string s5 = { "FOXEN" };
    std::string s6 = { "CONSISTENCY" };


    std::cout << solution(s1) << '\n';
    std::cout << solution(s2) << '\n';
    std::cout << solution(s3) << '\n';
    std::cout << solution(s4) << '\n';
    std::cout << solution(s5) << '\n';
    std::cout << solution(s6) << '\n';
    
    return 0;
}
