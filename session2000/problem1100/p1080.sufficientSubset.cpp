﻿#include <gtest/gtest.h>
#include "support.h"

using namespace std;

namespace {

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return check(root, limit);
    }
    TreeNode* check(TreeNode* node, int limit) {
        if (node == nullptr) return nullptr;
        if (node->left == nullptr && node->right == nullptr) {
            if (node->val >= limit) {
                return node;
            } else {
                return nullptr;
            }
        }
        node->left = check(node->left, limit - node->val);
        node->right = check(node->right, limit - node->val);
        if (node->left == nullptr && node->right == nullptr) return nullptr;
        return node;
    }
};

class P1080Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P1080Test, TestMain)
{
    TreeNode* root = createTree({ 1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14 });
    Solution s;
    auto actual = s.sufficientSubset(root, 1);
    //decltype(actual) expect = 1;
    //EXPECT_EQ(expect, actual);
}

}
