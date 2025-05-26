/**
 * @file disjointSet.h
 * @brief Union-Find (Disjoint Set) data structure implementation
 *
 * Implements a Union-Find data structure with path compression optimization.
 * Efficiently supports set operations: union and find.
 *
 * Features:
 * - Path compression for optimized find operations
 * - Union operation to merge sets
 * - Multiple constructor options
 *
 * Time complexity: Nearly O(1) for both union and find with path compression
 */

// filepath: e:\Playground\disjointSet.h
#pragma once
#include <vector>

/**
 * @class DisjointSet
 * @brief Union-Find data structure for managing disjoint sets
 *
 * Maintains a collection of disjoint sets and supports efficient
 * union and find operations with path compression optimization.
 */
class DisjointSet {
public:
	/**
	 * @brief Constructor from C-style array
	 * @param arr Pointer to array of integers
	 * @param size Size of the array
	 *
	 * Initializes each element as its own separate set.
	 * Each element becomes the parent of itself initially.
	 */
	DisjointSet(const int* arr, int size) {
		data.resize(size);
		parent.resize(size);
		for(int i = 0; i < size; ++i){
			data[i] = arr[i];
			parent[i] = i;
		}
	}

	/**
	 * @brief Constructor from std::vector
	 * @param vec Vector of integers to initialize the disjoint set
	 *
	 * Initializes each element as its own separate set.
	 * More convenient than the array constructor for modern C++ usage.
	 */
	DisjointSet(const std::vector<int> vec)
		: data(vec)
	{
		parent.resize(vec.size());
		for (int i = 0; i < vec.size(); ++i) {
			parent[i] = i;
		}
	}

	/**
	 * @brief Finds the root/representative of the set containing element i
	 * @param i Index of the element to find the root for
	 * @return Index of the root element of the set containing i
	 *
	 * Uses path compression optimization: during traversal to root,
	 * makes every node point directly to root for future efficiency.
	 * Time complexity: Nearly O(1) amortized due to path compression
	 */
	int find(int i) {
		if (parent[i] != i)
			parent[i] = find(parent[i]);
		return parent[i];
	}

	/**
	 * @brief Unites the sets containing elements a and b
	 * @param a Index of first element
	 * @param b Index of second element
	 *
	 * Finds the roots of both elements and makes one root point to the other,
	 * effectively merging the two sets into one.
	 * Time complexity: Nearly O(1) amortized due to path compression in find()
	 */
	void unionElements(int a, int b) {
		a = find(a);
		b = find(b);
		if (a != b) parent[a] = b;
	}

private:
	std::vector<int> data;    ///< Stores the actual data elements
	std::vector<int> parent;  ///< Stores parent pointers for each element (index -> parent index)

};