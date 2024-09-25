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
    vector<string> validStrings(int n) {
        vector<string> answers = {"0", "1"};
        for (int i = 1; i < n; ++i) {
            for (int j = answers.size() -  1; j >= 0; --j) {
                answers[j].push_back('1');
                if (answers[j][i-1] == '1') {
                    answers.emplace_back(answers[j]);
                    answers.back().back() = '0';
                }
            }
        }
        return answers;
    }
    vector<string> validStrings2(int n) {
        vector<string> answers;
        string r(n, ' ');
        function<void(int)> traverse = [&](int x) {
            if (x == n) {
                answers.push_back(r);
                return;
            }
            if (x == 0 || r[x-1] == '1') {
                r[x] = '0';
                traverse(x + 1);
            }
            r[x] = '1';
            traverse(x + 1);
        };
        traverse(0);
        return answers;
    }
};

class PTest3211 : public testing::Test {
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3211, Test1) {
    Solution s;
    auto actual = s.validStrings(3);
    std::sort(actual.begin(), actual.end());
    decltype(actual) expect = {"010","011","101","110","111"};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3211, Test2) {
    Solution s;
    auto actual = s.validStrings(1);
    std::sort(actual.begin(), actual.end());
    decltype(actual) expect = {"0","1"};
    EXPECT_EQ(expect, actual);
}
}


