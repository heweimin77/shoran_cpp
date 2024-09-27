#include <gtest/gtest.h>
#include <cmath>
#include <deque>
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
    int numberOfSubstrings(string s) {
        vector<int> pos = {-1};
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            int cnt = s[i] == '0' ? 1 : 0;
            int limit = sqrt(i + 1);
            int len = 0;
            for (int j = pos.size()-1; j >= 0 && cnt <= limit; --j) {
                int p = pos[j];
                int validlen = max(cnt + cnt * cnt, len + 1);
                len = i - p;
                ans += len >= validlen ? len - validlen + 1: 0;
                ++cnt;
            }
            if (s[i] == '0') pos.push_back(i);
            //cout << i << ", " << ans << endl;
        }
        return ans;
    }
    int numberOfSubstrings2(string s) {
        int n = s.size();
        deque<int> ps({n});
        int answer = 0;
        auto get_count = [&](int x, int validlen) {
            return x >= validlen ? x - validlen + 1 : 0;
        };
        for (int i = n - 1; i >= 0; --i) {
            int l = i, r = i;
            int cnt = s[i] == '0' ? 1 : 0;
            int limit = sqrt(n - i);

            for (auto p : ps) {
                if (cnt > limit) break;
                l = r;
                r = p;
                int validlen = cnt > 0 ? cnt + cnt * cnt : 1;
                answer += get_count(r - i, validlen) - get_count(l - i, validlen);
                ++cnt;
            }
            if (s[i] == '0') ps.push_front(i);
        }
        return answer;
    }
};

class PTest3234 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3234, Test1) {
    Solution s;
    auto actual = s.numberOfSubstrings("00011");
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3234, Test2) {
    Solution s;
    auto actual = s.numberOfSubstrings("101101");
    decltype(actual) expect = 16;
    EXPECT_EQ(expect, actual);
}
}


