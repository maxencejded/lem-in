# lem-in
This project is meant to make you code an ant farm manager - 42 Silicon Valley

# the problem

Input: a file representing a graph
Output: sequence of steps to send a number of units through the graph in a minimal sequence of steps

The graph is not directed

# architecture

```
file
  |
parser -> graph
            |
       preprocessor -> residual graph (transform reverse edges, no node capacity, create reverse edges)
                              |
                          max_flow -> flow graph
                                           |
                                        BFS/DFS -> paths with flow (aproximate a min-cost flow)
                                                          |
                                                      execution -> sequence of steps
```
