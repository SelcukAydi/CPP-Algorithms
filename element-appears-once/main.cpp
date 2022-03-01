#include <iostream>
#include <vector>

int solution(const std::vector<int>& arr)
{
    int ones = 0;
    int twos = 0;
    int common_bits = 0;

    for(int i = 0; i < arr.size(); ++i)
    {
        // If we have already this item then add it into twos.
        //
        twos = twos | (ones & arr[i]);

        // Accumulate this item's different bits.
        // Once stores items exist only one time in this array.
        //
        ones = ones ^ arr[i];

        // Calculate the common bits to remove them from ones and twos.
        // Flip the bits so that 1s will be 0s to remove them from ones and twos.
        //
        common_bits = ~(ones & twos);

        // Now remove common items from ones and twos.
        //
        ones = ones & common_bits;

        // Now remove common items from ones and twos.
        //
        twos = twos & common_bits;
    }

    return ones;
}

int main(int argc, char const *argv[])
{
    std::vector<int> arr = { 1,2,3,1,1 };
    
    std::cout << solution(arr) << '\n';
    
    return 0;
}
