# Shortest-Path-with-Visuals
Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data structures. It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as a ‘search key’) and explores the neighbor nodes first, before moving to the next level neighbors.
It uses a queue data structure to store the next set of nodes to visit. BFS is useful for finding the shortest path between two nodes in an unweighted graph.
It can also be used to solve many other problems in graph theory, for example:

Testing a graph for bipartiteness.
Finding all connected components in a graph.
Finding the shortest path between two nodes u and v, with path length measured in number of edges (an advantage over Dijkstra's algorithm, which can only handle non-negative edge weights).
Finding all nodes within one connected component that are at a certain shortest distance from a specific node.
solving the Rubik's Cube puzzle
traversing a maze
finding all nodes reachable from a given set of nodes

BFS processes the graph or tree by exploring all the vertices at the current depth level before moving on to the next level. It uses a queue data structure to keep track of the next set of nodes to visit.

The basic steps of the BFS algorithm are as follows:

1. Start at the root node (or search key) and enqueue it into the queue.
2. Dequeue a node from the queue and examine it.
3. If the desired node is found, the search is complete.
4. If the examined node has any unvisited child nodes, enqueue them into the queue and mark them as visited.
5. Repeat steps 2-4 until the queue is empty or the desired node is found.

It is important to note that BFS will always find the shortest path to a node in an unweighted graph.

<img width="796" alt="graph" src="https://user-images.githubusercontent.com/114533891/212448008-f5ab0cf8-9aa6-45e1-a241-15d5cdfc2570.png">


