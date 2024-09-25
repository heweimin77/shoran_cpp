//
// Created by heweimin on 2024/9/25.
//

#ifndef SHORAN_CPP_DICTTREE_H
#define SHORAN_CPP_DICTTREE_H

#include <string>
#include <climits>
#include <numeric>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
using std::string;
using std::pair;
using std::unordered_map;


class DictTree {
public:
    DictTree() {}
    ~DictTree() { for (auto &x : nexts) delete x.second; }
    void add(const string &w, int cost) {
        DictTree *now = this;
        for (auto x : w) {
            auto it = now->nexts.find(x);
            if (it == now->nexts.end()) {
                now = now->nexts[x] = new DictTree();
                it = now->nexts.find(x);
            } else {
                now = it->second;
            }
        }
        now->finish = true;
        now->cost = min(now->cost, cost);
    }
    vector<pair<int,int>> match(const string::iterator begin, const string::iterator end) {
        vector<pair<int,int>> ans;
        int r = 0;
        DictTree *now = this;
        for (auto x = begin; x != end; ++x) {
            auto it = now->nexts.find(*x);
            if (it == now->nexts.end()) {
                break;
            }
            ++r;
            now = it->second;
            if (now->finish) ans.push_back({r, now->cost});
        }
        return ans;
    }

private:
    unordered_map<char, DictTree*> nexts;
    bool finish = false;
    int cost = INT_MAX;
};


#endif //SHORAN_CPP_DICTTREE_H
