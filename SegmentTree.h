/**
 * @file SegmentTree.h
 * @brief Segment Tree data structure implementation for range sum queries
 *
 * Implements a Segment Tree that efficiently supports:
 * - Point updates: modify a single element
 * - Range queries: calculate sum over any range
 *
 * Uses array-based representation where tree[i] represents the sum
 * of a specific range, and leaf nodes contain the original values.
 *
 * Time complexity: O(log n) for both updates and queries
 * Space complexity: O(n)
 */

// filepath: e:\Playground\SegmentTree.h
#pragma once

#include<vector>

/**
 * @class SegmentTree
 * @brief Array-based segment tree for efficient range sum queries
 *
 * Uses a complete binary tree stored in an array where:
 * - Leaf nodes (indices n to 2n-1) store original values
 * - Internal nodes store sums of their children
 * - Root is at index 1
 */
class SegmentTree{
public:

	/**
	 * @brief Constructor that builds the segment tree from input array
	 * @param nums Vector of integers to build the tree from
	 *
	 * Places original values at leaf positions (n to 2n-1) and builds
	 * internal nodes by combining children values.
	 * Time complexity: O(n)
	 */
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

	/**
	 * @brief Updates a single element at given index
	 * @param index The 0-based index of element to update
	 * @param newValue The new value to set at the index
	 *
	 * Updates the leaf node and propagates changes up to the root
	 * by recalculating all ancestor nodes.
	 * Time complexity: O(log n)
	 */
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

	/**
	 * @brief Calculates sum of elements in given range
	 * @param left Left boundary of range (0-based, inclusive)
	 * @param right Right boundary of range (0-based, inclusive)
	 * @return Sum of elements in range [left, right]
	 *
	 * Uses the segment tree structure to efficiently compute range sums
	 * by combining appropriate internal nodes.
	 * Time complexity: O(log n)
	 */
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
	std::vector<int> tree;  ///< Array representation of the segment tree
	int n;                  ///< Size of the original input array
};