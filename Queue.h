/**
 * @file Queue.h
 * @brief Queue data structure implementation using dynamic array
 *
 * Implements a First-In-First-Out (FIFO) data structure with automatic
 * memory management and cleanup optimizations.
 *
 * Features:
 * - Push/Pop operations
 * - Front and back element access
 * - Memory optimization with periodic cleanup
 * - Printable interface for debugging
 */

// filepath: e:\Playground\Queue.h
#pragma once
#include "Vector.h"
#include "PrintableSequence.h"
#include <assert.h>

/**
 * @class Queue
 * @brief FIFO data structure implementation
 *
 * Uses an underlying Vector for storage with front/back pointers
 * for efficient queue operations and memory optimization.
 */
class Queue : public PrintableSequence {
public:
	/**
	 * @brief Default constructor - creates an empty queue
	 */
	Queue() {}

	/**
	 * @brief Constructor from initializer list
	 * @param data Initializer list containing initial elements to enqueue
	 *
	 * Elements are enqueued in the order they appear in the list.
	 */
	Queue(std::initializer_list<int> data) {
		for (auto& item : data)
			Push(item);
	}

	/**
	 * @brief Returns the front element of the queue (next to be dequeued)
	 * @return The front element
	 *
	 * Note: Method name is misleading - returns the last added element.
	 * Asserts if queue is empty. Always check IsEmpty() before calling.
	 * Time complexity: O(1)
	 */
	int Top() {
		if (top == 0)
			assert(false);
		return v[top - 1];
	}

	/**
	 * @brief Returns the back element of the queue (first to be dequeued)
	 * @return The back element
	 *
	 * Asserts if queue is empty. Always check IsEmpty() before calling.
	 * Time complexity: O(1)
	 */
	int Back() {
		if (back == -1)
			assert(false);
		return v[back];
	}


	/**
	 * @brief Removes the front element from the queue
	 *
	 * Performs memory optimization by cleaning up unused vector space
	 * when back pointer exceeds threshold (10 elements).
	 * This prevents memory waste from dequeued elements.
	 * Time complexity: O(1) amortized, O(n) when cleanup occurs
	 */
	void Pop() {
		back += 1;
		if (back > 10) // insert some fancy metric
		{
			v.RemoveIf([](int index, int item) {
				return index <= 10;
			});
			back = 0;
			top -= 10;
		}
	}
	/**
	 * @brief Checks if the queue is empty
	 * @return true if queue contains no elements, false otherwise
	 */
	bool IsEmpty() {
		return Size() == 0;
	}

	/**
	 * @brief Returns the current number of elements in the queue
	 * @return The size of the queue
	 */
	int Size() {
		return top - back + 1;
	}

	/**
	 * @brief Adds an element to the back of the queue
	 * @param data The element to enqueue
	 *
	 * Time complexity: O(1) amortized
	 */
	void Push(int data) {
		v.PushBack(data);
		top += 1;
	}

	/**
	 * @brief Prints the current contents of the queue
	 *
	 * Uses PrintableSequence utility to display queue contents
	 * in a formatted manner for debugging purposes.
	 */
	void Print() {
		int* data = v.RawData() + back + 1;
		auto before = [](int* arr, int size) {
			std::cout << "Queue: \n\t";
		};

		auto after = [](int* arr, int size) {
			std::cout << "\n";
		};

		PrintableSequence::Print(data, Size(), before, after);
	}

private:
	Vector v;        ///< Underlying storage container
	int back = -1;   ///< Index of the front element (next to be dequeued)
	int top = 0;     ///< Index after the last element (next insertion position)
};