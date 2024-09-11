#include <gtest/gtest.h>
#include <climits>

using namespace std;

namespace {

class Solution {
public:
  int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
    int low = uniqueCnt1 + uniqueCnt2 - 1;
    int high = INT_MAX;
    long long divisor = (long long)divisor1 * divisor2 / getGCD(divisor1, divisor2);
    while (low + 1 < high) {
      auto mid = low + (high - low) / 2;
      if (isOK(divisor1, divisor2, divisor, uniqueCnt1, uniqueCnt2, mid)) {
        high = mid;
      } else {
        low = mid;
      }
    }
    return high;
  }
  int getGCD(int d1, int d2) {
    if (d1 > d2) swap(d1, d2);
    int gcd = d1;
    while (d1 > 0) {
      gcd = d1;
      d1 = d2 % d1;
      d2 = gcd;
    }
    return gcd;
  }
  bool isOK(int divisor1, int divisor2, long long divisor, int uniqueCnt1, int uniqueCnt2, int v) {
    long long cnt1 = v - v / divisor1;
    long long cnt2 = v - v / divisor2;
    long long cnt = v - v / divisor1 - v / divisor2 + v / divisor;
    if (cnt1 < uniqueCnt1) return false;
    if (cnt2 < uniqueCnt2) return false;
    return cnt1 + cnt2 - cnt >= uniqueCnt1 + uniqueCnt2;
  }
};


class P2513Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};


TEST_F(P2513Test, Test1)
{
    Solution s;
    auto actual = s.minimizeSet(92761, 48337, 208563424, 9115778);
    decltype(actual) expect = 217679202;
    EXPECT_EQ(expect, actual);
}
}

