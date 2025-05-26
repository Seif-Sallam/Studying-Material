/**
 * @file Stack.h
 * @brief Stack data structure implementation using dynamic array
 *
 * Implements a Last-In-First-Out (LIFO) data structure with automatic
 * memory management and cleanup optimizations.
 *
 * Features:
 * - Push/Pop operations
 * - Top element access
 * - Memory optimization with periodic cleanup
 * - Printable interface for debugging
 */

// filepath: e:\Playground\Stack.h
#pragma once
#include "Vector.h"
#include "PrintableSequence.h"
#include <assert.h>

/**
 * @class Stack
 * @brief LIFO data structure implementation
 *
 * Uses an underlying Vector for storage with additional tracking
 * for stack-specific operations and memory optimization.
 */
class Stack {
public:
	/**
	 * @brief Default constructor - creates an empty stack
	 */
	Stack() {}

	/**
	 * @brief Constructor from initializer list
	 * @param data Initializer list containing initial elements to push onto stack
	 *
	 * Elements are pushed in the order they appear in the list.
	 */
	Stack(std::initializer_list<int> data) {
		for (auto& item : data)
			Push(item);
	}

	/**
	 * @brief Returns the top element of the stack
	 * @return The top element
	 *
	 * Asserts if stack is empty. Always check IsEmpty() before calling.
	 * Time complexity: O(1)
	 */
	int Top() {
		if (top == 0)
			assert(false);
		return v[top - 1];
	}

	/**
	 * @brief Removes the top element from the stack
	 *
	 * Performs memory optimization by cleaning up unused vector space
	 * when the difference between peak usage and current size is large.
	 * This prevents memory waste in scenarios with large temporary growth.
	 * Time complexity: O(1) amortized
	 */
	void Pop() {
		if (top != 0)
			top -= 1;
		if (peak - top >= 10)
		{
			v.RemoveIf([&](int index, int item) {
				return index > top;
			});
			peak -= 10;
		}
	}
	/**
	 * @brief Checks if the stack is empty
	 * @return true if stack contains no elements, false otherwise
	 */
	bool IsEmpty() {
		return top == 0;
	}

	/**
	 * @brief Adds an element to the top of the stack
	 * @param data The element to push onto the stack
	 *
	 * Updates both the current top and peak counters for memory management.
	 * Time complexity: O(1) amortized
	 */
	void Push(int data) {
		v.PushBack(data);
		top += 1;
		peak += 1;
	}
	/**
	 * @brief Returns the current number of elements in the stack
	 * @return The size of the stack
	 */
	int Size() {
		return top;
	}

	/**
	 * @brief Prints the current contents of the stack
	 *
	 * Uses PrintableSequence utility to display stack contents
	 * in a formatted manner for debugging purposes.
	 */
	void Print() {
		int* data = v.RawData();
		auto before = [](int* arr, int size) {
			std::cout << "Stack: \n\t";
		};

		auto after = [](int* arr, int size) {
			std::cout << "\n";
		};

		PrintableSequence::Print(data, Size(), before, after);
	}


private:
	Vector v;      ///< Underlying storage container
	int top = 0;   ///< Current number of elements (top of stack index + 1)
	int peak = 0;  ///< Maximum number of elements reached (for memory optimization)
};