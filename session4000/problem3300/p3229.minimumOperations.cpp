#include <gtest/gtest.h>

using namespace std;

namespace {
static auto autorun = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        auto minium = [](vector<int> nums)->long long {
            if (nums.empty()) return 0;
            vector<pair<int,int>> data;
            for (int i = 0; i < nums.size(); ++i) data.emplace_back(nums[i], i);
            std::sort(data.begin(), data.end());
            map<int,int> dmap = {{-1, -1e9}, {nums.size(), -1e9}};
            long long ans = 0;
            for (auto &[d, i]: data) {
                auto it = dmap.insert(make_pair(i, d)).first;
                int r = abs(d);
                auto jt = it;
                ++jt;
                r = min(r, d - jt->second);
                --it;
                r = min(r, d - it->second);
                ans += r;
            }
            return ans;
        };

        long long ans = 0;
        int flag = 0;
        vector<int> ns;
        for (int i = 0; i < nums.size(); ++i) {
            int nflag = target[i] == nums[i] ? 0 : (target[i] > nums[i] ? 1 : -1);
            if (nflag == 0 || flag * nflag < 0) {
                ans += minium(ns);
                ns.clear();
            }
            flag = nflag;
            if (nflag) {
                ns.push_back(abs(target[i] - nums[i]));
            }
        }
        return ans + minium(ns);
    }
};

class PTest3229 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3229, Test1) {
    Solution s;
    vector<int> nums = {3,5,1,2};
    vector<int> target = {4,6,2,4};
    auto actual = s.minimumOperations(nums, target);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3229, Test2) {
    Solution s;
    vector<int> nums = {1,3,2};
    vector<int> target = {2,1,4};
    auto actual = s.minimumOperations(nums, target);
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}
}


