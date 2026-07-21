# Experiment 06 - Routing Algorithms

## Aim

To study and implement the Distance Vector Routing Algorithm and Link State Routing Algorithm (Dijkstra's Algorithm) for finding the shortest path in a computer network.

---

## Theory

### 1. Distance Vector Routing Algorithm

Distance Vector Routing is a dynamic routing algorithm based on the Bellman-Ford algorithm. Each router maintains a routing table containing the distance (cost) to every other router. Routers periodically exchange their routing tables with neighboring routers and update their own tables whenever a shorter path is found. The process continues until no further updates occur, indicating that the network has converged.

### 2. Link State Routing Algorithm (Dijkstra's Algorithm)

Link State Routing is based on Dijkstra's shortest path algorithm. Every router has complete knowledge of the network topology and independently computes the shortest path from itself to all other routers. This algorithm provides faster convergence and more accurate routing information than Distance Vector Routing.

---

## Algorithms

### Algorithm 1: Distance Vector Routing

1. Read the number of routers.
2. Input the cost matrix.
3. Initialize the routing table with the given cost matrix.
4. Repeat until no updates occur:
   - Compare all possible paths through intermediate routers.
   - Update the routing table if a shorter path is found.
5. Display the routing table after each iteration.

---

### Algorithm 2: Link State Routing (Dijkstra's Algorithm)

1. Read the number of routers.
2. Input the cost matrix.
3. Read the source router.
4. Initialize the distance, visited, and parent arrays.
5. Mark the source router as visited.
6. Repeat until all routers are processed:
   - Select the unvisited router having the minimum distance.
   - Mark it as visited.
   - Update the distances of all adjacent routers if a shorter path is found.
7. Display the shortest distance from the source router to every other router.

---

## Programs

- `distance_vector.cpp`
- `link_state.cpp`

---

## Sample Input

```
Enter number of routers:
4

Enter cost matrix:
0 2 999 1
2 0 3 2
999 3 0 4
1 2 4 0

Enter source router:
1
```

---

## Sample Output

### Distance Vector Routing

```
Iteration 1

Router 1
Destination    Cost
1              0
2              2
3              5
4              1

Router 2
Destination    Cost
1              2
2              0
3              3
4              2

Router 3
Destination    Cost
1              5
2              3
3              0
4              4

Router 4
Destination    Cost
1              1
2              2
3              4
4              0
```

### Link State Routing

```
Shortest Distance from Router 1

Destination    Distance
1              0
2              2
3              5
4              1
```

---

## Conclusion

The Distance Vector Routing and Link State Routing algorithms were successfully implemented. Distance Vector Routing updates routing tables iteratively until convergence, while Link State Routing uses Dijkstra's Algorithm to compute the shortest path from a source router to all other routers efficiently.