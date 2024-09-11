#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

namespace {

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t result = 0;
        int start = -1;
        unordered_map<int, int> indexes;

        for (size_t i = 0; i < s.size(); ++i) {
            auto it = indexes.find(s[i]);
            if (it != indexes.end() && it->second > start) {
                start = it->second;
            } else {
                result = max(result, i - start);
            }
            indexes[s[i]] = i;
        }
        return result;
    }
};

class p003Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(p003Test, Test1)
{
    Solution s;
    auto actual = s.lengthOfLongestSubstring("abcabcbb");
    EXPECT_EQ(3, actual);
}
TEST_F(p003Test, Test2)
{
    Solution s;
    auto actual = s.lengthOfLongestSubstring("tmmzuxt");
    EXPECT_EQ(5, actual);
}

}
