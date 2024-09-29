#include <gtest/gtest.h>
#include <unordered_set>
#include <valarray>

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
    long long countGoodIntegers(int n, int k) {
        int half = (n + 1) / 2, odd = n & 1;
        unordered_set<long long> visit;
        vector<long long> xs(n + 1);
        xs[0] = 1;
        for (int i = 1; i <= n; ++i) {
            xs[i] = xs[i-1] * i;
        }
        auto comb = [&](int n, int v) {
            return xs[n] / (xs[v] * xs[n-v]);
        };

        auto getvalue = [&](unordered_map<int,int> &counter, int n) {
            long long ans = 1;
            for (auto &[k, v] : counter) {
                ans *= comb(n, v);
                n -= v;
            }
            return ans;
        };

        auto gettagcount = [&](vector<int>& tag) {
            unordered_map<int, int> counter;
            for (auto x : tag) ++counter[x];
            long long ans = getvalue(counter, n);
            if (counter[0] > 0) {
                --counter[0];
                ans -= getvalue(counter, n-1);
            }
            return ans;
        };
        auto getkey = [](vector<int> &tag) {
            long long ans = 0;
            for (auto x : tag) {
                ans *= 10;
                ans += x;
            }
            return ans;
        };

        auto getCount = [&](long long x)->long long {
            vector<int> digit;
            for (int xx = x; xx > 0; xx /= 10) digit.push_back(xx % 10);
            int start = odd;
            for (int d = start; d < digit.size(); ++d) {
                x *= 10;
                x += digit[d];
            }
            if (x % k != 0) return 0;
            vector<int> tag = digit;
            tag.insert(tag.end(), digit.begin()+start, digit.end());
            std::sort(tag.begin(), tag.end());
            long long tagkey = getkey(tag);
            if (visit.contains(tagkey)) return 0;
            visit.insert(tagkey);
            return gettagcount(tag);
        };

        long long ans = 0, limit = pow(10, half);
        for (int x = pow(10, half-1); x < limit; ++x) {
            ans += getCount(x);
        }
        return ans;
    }
};

class PTest3272 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3272, Test1) {
    Solution s;
    auto actual = s.countGoodIntegers(3, 5);
    decltype(actual) expect = 27;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3272, Test2) {
    Solution s;
    auto actual = s.countGoodIntegers(1, 4);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3272, Test3) {
    Solution s;
    auto actual = s.countGoodIntegers(5, 6);
    decltype(actual) expect = 2468;
    EXPECT_EQ(expect, actual);
}
}


