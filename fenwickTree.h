/**
 * @file fenwickTree.h
 * @brief Implementation of a Fenwick Tree (Binary Indexed Tree) data structure
 *
 * A Fenwick Tree is a data structure that efficiently supports:
 * - Point updates: modify a single element
 * - Range queries: calculate prefix sums and range sums
 *
 * Time complexity: O(log n) for both updates and queries
 * Space complexity: O(n)
 */

#pragma once
#include <vector>

/**
 * @class FenwickTree
 * @brief Binary Indexed Tree implementation for efficient range sum queries
 *
 * This implementation supports 1-indexed operations for easier mathematical operations.
 * The tree is built from a given array and allows efficient updates and queries.
 */
class FenwickTree {
public:
	/**
	 * @brief Constructor that builds the Fenwick Tree from an input array
	 * @param original The original array to build the tree from (0-indexed)
	 *
	 * Converts 0-indexed input array to 1-indexed Fenwick Tree representation.
	 * Time complexity: O(n log n)
	 */
	FenwickTree(const std::vector<int>& original) {
		data.resize(original.size() + 1, 0);
		for (int i = 1; i <= original.size(); ++i)
			update(i, original[i - 1]);
	}

	/**
	 * @brief Updates a single element by adding a delta value
	 * @param index The 1-indexed position to update
	 * @param delta The value to add to the element at the given index
	 *
	 * Time complexity: O(log n)
	 */
	void update(int index, int delta) {
		while (index <= data.size()) {
			data[index] += delta;
			index += leastSegnificantBit(index);
		}
	}

	/**
	 * @brief Calculates the prefix sum from index 1 to the given index
	 * @param index The 1-indexed position up to which to calculate the sum
	 * @return The sum of elements from index 1 to the given index (inclusive)
	 *
	 * Time complexity: O(log n)
	 */
	int querySum(int index) {
		int result = 0;
		while(index > 0) {
			result += data[index];
			index -= leastSegnificantBit(index);
		}
		return result;
	}

	/**
	 * @brief Calculates the sum of elements in a given range
	 * @param left The left boundary of the range (1-indexed, inclusive)
	 * @param right The right boundary of the range (1-indexed, inclusive)
	 * @return The sum of elements from left to right (inclusive)
	 *
	 * Uses the principle: rangeSum(left, right) = prefixSum(right) - prefixSum(left-1)
	 * Time complexity: O(log n)
	 */
	int queryRange(int left, int right) {
		return querySum(right) - querySum(left - 1);
	}

private:
	/**
	 * @brief Calculates the least significant bit of a number
	 * @param v The input value
	 * @return The least significant bit (rightmost set bit)
	 *
	 * Uses bit manipulation: v & -v isolates the rightmost set bit.
	 * This is crucial for navigating the Fenwick Tree structure.
	 */
	int leastSegnificantBit(int v) {
		return v & -v;    }

	/**
	 * @brief Internal storage for the Fenwick Tree
	 *
	 * Uses 1-indexed array where data[0] is unused.
	 * Each index stores a partial sum that covers a specific range
	 * determined by the binary representation of the index.
	 */
	std::vector<int> data;
};