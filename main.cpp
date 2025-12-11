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
            int delay = 5 + (rng() % 75);
            nodes[a].addNeighbor(b, delay);
            nodes[b].addNeighbor(a, delay);
        }
    }

    std::cout << "Starting gossip simulation...\n";

    std::queue<std::pair<int,int>> q;

    int start = 0;
    nodes[start].seen = true;
    q.push(start);

    int reached = 1;
    long totalTime = 0;

    while (!q.empty()) {
        auto [cur, delay] = q.front();
        q.pop();

        totalTime += delay;
        
        for (size_t i = 0; i < nodes[cur].neighbors.size(); i++) {
            int n = nodes[cur].neighbors[i];
            int linkDelay = nodes[cur].linkDelay[i];

            if (!nodes[n].seen) {
                nodes[n].getMessage(cur, linkDelay, q);
                reached++;
            }
        }
    }

    std::cout << "\nFinished.\n";
    std::cout << "Reached " << reached << " out of " << NODE_COUNT << " nodes.\n";
    std::cout << "Total propagation time: " << totalTime << " ms\n";

    return 0;
}
