/**
 * @file Vector.h
 * @brief Custom dynamic array implementation similar to std::vector
 *
 * A resizable array implementation that provides dynamic memory management
 * and various operations for manipulating integer sequences.
 *
 * Features:
 * - Dynamic resizing with capacity management
 * - Push/pop operations at front and back
 * - Random access with bounds checking
 * - Conditional element removal
 */

// filepath: e:\Playground\Vector.h
#pragma once
#include <initializer_list>
#include <string.h>
#include <functional>
#include <assert.h>

/**
 * @class Vector
 * @brief Dynamic array implementation for integers
 *
 * Provides automatic memory management with growth/shrink capabilities.
 * Maintains capacity larger than size to amortize allocation costs.
 */
class Vector {
public:
	/**
	 * @brief Default constructor - creates an empty vector with initial capacity
	 *
	 * Initializes with capacity of 6 elements to avoid frequent reallocations
	 * for small vectors.
	 */
	Vector()
		: arr(nullptr), size(0), capacity(0)
	{
		Reallocate(6);
	}

	/**
	 * @brief Constructor from initializer list
	 * @param data Initializer list containing initial elements
	 *
	 * Creates vector with elements from the initializer list.
	 * Capacity is set to 1.5x the initial size for future growth.
	 */
	Vector(std::initializer_list<int> data)
		: arr(nullptr), size(0), capacity(0)
	{
		Reallocate(data.size() * 1.5);
		unsigned int i = 0;
		for (auto& item : data)
			arr[i++] = item;
		size = data.size();
	}

	/**
	 * @brief Adds an element to the end of the vector
	 * @param data The element to add
	 *
	 * Automatically resizes the vector if capacity is exceeded.
	 * Amortized time complexity: O(1)
	 */
	void PushBack(int data) {
		if (size == capacity)
			Reallocate(capacity * 1.5);

		arr[size] = data;
		size += 1;
	}

	/**
	 * @brief Adds an element to the beginning of the vector
	 * @param data The element to add
	 *
	 * Shifts all existing elements one position to the right.
	 * Time complexity: O(n) due to element shifting
	 */
	void PushFront(int data) {
		if (size + 1 >= capacity)
			Reallocate(capacity * 1.5);

		for (int i = size; i > 0; --i)
			Swap(arr[i], arr[i - 1]);

		arr[0] = data;
		size += 1;
	}
	/**
	 * @brief Returns the current number of elements in the vector
	 * @return The size of the vector
	 */
	const int Size() const {
		return size;
	}

	/**
	 * @brief Returns the current capacity of the vector
	 * @return The maximum number of elements that can be stored without reallocation
	 */
	const int Capacity() const {
		return capacity;
	}

		/**
	 * @brief Returns the last element in the vector
	 * @return The last element, or -1 if vector is empty
	 *
	 * Note: Returns -1 for empty vector instead of throwing exception
	 */
int Back() {
		if (size == 0)
			return -1;
		return arr[size - 1];
	}

	/**
	 * @brief Removes the last element from the vector
	 * @return true if element was removed, false if vector was empty
	 *
	 * Automatically shrinks capacity if size becomes much smaller than capacity.
	 * Shrinks when size * 4 < capacity to avoid frequent reallocations.
	 */
	bool RemoveBack() {
		if (size == 0)
			return false;
		int back = arr[size - 1];
		size -= 1;
		if (size * 4 >= capacity) {
			Reallocate(capacity / 2);
		}
		return true;
	}

	/**
	 * @brief Removes the first element from the vector
	 * @return true if element was removed, false if vector was empty
	 *
	 * Shifts all remaining elements one position to the left.
	 * Time complexity: O(n) due to element shifting
	 * Note: Missing return statement in current implementation
	 */
	bool RemoveFront() {
		if (size == 0)
			return false;
		for (int i = 1; i < size; i--)
			Swap(arr[i], arr[i - 1]);
		size -= 1;
		if (size * 4 >= capacity) {
			Reallocate(capacity / 2);
		}
	}

	/**
	 * @brief Removes all elements that satisfy the given predicate
	 * @param predicate Function that takes (index, value) and returns true if element should be removed
	 *
	 * Iterates through the vector and removes elements where predicate returns true.
	 * Uses shifting to maintain element order after removal.
	 * Time complexity: O(n²) in worst case due to repeated shifting
	 */
	void RemoveIf(std::function<bool(int, int)> (predicate)) {
		for(int i = 0; i < size; ++i) {
			if (predicate(i, arr[i])) {
				for (int j = i + 1; j < size; ++j) {
					Swap(arr[j], arr[j - 1]);
				}
				i -= 1;
				size -= 1;
			}
		}
		if (size * 4 >= capacity) {
			Reallocate(capacity / 2);
		}
	}

	/**
	 * @brief Provides bounds-checked access to elements
	 * @param index The index of the element to access
	 * @return Reference to the element at the given index
	 *
	 * Asserts if index is out of bounds. Use for safe element access.
	 */
	int& At(int index) {
		if (index >= size || index < 0)
			assert(false);
		return arr[index];
	}
	/**
	 * @brief Operator overload for array-style access
	 * @param index The index of the element to access
	 * @return Reference to the element at the given index
	 *
	 * Provides convenient array-style syntax: vec[index]
	 */
	int& operator[](int index) {
		return At(index);
	}

	/**
	 * @brief Const version of operator[] for read-only access
	 * @param index The index of the element to access
	 * @return Copy of the element at the given index
	 */
	const int operator[](int index) const {
		if (index >= size || index < 0)
			assert(false);
		return arr[index];
	}
	/**
	 * @brief Provides direct access to the underlying array
	 * @return Pointer to the internal array
	 *
	 * Use with caution. Allows direct manipulation of internal data.
	 * Useful for interfacing with C-style functions.
	 */
	int* RawData() {
		return arr;
	}

private:
	/**
	 * @brief Reallocates the internal array with a new capacity
	 * @param newCapacity The new capacity for the vector
	 *
	 * Copies existing elements to the new array and deallocates the old one.
	 * Used internally for dynamic resizing.
	 */
	void Reallocate(int newCapacity)
	{
		int* temp = new int[newCapacity];
		if (arr) {
			memcpy(temp, arr, sizeof(int) * size);
			delete[] arr;
		}
		capacity = newCapacity;
		arr = temp;
	}
	/**
	 * @brief Utility function to swap two integers
	 * @param a First integer to swap
	 * @param b Second integer to swap
	 *
	 * Used internally for element manipulation operations.
	 */
	void Swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

	int size;      ///< Current number of elements in the vector
	int capacity;  ///< Maximum number of elements that can be stored without reallocation
	int* arr;      ///< Pointer to the dynamically allocated array
};