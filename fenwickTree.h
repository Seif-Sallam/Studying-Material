#pragma once
#include <vector>

class FenwickTree {
public:
    FenwickTree(const std::vector<int>& original) {
        data.resize(original.size() + 1, 0);
        for (int i = 1; i <= original.size(); ++i)
            update(i, original[i - 1]);
    }

    void update(int index, int delta) {
        while (index <= data.size()) {
            data[index] += delta;
            index += index & -index;
        }
    }

    int querySum(int index) {
        int result = 0;
        while(index > 0) {
            result += data[index];
            index -= index & -index;
        }
        return result;
    }

    int queryRange(int left, int right) {
        return querySum(right) - querySum(left - 1);
    }

private:
    std::vector<int> data;
};