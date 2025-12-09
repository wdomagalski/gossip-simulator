#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <ctime>
#include "Node.hpp"

int main() {
    const int NODE_COUNT = 12;
    const int RANDOM_LINKS = 25;

    std::vector<Node> nodes;
    for (int i = 0; i < NODE_COUNT; i++) {
        nodes.emplace_back(i);
    }

    std::mt19937 rng(time(nullptr));
    std::uniform_int_distribution<int> dist(0, NODE_COUNT - 1);

    for (int i = 0; i < RANDOM_LINKS; i++) {
        int a = dist(rng);
        int b = dist(rng);
        if (a != b) {
            nodes[a].addNeighbor(b);
            nodes[b].addNeighbor(a);
        }
    }

    std::cout << "Starting gossip simulation...\n";

    std::queue<int> q;

    int start = 0;
    nodes[start].seen = true;
    q.push(start);

    int reached = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int n : nodes[cur].neighbors) {
            if (!nodes[n].seen) {
                nodes[n].getMessage(cur, q);
                reached++;
            }
        }
    }

    std::cout << "\nFinished.\n";
    std::cout << "Reached " << reached << " out of " << NODE_COUNT << " nodes.\n";

    return 0;
}