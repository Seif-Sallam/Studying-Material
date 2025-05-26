#pragma once
#include "Vector.h"
#include "PrintableSequence.h"
#include <assert.h>

class Stack {
public:
	Stack() {}

	Stack(std::initializer_list<int> data) {
		for (auto& item : data)
			Push(item);
	}

	int Top() {
		if (top == 0)
			assert(false);
		return v[top - 1];
	}

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

	bool IsEmpty() {
		return top == 0;
	}

	void Push(int data) {
		v.PushBack(data);
		top += 1;
		peak += 1;
	}

	int Size() {
		return top;
	}

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
	Vector v;
	int top = 0;
	int peak = 0;
};