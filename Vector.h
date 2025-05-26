#pragma once
#include <initializer_list>
#include <string.h>
#include <functional>
#include <assert.h>

class Vector {
public:
	Vector()
		: arr(nullptr), size(0), capacity(0)
	{
		Reallocate(6);
	}

	Vector(std::initializer_list<int> data)
		: arr(nullptr), size(0), capacity(0)
	{
		Reallocate(data.size() * 1.5);
		unsigned int i = 0;
		for (auto& item : data)
			arr[i++] = item;
		size = data.size();
	}

	void PushBack(int data) {
		if (size == capacity)
			Reallocate(capacity * 1.5);

		arr[size] = data;
		size += 1;
	}

	void PushFront(int data) {
		if (size + 1 >= capacity)
			Reallocate(capacity * 1.5);

		for (int i = size; i > 0; --i)
			Swap(arr[i], arr[i - 1]);

		arr[0] = data;
		size += 1;
	}

	const int Size() const {
		return size;
	}

	const int Capacity() const {
		return capacity;
	}

	int Back() {
		if (size == 0)
			return -1;
		return arr[size - 1];
	}

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

	int& At(int index) {
		if (index >= size || index < 0)
			assert(false);
		return arr[index];
	}

	int& operator[](int index) {
		return At(index);
	}

	const int operator[](int index) const {
		if (index >= size || index < 0)
			assert(false);
		return arr[index];
	}

	int* RawData() {
		return arr;
	}

private:
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

	void Swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

	int size;
	int capacity;
	int* arr;
};