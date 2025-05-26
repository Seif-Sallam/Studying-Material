#pragma once
#include <iostream>
#include <functional>

class PrintableSequence {
public:
static void Print(int* arr, int size,
	std::function<void(int*, int)> before, std::function<void(int*, int)> after) {
	if (before)
	before(arr, size);

	std::cout << "[";
	int i = 0;
	for(i = 0; i < size -1 ; ++i)
	std::cout << arr[i] << ", ";
	std::cout <<arr[i] << "]";

	if (after)
	after(arr, size);
}
protected:
	PrintableSequence() {}
};