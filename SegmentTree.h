#pragma once

#include<vector>

class SegmentTree{
public:

    SegmentTree(std::vector<int> nums) {
        n = nums.size();
        tree.resize(2 * n, 0);

        // Put the values at the leave nodes
        for(int i = 0; i < n; ++i){
            tree[i + n] = nums[i];
        }

        // Build the rest of the tree
        for (int i = n - 1; i > 0; --i){
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }

    void update(int index, int newValue)  {
        index += n;
        tree[index] = newValue;
        for (index /= 2; index >= 1; index /= 2)
            tree[index] = tree[2 * index] + tree[2 * index + 1];
        // return;
        while(index >= 1) {
            index /= 2;
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
        }
    }

    int sumRange(int left, int right) {
        left += n;
        right += n;
        int answer = 0;
        while(left <= right) {
            if (left % 2 == 1) {
                answer += tree[left];
                left += 1;
            }
            if (right % 2 == 0) {
                answer += tree[right];
                right -=1;
            }
            left /=2;
            right /=2;
        }

        return answer;
    }


private:
    std::vector<int> tree;
    int n;
};