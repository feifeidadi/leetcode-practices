#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

long long sum1ToN(vector<int>& nums, long long *numsSum)
{
    long long sum = 0;
    int N = nums.size();

    for(int i = 0; i < N ; i++)
    {
        sum += i+1;
        *numsSum += (nums[i] > 1 && nums[i] <= N) ? nums[i] : 0;
    }

    cout << "N = " << N << ",sum = " << sum <<endl;
    return sum;
}

int firstMissingPositive(vector<int>& nums) {
   if(nums.size() == 0) return 1;

   long long numsSum = 0;

                                                                                                                                        long long sumOne2N = sum1ToN(nums, &numsSum);

       cout <<sumOne2N << "   " << numsSum <<endl;
    return (sumOne2N - numsSum);
}

int main()
{
    std::vector<int> my_array;
    int validNumsSum = 0;
    my_array.push_back(0);
    int sum = firstMissingPositive(my_array);

    cout << sum <<endl;

}
