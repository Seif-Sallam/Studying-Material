#pragma once
#include <iostream>
#include <iomanip>

/**
 * SORTING ALGORITHMS COLLECTION
 *
 * This file contains implementations of various sorting algorithms with different
 * time and space complexities. Each algorithm is documented with its characteristics.
 */

/**
 * Swaps two integer values
 * @param a First integer reference
 * @param b Second integer reference
 */
void swap(int& a, int& b) {
	int temp = b;
	b = a;
	a = temp;
}

/**
 * Checks if an array segment is sorted in ascending order
 * @param arr Pointer to the array
 * @param start Starting index (inclusive)
 * @param end Ending index (inclusive)
 * @return true if sorted, false otherwise
 */
bool is_sorted(int* arr, int start, int end) {
	for (int i = start; i < end; ++i)
		if (arr[i + 1] < arr[i])
			return false;
	return true;
}

/**
 * Checks if entire array is sorted in ascending order
 * @param arr Pointer to the array
 * @param size Size of the array
 * @return true if sorted, false otherwise
 */
bool is_sorted(int* arr, int size) {
	return is_sorted(arr, 0, size - 1);
}

/**
 * Prints array segment with sorting status
 * @param arr Pointer to the array
 * @param start Starting index (inclusive)
 * @param end Ending index (inclusive)
 */
void print_arr(int* arr, int start, int end) {
	std::cout << "Array: Is sorted:" << std::boolalpha << is_sorted(arr, start, end) << "\n\tData: [";
	for (int i = start; i <= end; ++i) {
		if (i != end)
			std::cout << arr[i] << ", ";
		else
			std::cout << arr[i];
	}
	std::cout << "]\n";
}

/**
 * Prints entire array with sorting status
 * @param arr Pointer to the array
 * @param size Size of the array
 */
void print_arr(int* arr, int size) {
	return print_arr(arr, 0, size - 1);
}

/**
 * SELECTION SORT
 * Time Complexity: O(n²) - always, regardless of input
 * Space Complexity: O(1) - in-place sorting
 * Stability: Unstable
 *
 * Algorithm: Repeatedly finds the minimum element from unsorted portion
 * and places it at the beginning of the sorted portion.
 */
void selection_sort(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		int smallest = i;
		for (int j = i + 1; j < size; ++j) {
			if (arr[j] < arr[smallest]){
				smallest = j;
			}
		}
		swap(arr[i], arr[smallest]);
	}
}

/**
 * DOUBLE SELECTION SORT (Bidirectional Selection Sort)
 * Time Complexity: O(n²) - but roughly half the comparisons of regular selection sort
 * Space Complexity: O(1) - in-place sorting
 * Stability: Unstable
 *
 * Algorithm: Selects both minimum and maximum elements in each pass,
 * placing them at both ends of the unsorted portion.
 */
void double_selection_sort(int* arr, int size) {
	int a = 0, b = size - 1;
	while(a < b){
		int smallest = a;
		int largest = a;
		for (int i = a + 1; i <= b; ++i) {
			if (arr[i] < arr[smallest])
				smallest = i;
			if (arr[i] > arr[largest])
				largest = i;
		}

		std::cout << "Smallest: " << smallest << ", Largest: " << largest << std::endl;

		swap(arr[smallest], arr[a]);
		if (largest == a);
			largest = smallest;
		swap(arr[largest], arr[b]);
		++a;
		--b;
	}
	std::cout << "===========================\n";
	a = 0;
	b = size - 1;

	while (a < b) {
		int smallestIndex = a;
		int largestIndex = a;
		// Select Largest and Smallest
		for (int i = a; i <= b; ++i) {
			if (arr[i] < arr[smallestIndex])
				smallestIndex = i;

			if (arr[i] > arr[largestIndex])
				largestIndex = i;
		}
		std::cout << "Smallest: " << smallestIndex << ", Largest: " << largestIndex << std::endl;

		std::swap(arr[a], arr[smallestIndex]);
		// If the largest Index was A then it is now smallestIndex (they are swapped)
		if (largestIndex == a)
			largestIndex = smallestIndex;

		std::swap(arr[largestIndex], arr[b]);

		++a;
		--b;
	}
}


/**
 * BUBBLE SORT
 * Time Complexity: O(n²) - worst and average case, O(n) best case (if optimized)
 * Space Complexity: O(1) - in-place sorting
 * Stability: Stable
 *
 * Algorithm: Repeatedly steps through the list, compares adjacent elements
 * and swaps them if they're in wrong order.
 */
void bubble_sort(int* arr, int size) {
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			if (arr[i] < arr[j])
				swap(arr[j], arr[i]);
}

/**
 * SHAKER SORT (Cocktail Shaker Sort / Bidirectional Bubble Sort)
 * Time Complexity: O(n²) - worst case, O(n) best case
 * Space Complexity: O(1) - in-place sorting
 * Stability: Stable
 *
 * Algorithm: Variation of bubble sort that sorts in both directions,
 * reducing the number of passes needed for certain data patterns.
 */
void shaker_sort(int* arr, int size) {
	int start = 0;
	int end = size - 1;
	bool swapped = true;
	while (start < end)
	{
		swapped = false;

		for (int i = start; i <= end - 1; ++i) {
			if (arr[i + 1] < arr[i]){
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;
		swapped = false;

		for (int j = end; j > 0; --j) {
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
				swapped = true;
			}
		}
		start += 1;
		end -= 1;
	}
}

/**
 * INSERTION SORT
 * Time Complexity: O(n²) - worst case, O(n) best case (nearly sorted)
 * Space Complexity: O(1) - in-place sorting
 * Stability: Stable
 *
 * Algorithm: Builds sorted array one element at a time by repeatedly
 * taking an element and inserting it into its correct position.
 */
void insertion_sort(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		int j = i;
		while (j >= 1 && arr[j] < arr[j - 1])
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}

/**
 * Binary search helper for binary insertion sort
 * Finds the correct position to insert an item in a sorted array
 * @param arr Sorted array to search in
 * @param start Starting index
 * @param end Ending index
 * @param item Item to find position for
 * @return Index where item should be inserted
 */
int binary_search(int* arr, int start, int end, int item) {
	if (start >= end)
		return start;
	int mid  = start + (end - start) / 2;
	if (arr[mid] == item)
		return mid;
	if (arr[mid] > item)
		return binary_search(arr, start, mid, item);
	if (arr[mid] < item)
		return binary_search(arr, mid + 1, end, item);

}

/**
 * BINARY INSERTION SORT
 * Time Complexity: O(n²) - due to shifting, but fewer comparisons than regular insertion sort
 * Space Complexity: O(1) - in-place sorting
 * Stability: Stable
 *
 * Algorithm: Uses binary search to find the correct position for insertion,
 * reducing the number of comparisons compared to linear insertion sort.
 */
void binary_insertion_sort(int* arr, int size){
	for(int i = 0; i < size; ++i) {
		int value = arr[i];
		int index = binary_search(arr, 0, i, value);
		int j = i - 1;
		while (j >= index) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[index] = value;
	}
}

/**
 * Partition function for quicksort
 * Rearranges array so elements smaller than pivot are on left,
 * larger elements are on right
 * @param arr Array to partition
 * @param start Starting index
 * @param end Ending index
 * @return Final position of pivot element
 */
int partition(int* arr, int start, int end) {
	int pivot = start + (end - start) / 2; // Middle item
	swap(arr[pivot], arr[end]); // Moving the pivot to the end
	int left = start;
	int right = end - 1;
	pivot = end;

	while (left < right) {
		left = -1;
		right = -1;
		// get the smallest and largest
		for (int i = start; i < end; ++i) {
			if (arr[i] > arr[pivot])
			{
				left = i;
				break;
			}
		}

		for (int i = end - 1; i >= start; --i) {
			if (arr[i] < arr[pivot])
			{
				right = i;
				break;
			}
		}

		if (left > right)
			break;

		if (left != -1 && right != -1)
			swap(arr[left], arr[right]);
	}
	if (left != -1 && arr[left] > arr[pivot])
		swap(arr[pivot], arr[left]); // getting the smallest at the pivot instead of keeping it in the middle

	return left; // the actual partition point.
}

/**
 * Recursive helper function for quicksort
 * @param arr Array to sort
 * @param start Starting index
 * @param end Ending index
 */
void quick_sort_req(int* arr, int start, int end) {
	if (start >= end)
		return;
	int pi = partition(arr, start, end);
	quick_sort_req(arr, start, pi);
	quick_sort_req(arr, pi + 1, end);
}

/**
 * QUICK SORT
 * Time Complexity: O(n log n) average case, O(n²) worst case
 * Space Complexity: O(log n) - due to recursion stack
 * Stability: Unstable
 *
 * Algorithm: Divide-and-conquer algorithm that picks a pivot element
 * and partitions array around it, then recursively sorts sub-arrays.
 */
void quick_sort(int* arr, int size){
	return quick_sort_req(arr, 0, size -1);
}

/**
 * Merges two sorted halves of an array
 * @param arr Array containing both halves
 * @param start Starting index of first half
 * @param end Ending index of second half
 * @param mid Ending index of first half
 */
void combine_halves(int* arr, int start, int end, int mid) {
	int* copy = new int[(end - start)+ 1];
	int a = start, b = mid + 1, k = 0;
	while(a <= mid && b <= end) {
		if (arr[a] < arr[b]){
			copy[k] = arr[a];
			++a;
		}
		else {
			copy[k] = arr[b];
			++b;
		}
		++k;
	}
	while(a <= mid) {
		copy[k] = arr[a];
		++k; ++a;
	}

	while(b <= end) {
		copy[k] = arr[b];
		++b; ++k;
	}
	for (int i = start, k = 0; i <= end; ++i, ++k)
		arr[i] = copy[k];

	delete[] copy;
}

/**
 * Recursive helper function for merge sort
 * @param arr Array to sort
 * @param start Starting index
 * @param end Ending index
 */
void merge_sort_req(int* arr, int start, int end) {
	if (start >= end)
		return;
	int mid = start + (end - start) / 2;

	merge_sort_req(arr, start, mid);
	merge_sort_req(arr, mid + 1, end);
	combine_halves(arr, start, end, mid);
}

/**
 * MERGE SORT
 * Time Complexity: O(n log n) - always, regardless of input
 * Space Complexity: O(n) - requires additional memory for merging
 * Stability: Stable
 *
 * Algorithm: Divide-and-conquer algorithm that divides array into halves,
 * recursively sorts them, then merges the sorted halves.
 */
void merge_sort(int* arr, int size) {
	return merge_sort_req(arr, 0, size - 1);
}

/**
 * Maintains heap property for a subtree rooted at given index
 * @param arr Array representing the heap
 * @param size Size of the heap
 * @param index Root index of subtree to heapify
 */
void heapify(int* arr, int size, int index) {
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size  && arr[left] > arr[largest])
		largest = left;
	if (right < size && arr[right] > arr[largest])
		largest = right;

	if (largest != index) {
		swap(arr[index], arr[largest]);
		heapify(arr, size, largest);
	}
}

/**
 * Builds a max heap from an unsorted array
 * @param arr Array to convert to heap
 * @param size Size of the array
 */
void build_heap(int* arr, int size) {
	for (int i = size / 2 - 1; i >= 0; --i)
		heapify(arr, size, i);
}

/**
 * HEAP SORT
 * Time Complexity: O(n log n) - always, regardless of input
 * Space Complexity: O(1) - in-place sorting
 * Stability: Unstable
 *
 * Algorithm: Builds a max heap from the array, then repeatedly extracts
 * the maximum element and places it at the end of the sorted portion.
 */
void heap_sort(int* arr, int size) {
	build_heap(arr, size);

	for (int i = size - 1; i >= 0; --i) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
