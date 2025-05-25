#pragma once
#include <iostream>
#include <iomanip>

void swap(int& a, int& b) {
    int temp = b;
    b = a;
    a = temp;
}

bool is_sorted(int* arr, int start, int end) {
    for (int i = start; i < end; ++i)
        if (arr[i + 1] < arr[i])
            return false;
    return true;
}

bool is_sorted(int* arr, int size) {
    return is_sorted(arr, 0, size - 1);
}

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

void print_arr(int* arr, int size) {
    return print_arr(arr, 0, size - 1);
}

// Going from left to right and select the smallest element
//   then put it in the left most item and so on until you finish.
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


void bubble_sort(int* arr, int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (arr[i] < arr[j])
                swap(arr[j], arr[i]);
}

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

void quick_sort_req(int* arr, int start, int end) {
    if (start >= end)
        return;
    int pi = partition(arr, start, end);
    quick_sort_req(arr, start, pi);
    quick_sort_req(arr, pi + 1, end);
}

void quick_sort(int* arr, int size){
    return quick_sort_req(arr, 0, size -1);
}

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

void merge_sort_req(int* arr, int start, int end) {
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;

    merge_sort_req(arr, start, mid);
    merge_sort_req(arr, mid + 1, end);
    combine_halves(arr, start, end, mid);
}

void merge_sort(int* arr, int size) {
    return merge_sort_req(arr, 0, size - 1);
}

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

void build_heap(int* arr, int size) {
    for (int i = size / 2 - 1; i >= 0; --i)
        heapify(arr, size, i);
}

void heap_sort(int* arr, int size) {
    build_heap(arr, size);

    for (int i = size - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
