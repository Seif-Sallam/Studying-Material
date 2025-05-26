/**
 * @file PrintableSequence.h
 * @brief Utility class for printing integer arrays with custom formatting
 *
 * Provides a static utility function for printing arrays with customizable
 * before/after formatting functions. Used as a base class or utility for
 * data structures that need formatted output.
 */

// filepath: e:\Playground\PrintableSequence.h
#pragma once
#include <iostream>
#include <functional>

/**
 * @class PrintableSequence
 * @brief Utility class providing formatted array printing functionality
 *
 * Contains static methods for printing integer arrays with customizable
 * formatting. Designed to be inherited by other classes or used as utility.
 */
class PrintableSequence {
public:
/**
 * @brief Prints an integer array with custom formatting
 * @param arr Pointer to the integer array to print
 * @param size Number of elements in the array
 * @param before Function called before printing the array (can be null)
 * @param after Function called after printing the array (can be null)
 *
 * Prints the array in format [elem1, elem2, ..., elemN]
 * with optional custom formatting before and after the array.
 */
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
	/**
	 * @brief Protected constructor to prevent direct instantiation
	 *
	 * This class is designed to be used as a utility or base class,
	 * not instantiated directly.
	 */
	PrintableSequence() {}
};