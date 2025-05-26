#pragma once
#include "Vector.h"
#include "PrintableSequence.h"
#include <assert.h>

class Queue : public PrintableSequence {
public:
	Queue() {}
	Queue(std::initializer_list<int> data) {
		for (auto& item : data)
			Push(item);
	}

	int Top() {
		if (top == 0)
			assert(false);
		return v[top - 1];
	}

	int Back() {
		if (back == -1)
			assert(false);
		return v[back];
	}


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

	bool IsEmpty() {
		return Size() == 0;
	}

	int Size() {
		return top - back + 1;
	}

	void Push(int data) {
		v.PushBack(data);
		top += 1;
	}

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
	Vector v;
	int back = -1;
	int top = 0;
};