# Recitation 12 #

## Graphs ##

### Graph Notation ###
We say G = (V, E) for a graph G where
  * V is a set of vertices (or nodes)
  * E is a set of edges (node connections)
  * an edge is a tuple (u,v) for vertices u and v

### Graph Representation in a Program ###

#### Using an adjacency matrix ####
One way is this:
If there are n vertices (nodes), initialize a n x n array (array of arrays) storing integers.
Store a 1 in ary[u][v] if there is an edge connecting u to v and a 0 there otherwise.

#### Using an adjacency list ####
One way is this:
If there are n vertices (nodes), initialize an array of n lists storing integers.
If there is a connection from the uth vertex to the vth vertex, append a v to the list at the uth index of the array.

### Breadth First Search (BFS) ###
The general idea of the algorithm is:
 * Visit and inspect a node of a graph
 * Gain access to visit the nodes that neighbor the currently visited node
```
1  procedure BFS(G,v) is
2      create a queue Q
3      create a set V
4      add v to V
5      enqueue v onto Q
6      while Q is not empty loop
7         t ← Q.dequeue()
8         if t is what we are looking for then
9            return t
10        end if
11        for all edges e in G.adjacentEdges(t) loop
12           u ← G.adjacentVertex(t,e)
13           if u is not in V then
14               add u to V
15               enqueue u onto Q
16           end if
17        end loop
18     end loop
19     return none
20 end BFS
```

### Depth First Search (DFS) ###
With Depth First Search, we start at a node and explore as far as possible along each branch before backtracking.
DFS can be implemented the same way as BFS but with using a Stack instead of a Queue!
```
1  procedure DFS(G,v) is
2      create a stack Q
3      create a set V
4      add v to V
5      push v onto Q
6      while Q is not empty loop
7         t ← Q.pop()
8         if t is what we are looking for then
9            return t
10        end if
11        for all edges e in G.adjacentEdges(t) loop
12           u ← G.adjacentVertex(t,e)
13           if u is not in V then
14               add u to V
15               push u onto Q
16           end if
17        end loop
18     end loop
19     return none
20 end BFS
```
