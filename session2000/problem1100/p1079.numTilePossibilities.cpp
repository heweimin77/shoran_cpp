#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

namespace {

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<int, int> counts;
        for (auto ch : tiles) {
            ++counts[ch];
        }
        vector<int> cnts;
        for (auto& r : counts) {
            cnts.push_back(r.second);
        }
        sort(cnts.begin(), cnts.end(), greater<int>());
        return getCount(cnts) - 1;
    }

    int getCount(vector<int>& cnts) {
        int r = 1;
        for (int i = 0; i < cnts.size(); ++i) {
            vector<int> next = cnts;
            --next[i];
            sort(next.begin(), next.end(), greater<int>());
            if (next.back() == 0) next.pop_back();
            r += getCount(next);
        }
        return r;
    }
};

class P1079Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P1079Test, Test1)
{
    Solution s;
    auto actual = s.numTilePossibilities("AAB");
    decltype(actual) expect = 8;
    EXPECT_EQ(expect, actual);
}

TEST_F(P1079Test, Test2)
{
    Solution s;
    auto actual = s.numTilePossibilities("AAABBC");
    decltype(actual) expect = 188;
    EXPECT_EQ(expect, actual);
}
TEST_F(P1079Test, Test3)
{
    Solution s;
    auto actual = s.numTilePossibilities("V");
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
}

