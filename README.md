# gossip-simulator

A C++ simulation modeling decentralized message propagation across a dynamic network topology. This project demonstrates core concepts used in P2P networks.

## Key Features

* **Decentralized Message Propagation:** Implements a message-passing mechanism where nodes relay information only to unseen neighbors.
* **Dynamic Network Topology:** Uses C++ random number generation to quickly generate a random graph with configurable nodes and links.
* **BFS-like Traversal:** Utilizes a queue to manage message propagation, ensuring all accesible nodes are reached efficiently.

## Core logic

1. **Network Setup:** 'main.cpp' initializes 'NODE_COUNT' objects and connects them randomly using 'RANDOM_LINKS' to create the network graph.
2. **Seeding the Gossip:** A starting node is marked as 'seen' and its ID is pushed onto the global message queue
3. **Propagation Loop:** The 'while (!q.empty())' loop drives the simulation. When a node receives a message, its 'getMessage()' method:
   * Marks the node as 'seen'.
   * Enqueues all its unvisited neighbors to receive the message in the next step.
4. **Result:** The simulation terminates when the queue is empty and it reports the total number of nodes reached.

## Build and Run

This project requires a standard C++ compiler (like GCC or Clang) supporting C++11 or newer.

```bash
g++ -o gossip main.cpp Node.cpp -std=c++11
./gossip
```
