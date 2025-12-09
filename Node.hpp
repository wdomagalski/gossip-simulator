#pragma once
#include <vector>
#include <queue>

class Node {
public:
    int id;
    std::vector<int> neighbors;
    bool seen = false;

    Node(int id);
    void addNeighbor(int n);
    void getMessage(int from, std::queue<int>& q);
};