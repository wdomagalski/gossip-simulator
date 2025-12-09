#include "Node.hpp"
#include <iostream>

Node::Node(int id) : id(id) {}

void Node::addNeighbor(int n) {
    neighbors.push_back(n);
}

void Node::getMessage(int from, std::queue<int>& q) {
    if (seen) return;

    seen = true;
    std::cout << "Node " << id << " received message from " << from << "\n";

    for (int n : neighbors) {
        if (n != from) {
            q.push(n);
        }
    }
}