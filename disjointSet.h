#pragma once
#include <vector>

class DisjointSet {
public:
    DisjointSet(const int* arr, int size) {
        data.resize(size);
        parent.resize(size);
        for(int i = 0; i < size; ++i){
            data[i] = arr[i];
            parent[i] = i;
        }
    }

    DisjointSet(const std::vector<int> vec)
        : data(vec)
    {
        parent.resize(vec.size());
        for (int i = 0; i < vec.size(); ++i) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    void unionElements(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) parent[a] = b;
    }

private:
    std::vector<int> data;
    std::vector<int> parent;

};