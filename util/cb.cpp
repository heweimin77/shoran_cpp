#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>

using namespace std;

namespace {

class AutoRun {
public:
    AutoRun() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

} autorun;

long long fast_power(long long base, long long n, long long module) {
    long long result = 1;
    int mask = 1;
    for (int mask = 1; mask <= n; mask <<= 1) {
        if (mask & n) {
            result *= base;
            result %= module;
        }
        base *= base;
        base %= module;
    }
    return result;
}

long long invert(long long a, long long p) {
    return fast_power(a, p - 2, p);
}

int combination(int n, int m, int MOD)
{
    vector<int> results(m + 1);
    vector<int> nexts(m + 1);
    results[0] = nexts[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i && j <= m; ++j) {
            nexts[j] = (results[j] + results[j - 1]) % MOD;
        }
        results.swap(nexts);
    }
    return results[m];
}

void get_primes(vector<int> &min_factor, vector<int> &primes)
{
    int maxnum = min_factor.size() - 1;
    for (int i = 2; i <= maxnum; ++i) {
        if (min_factor[i] == 0) {
            min_factor[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > maxnum) break;
            min_factor[i * p] = p;
            if (p == min_factor[i]) break;
        }
    }
}

vector<int> getPrimes(int maxnum)
{
    vector<int> primes;
    vector<int> min_factor(maxnum + 1);
    for (int i = 2; i <= maxnum; ++i) {
        if (min_factor[i] == 0) {
            min_factor[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > maxnum) break;
            min_factor[i * p] = p;
            if (p == min_factor[i]) break;
        }
    }
    return primes;
}

// �߶���
class SegmentTree {
    static constexpr int MOD = 1e9 + 7;
#if 1
#define GETMOD(x)  ((x) % MOD)
#define MAKEMOD(x)  (x %= MOD)
#else
#define GETMOD(x) x
#define MAKEMOD(x)
#endif 

    struct Info {
        int value = 0;
        int todo = 0;
    };
public:
    SegmentTree(int nn)
    {
        for (n = 1; n < nn; n <<= 1);
        data = (Info *)malloc(sizeof(Info) * n * 2);
        memset(data, 0, sizeof(Info) * n * 2);
    }
    ~SegmentTree()
    {
        free(data);
    }

    void update(int i, int v)
    {
        update(i, i, v);
    }
    void update(int left, int right, int v)
    {
        update(left, right, v, 0, 0, n - 1);
    }
    // ll <= left <= right <= rr
    void update(int left, int right, int v, int index, int ll, int rr)
    {
        Info *info = &data[index];
        if (ll == left && right == rr) {
            info->todo += v;
            MAKEMOD(info->todo);
            return;
        }
        info->value += v * (right - left + 1);
        MAKEMOD(info->value);
        int mid = (ll + rr) >> 1;
        if (right <= mid) {
            update(left, right, v, (index << 1) + 1, ll, mid);
        } else if (left > mid) {
            update(left, right, v, (index << 1) + 2, mid + 1, rr);
        } else {
            update(left, mid, v, (index << 1) + 1, ll, mid);
            update(mid + 1, right, v, (index << 1) + 2, mid + 1, rr);
        }

    }
    int get(int left, int right)
    {
        return GETMOD(get(left, right, 0, 0, n - 1));
    }
    // ll <= left <= right <= rr
    long long get(int left, int right, int index, int ll, int rr)
    {
        Info *info = &data[index];
        if (ll == rr) {
            return info->todo + info->value;
        }
        int lindex = (index << 1) + 1;
        int rindex = (index << 1) + 2;
        // Process todo
        if (info->todo) {
            data[lindex].todo += info->todo;
            data[rindex].todo += info->todo;
            info->value += GETMOD((long long)info->todo * (rr - ll + 1));
            MAKEMOD(info->value);
            info->todo = 0;
        }

        if (ll == left && right == rr) {
            return info->value;
        }
        long long  result = 0;
        int mid = (ll + rr) >> 1;
        if (right <= mid) {
            result += get(left, right, lindex, ll, mid);
        } else if (left > mid) {
            result += get(left, right, rindex, mid + 1, rr);
        } else {
            result += get(left, mid, lindex, ll, mid);
            result += get(mid + 1, right, rindex, mid + 1, rr);
        }
        return result;
    }

private:
    Info *data;
    //vector<Info> data;
    int n;
};


// ��״����
// �����������޸ģ���ȡ����
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int n) : data(n + 1)
    {
    }
    ~BinaryIndexedTree()
    {
    }

    void update(int i, int v)
    {
        for (int n = data.size() - 1; i <= n; i += lowbit(i)) {
            data[i] += v;
        }
    }
    long long get_range(int left, int right)
    {
        return get_sum(right) - get_sum(left - 1);
    }
    long long get_sum(int i)
    {
        long long r = 0;
        for (; i > 0; i -= lowbit(i)) {
            r += data[i];
        }
        return r;
    }
private:
    inline int lowbit(int i)
    {
        return i & -i;
    }
private:
    vector<long long> data;
};

// �����޸ģ���ȡ���㡣����ʹ�ò�֣������޸ģ���Ӧ�޸�left v, right+1 -v����ȡ���㣬���Ƕ�diff���
class BinaryIndexedTree2 {
public:
    BinaryIndexedTree2(int n) : diff(n + 1)
    {
    }
    ~BinaryIndexedTree2()
    {
    }

    void update(int left, int right, int v)
    {
        diff.update(left, v);
        diff.update(right + 1, -v);
    }

    int get_value(int i)
    {
        return diff.get_sum(i);
    }
private:
    BinaryIndexedTree diff;
};

// �����޸ģ���ȡ���򡣡���ʹ���������diff��i * diff, �����޸Ĺ�ʽ��sum(x) = (x + 1) * sum(diff) - sum (i * diff)
class BinaryIndexedTree3 {
public:
    BinaryIndexedTree3(int n) : diff(n + 1), idiff(n + 1)
    {
    }
    ~BinaryIndexedTree3()
    {
    }

    void update(int left, int right, int v)
    {
        diff.update(left, v);
        idiff.update(left, left * v);

        ++right;
        diff.update(right, -v);
        idiff.update(right, -right * v);
    }

    long long get_sum(int i)
    {
        long long r = (i + 1) * diff.get_sum(i);
        r -= idiff.get_sum(i);
        return r;
    }
    long long get_range(int left, int right)
    {
        return get_sum(right) - get_sum(left - 1);
    }

private:
    inline int lowbit(int i)
    {
        return i & -i;
    }
private:
    BinaryIndexedTree diff;
    BinaryIndexedTree idiff;
};
}

// ���
class Uniset {
public:
    Uniset(int n) : indexes(n, -1) {
    }

    int getIndex(int i) const { return indexes[i]; }
    void merge(int i, int j) {
        if (isSameGroup(i, j)) return;
        int ii = getIndex(i), ji = getIndex(j);
        if (ii < 0 && ji < 0) {
            indexes[i] = indexes[j] = groups.size();
            groups.push_back(unordered_set<int>{i, j});
        } else if (ii < 0) {
            indexes[i] = ji;
            groups[ji].insert(i);
        } else if (ji < 0) {
            indexes[j] = ii;
            groups[ii].insert(j);
        } else {
            if (groups[ii].size() < groups[ji].size()) swap(ii, ji);
            auto& t = groups[ii];
            for (auto x : groups[ji]) {
                indexes[x] = ii;
                t.insert(x);
            }
            groups[ji].clear();
        }
    }
    bool isSameGroup(int i, int j) {
        int ii = getIndex(i), ji = getIndex(j);
        return ii >= 0 && ii == ji;
    }

private:
    vector<int> indexes;
    vector<unordered_set<int>> groups;
};

// �ַ����Ĺ���ǰ׺
vector<int> getLcp(const string &s)
{
    int n = s.size();
    vector<int> lcp(n);
    lcp[0] = 0;
    int left = 0, right = 0;
    for (int i = 1; i < n; ++i) {
        //0, right-left = left, right;  i, right ==   i - left ,right - left
        if (i <= right && i + lcp[i - left] <= right) {
            lcp[i] = lcp[i - left];
        } else {
            int r = max(0, right - i + 1);
            while (i + r < n && s[i + r] == s[r]) ++r;
            lcp[i] = r;
            left = i;
            right = i + lcp[i] - 1;
        }

    }
    return lcp;
}
