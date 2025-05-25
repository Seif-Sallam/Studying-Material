#include <iostream>
#include <algorithm>
#include <iomanip>
#include <memory>
#include <thread>
#include "sortingAlgorithms.h"

// bool is_sorted(int*, int);
// bool is_sorted(int*, int, int);

// void print_arr(int* arr, int size)
// {
// 	std::cout << "Array Sorted: {" << std::boolalpha << is_sorted(arr, size) << "}:\n\tData:[";
// 	for (int i = 0; i < size; ++i){
// 		if (i != size - 1)
// 			std::cout << arr[i] << ", ";
// 		else
// 			std::cout << arr[i];

// 	}
// 	std::cout << "]\n";

// }

// void print_arr(int* arr, int start, int end)
// {
// 	std::cout << "Array Sorted: {" << std::boolalpha << is_sorted(arr, start, end) << "}:\n\tData:[";
// 	for (int i = start; i <= end; ++i){
// 		if (i != end)
// 			std::cout << arr[i] << ", ";
// 		else
// 			std::cout << arr[i];

// 	}
// 	std::cout << "]\n";

// }

// bool is_sorted(int* arr, int start, int end) {
// 	for (int i = start; i <= end - 1; i++) {
// 		if (arr[i] > arr[i + 1])
// 			return false;
// 	}
// 	return true;
// }

// bool is_sorted(int* arr, int size) {
// 	for (int i = 0; i < size - 1; i++) {
// 		if (arr[i] > arr[i + 1])
// 			return false;
// 	}
// 	return true;
// }

// void selection_sort(int* arr, int size) {
// 	for (int i = 0; i < size; ++i) {
// 		int smallestIndex = i;
// 		for (int j = i + 1; j < size; ++j) {
// 			if (arr[smallestIndex] > arr[j])
// 				smallestIndex = j;
// 		}
// 		std::swap(arr[i], arr[smallestIndex]);
// 	}
// }

// void double_selection_sort(int*arr, int size) {
// 	int a, b;
// 	a = 0;
// 	b = size - 1;// 	while (a < b) {
// 		int smallestIndex = a;
// 		int largestIndex = a;
// 		// Select Largest and Smallest
// 		for (int i = a; i <= b; ++i) {
// 			if (arr[i] < arr[smallestIndex])
// 				smallestIndex = i;

// 			if (arr[i] > arr[largestIndex])
// 				largestIndex = i;
// 		}

// 		std::swap(arr[a], arr[smallestIndex]);
// 		// If the largest Index was A then it is now smallestIndex (they are swapped)
// 		if (largestIndex == a)
// 			largestIndex = smallestIndex;

// 		std::swap(arr[largestIndex], arr[b]);

// 		++a;
// 		--b;
// 	}

// }

// void insertion_sort(int* arr, int size) {
// 	for (int i = 0; i < size; ++i) {
// 		int j = i;
// 		while(j >= 1 && arr[j] < arr[j - 1]) {
// 			std::swap(arr[j], arr[j - 1]);
// 			--j;
// 		}
// 	}
// }

// int binary_search(int* arr, int start, int endIndex, int item) {
// 	int middle = 0;
// 	int size = endIndex - start;
// 	while (endIndex >= start) {
// 		int mid = start + (endIndex - start) / 2;
// 		if (item == arr[mid])
// 			return mid;
// 		else if (item > arr[mid])
// 			start = mid + 1;
// 		else if (item < arr[mid])
// 			endIndex = mid - 1;
// 	}
// 	// Return the lower bound instead of -1 when not found
// 	return start;
// }

// void binary_insertion_sort(int* arr, int size) {
// 	for (int i = 0; i < size; ++i) {
// 		// Save the item
// 		int item = arr[i];
// 		// Get where it should be
// 		int index = binary_search(arr, 0, i, item);
// 		int j = i - 1;
// 		// Shift all to the right until we reach
// 		while (j >= index) {
// 			arr[j + 1] = arr[j];
// 			--j;
// 		}
// 		arr[index] = item;
// 	}
// }

// void bubble_sort(int* arr, int size) {
// 	for (int i = 0; i < size; ++i) {
// 		for (int j = 0; j < size; ++j) {
// 			if (arr[i] < arr[j]){
// 				std::swap(arr[j], arr[i]);
// 			}
// 		}
// 	}
// }

// void shaker_sort(int* arr, int size) {
// 	int start = 0;
// 	int end = size - 1;
// 	bool swapped = true;
// 	while (swapped) {
// 		swapped = false;
// 		for (int i = start; i <= end - 1; ++i) {
// 			if (arr[i] > arr[ i + 1]) {
// 				std::swap(arr[i], arr[i + 1]);
// 				swapped = true;
// 			}
// 		}

// 		if (!swapped)
// 			break;

// 		swapped = false;
// 		end -= 1;

// 		for (int i = end - 1; i >= start; --i) {
// 			if (arr[i] > arr[i + 1]) {
// 				std::swap(arr[i], arr[i + 1]);
// 				swapped = true;
// 			}
// 		}
// 		start += 1;
// 	}

// }

// int partition2(int* arr, int start, int end) {
// 	int pivotIndexOG = start + (end - start) /2;
// 	// Swap the pivot to the end
// 	std::swap(arr[pivotIndexOG], arr[end]);
// 	int pivot = end;

// 	int indexFromTheLeft = start;
// 	int indexFromTheRight = end - 1;
// 	while (indexFromTheLeft < indexFromTheRight) {
// 		// Start with invalid indices
// 		indexFromTheLeft = -1;
// 		indexFromTheRight = -1;
// 		// Choose first item to be larger than the pivot from the left
// 		for (int i = start; i <= end - 1; i++) {
// 			if (arr[i] > arr[pivot])
// 			{
// 				indexFromTheLeft = i;
// 				break;
// 			}
// 		}

// 		// Choose first item to be smaller than the pivot from the right
// 		for (int i = end - 1; i >= start; i--) {
// 			if (arr[i] < arr[pivot])
// 			{
// 				indexFromTheRight = i;
// 				break;
// 			}
// 		}

// 		// Make sure that both indices are valid and swap them
// 		if (indexFromTheLeft < indexFromTheRight && indexFromTheLeft != -1 && indexFromTheRight != -1)
// 			std::swap(arr[indexFromTheLeft], arr[indexFromTheRight]);
// 		else
// 			break;
// 	}
// 	// If the index from the left is invalid (the pivot is the largest)
// 	//  else, we put the pivot in the place of the largest item (the largest item should be in the end)
// 	if (indexFromTheLeft != -1 && arr[indexFromTheLeft] > arr[pivot])
// 		std::swap(arr[indexFromTheLeft], arr[pivot]);

// 	return indexFromTheLeft;
// }

// int partition(int* arr, int start, int end) {
// 	int pivot = start;
// 	// Right indicator (searches for the smallest)
// 	int a = start + 1;
// 	for (int b = a; b <= end; ++b){
// 		// If the array at the left is smaller than the pivot then
// 		if (arr[b] < arr[pivot]) {
// 			std::swap(arr[a], arr[b]);
// 			++a;
// 		}
// 	}
// 	std::swap(arr[a - 1], arr[pivot]);
// 	return a - 1;
// }

// void quick_sort_req(int* arr, int start, int end) {
// 	if (start >= end)
// 		return;

// 	int partitionIndex = partition2(arr, start, end);
// 	quick_sort_req(arr, start, partitionIndex - 1);
// 	quick_sort_req(arr, partitionIndex + 1, end);
// }

// void quick_sort(int* arr, int size) {
// 	quick_sort_req(arr, 0, size - 1);
// }

// void combine_halves(int* arr, int start, int end, int mid) {
// 	int* copy = new int[end - start + 1];
// 	int a = start, b = mid + 1;
// 	int x = 0;
// 	while (a <= mid && b <= end)
// 	{
// 		if (arr[a] < arr[b])
// 		{
// 			copy[x] = arr[a];
// 			a++;
// 		}
// 		else
// 		{
// 			copy[x] = arr[b];
// 			b++;
// 		}
// 		x++;
// 	}
// 	// std::cout << "A: " << a << " mid: " << mid << std::endl;
// 	while (a <= mid) {
// 		copy[x] = arr[a];
// 		a++;
// 		x++;
// 	}
// 	while (b <= end) {
// 		copy[x] = arr[b];
// 		b++;
// 		x++;
// 	}

// 	for (int i = start, x = 0; i <= end; ++i, ++x)
// 		arr[i] = copy[x];

// 	delete[] copy;
// }


// void merge_sort_req(int* arr, int start, int end) {
// 	if (start >= end)
// 		return;

// 	int mid = start + (end - start) / 2;
// 	merge_sort_req(arr, start, mid);
// 	merge_sort_req(arr, mid + 1, end);

// 	combine_halves(arr, start, end, mid);
// }

// void merge_sort(int* arr, int size) {
// 	merge_sort_req(arr, 0, size - 1);
// }

// void max_heapify(int* arr, int size, int i) {
// 	int largest = i;
// 	int left = 2 * i + 1;
// 	int right = 2 * i + 2;

// 	if (left < size && arr[left] > arr[largest])
// 		largest = left;
// 	if (right < size && arr[right] > arr[largest])
// 		largest = right;

// 	if (largest != i) {
// 		std::swap(arr[i], arr[largest]);
// 		max_heapify(arr, size, largest);
// 	}
// }

// void build_max_heap(int* arr, int size) {
// 	for (int i = size / 2 - 1; i >= 0; --i)
// 		max_heapify(arr, size, i);
// }

// void heap_sort(int* arr, int size) {
// 	build_max_heap(arr, size);
// 	for (int i = size - 1; i >= 0; --i) {
// 		std::swap(arr[0], arr[i]);
// 		max_heapify(arr, i, 0);
// 	}
// }

int TESTS = 0;
int CORRECT = 0;
int FAILED = 0;

void test(void(* function)(int*, int)) {
	int arr1[] = {42, 50, 7, 19, 3, 88, 12, 57, 6, 31, 75, 1, 99, 24, 17, 63, 5, 81, 38, 14, 29};
	int arr2[] = {1,5,2,4,3};
	int arr3[] = {2,6,5,3,8,7,1,0};
	int arr4[] = {5,4,3,2,1};
	int arr5[] = {1,2,3,4,5};

	int size1 = sizeof(arr1) / sizeof(int);
	int size2 = sizeof(arr2) / sizeof(int);
	int size3 = sizeof(arr3) / sizeof(int);
	int size4 = sizeof(arr4) / sizeof(int);
	int size5 = sizeof(arr5) / sizeof(int);

	bool test[] = {
		true,
		true,
		true,
		true,
		true
	};

	std::cout << "++++++++++++++++\n";
	if (test[0]){
		std::cout << "Test: " << 1 << "\nBefore: " << std::endl;
		print_arr(arr1, size1);
		function(arr1, size1);
		std::cout << "After: " << std::endl;
		print_arr(arr1, size1);
		std::cout << "++++++++++++++++\n";
		TESTS += 1;
		CORRECT += (is_sorted(arr1, size1));
		FAILED += !(is_sorted(arr1, size1));
	}
	if (test[1]){
		std::cout << "Test: " << 2 << "\nBefore: " << std::endl;
		print_arr(arr2, size2);
		function(arr2, size2);
		std::cout << "After: " << std::endl;
		print_arr(arr2, size2);
		std::cout << "++++++++++++++++\n";
		TESTS += 1;
		CORRECT += (is_sorted(arr2, size2));
		FAILED += !(is_sorted(arr2, size2));
	}
	if (test[2]){
		std::cout << "Test: " << 3 << "\nBefore: " << std::endl;
		print_arr(arr3, size3);
		function(arr3, size3);
		std::cout << "After: " << std::endl;
		print_arr(arr3, size3);
		std::cout << "++++++++++++++++\n";
		TESTS += 1;
		CORRECT += (is_sorted(arr3, size3));
		FAILED += !(is_sorted(arr3, size3));
	}
	if (test[3]){
		std::cout << "Test: " << 4 << "\nBefore: " << std::endl;
		print_arr(arr4, size4);
		function(arr4, size4);
		std::cout << "After: " << std::endl;
		print_arr(arr4, size4);
		std::cout << "++++++++++++++++\n";
		TESTS += 1;
		CORRECT += (is_sorted(arr4, size4));
		FAILED += !(is_sorted(arr4, size4));
	}
	if (test[4]){
		std::cout << "Test: " << 5 << "\nBefore: " << std::endl;
		print_arr(arr5, size5);
		function(arr5, size5);
		std::cout << "After: " << std::endl;
		print_arr(arr5, size5);
		std::cout << "++++++++++++++++\n";
		TESTS += 1;
		CORRECT += (is_sorted(arr5, size5));
		FAILED += !(is_sorted(arr5, size5));
	}
}

#include "SegmentTree.h"


int main(){

	// test(selection_sort);
	// test(double_selection_sort);
	// test(bubble_sort);
	// test(shaker_sort);
	// test(insertion_sort);
	// test(binary_insertion_sort);
	// test(quick_sort);
	// test(merge_sort);
	// test(heap_sort);

	// std::cout << "Tested: " << TESTS << std::endl;
	// std::cout << "PASSED: " << CORRECT << " / " << TESTS << std::endl;
	// std::cout << "FAILED: " << FAILED << std::endl;
	// int n = 4, m = 5;
	// for (int i = 0; i < m; ++i) {
	// 	for (int j = 0; j < n; ++j) {
	// 		std::cout <<  i * n + j << " ";
	// 	}
	// 	std::cout << '\n';
	// }


	std::vector<int> data = {
		1, 2, 3, 4, 5
	};
	SegmentTree tree(data);
	for(int i = 1; i <= 5; ++i) {
		std::cout << tree.sumRange(0, i - 1) << std::endl;
	}

	// FenwickTree tree(data);

	// for (int i = 1; i <= 5; ++i)
	// 	std::cout << tree.querySum(i) << std::endl;

	// std::cout << tree.queryRange(3, 5) << std::endl;
}