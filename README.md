# gossip-simulator

A C++ simulation modeling decentralized message propagation across a dynamic network topology. This project demonstrates core concepts used in P2P networks.

## Key Features

* **Decentralized Message Propagation:** Implements a message-passing mechanism where nodes relay information only to unseen neighbors.
* **Dynamic Network Topology:** Uses C++ random number generation to quickly generate a random graph with configurable nodes and links.
* **BFS-like Traversal:** Utilizes a queue to manage message propagation, ensuring all accesible nodes are reached efficiently.

## Build and Run

This project requires a standard C++ compiler (like GCC or Clang) supporting C++11 or newer.

```bash
g++ -o gossip main.cpp Node.cpp -std=c++11
./gossip
```
