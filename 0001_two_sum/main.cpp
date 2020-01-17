
#include <hash_map>
#include <iostream>
#include <vector>
// 使用hashmap 时，要注意命名空间
using namespace __gnu_cxx;
using namespace std;

class Solution
{
private:
    /* data */
public:
    vector<int> twoSum_Force(vector<int> &nums, int target)
    {
        int size = nums.size();

        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return vector<int>({i, j});
                }
            }
        }
        return vector<int>({0, 0});
    };
    vector<int> twoSum_Hash_1(vector<int> &nums, int target)
    {
        int size = nums.size();
        hash_map<int, int> hashMap;

        for (int i = 0; i < size; i++)
        {
            hashMap[nums[i]] = i;
        }
        for (int i = 0; i < size; i++)
        {
            int index = target - nums[i];
            if ((hashMap.find(index) != hashMap.end()) && (hashMap[index] != i))
            {
                return vector<int>({hashMap[index], i});
            }
        }
        return vector<int>({0, 0});
    };
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int size = nums.size();
        hash_map<int, int> hashMap;

        for (int i = 0; i < size; i++)
        {
            int index = target - nums[i];
            if (hashMap.find(index) != hashMap.end())
            {
                return vector<int>({hashMap[index], i});
            }
            hashMap[nums[i]] = i;
        }
        return vector<int>({0, 0});
    }
};

int main()
{
    // 用new 申请的vector 并不能自动释放，注意！
    Solution *sol = new Solution();
    vector<int> vii = {3, 2, 4};
    vector<int> vi = sol->twoSum(vii, 6);

    cout << vi[0] << vi[1] << endl;
}
