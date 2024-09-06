#include <gtest/gtest.h>
using namespace std;

namespace {
    class Solution {
    public:
        int countSubarrays(vector<int>& nums, int k) {
            auto kit = std::find(nums.begin(), nums.end(), k);
            int cnt = k - 1;
            //int* counts = new int[nums.size()];
            //memset(counts, 0, sizeof(int) * nums.size());
            vector<int> counts(nums.size() + 1);
            counts[k - 1] = 1;
            
            for (auto it = kit + 1; it != nums.end(); ++it) {
                cnt += (*it > k) ? 1 : -1;
                ++counts[cnt];
            }
            for (int i = 0; i < counts.size() - 1; ++i) {
                counts[i] += counts[i + 1];
            }

            int ci = k - 1;
            int result = counts[ci] + counts[ci + 1];
            for (int i = kit - nums.begin() - 1; i >= 0; --i) {
                ci += (nums[i] > k) ? -1 : 1;
                if (0 <= ci && ci < nums.size()) {
                    result += counts[ci];
                } else if (ci == -1) {
                    result += counts[0];
                }

            }
            return result;
        }
    };

    class P2488Test :public testing::Test
    {
    public:
        virtual void SetUp()
        {
        }
        virtual void TearDown()
        {
        }
    };


    TEST_F(P2488Test, Test1)
    {
        vector<int> para = { 2,3,1 };
        vector<string> spara = { "hold","engineer","cost","level" };
        Solution s;
        auto actual = s.countSubarrays(para, 3);
        decltype(actual) expect = 1;
        EXPECT_EQ(expect, actual);
    }
}



