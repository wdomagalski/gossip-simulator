#include "Node.hpp"
#include <iostream>

Node::Node(int id) : id(id) {}

void Node::addNeighbor(int n, int delay) {
    neighbors.push_back(n);
    linkDelay.push_back(delay);
}

void Node::getMessage(int from, int delay, std::queue<std::pair<int, int>>& q) {
    if (seen) return;

    seen = true;
    
    std::cout << "Node " << id << " received message (+" << from << :ms) from " << from << "\n";

    for (size_t i = 0; i < neighbors.size(); i++) {
        int n = neighbors[i];
        int nextDelay = linkDelay[i];

        if (n != from) {
            q.push({n, nextDelay});
        }
    }
}
