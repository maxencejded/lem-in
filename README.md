# lem-in
A riff on the classic 90s video game. Developers design their own implementation of Dijkstra’s pathfinding algorithm in C. This algorithm analyzes a unique input with a variable number of ants and then helps the colony navigate from the start of a maze to the end. Solutions tend to start off single-pathed. However, as software developers revise their code, solvers become multi-pathed, recursive, and weighted for distance or number of hops. All solutions involve rigorous input validation, algorithmic optimization, and a graphical output to watch the ants find their home.

## Installation
```console
$ git clone https://github.com/maxencejded/lem-in.git --recursive
```

## Usage
```console
$ make
$ ./lem-in -q
4
##start
S 0 0
##end
T 2 2
A 1 1
B 0 1
C 1 0
S-A
A-C
C-T
S-B
B-T

L0-A L1-B
L0-C L1-T L2-B
L0-T L2-T L3-B
L3-T
$
```

### Flags
| Command | Description |
| ------ | ------ |
| -p | Print paths |
| -q | Quiet mode |

## Format
The map has a specific format:
```console
3         <- Number of Ants
##start   <- Indicate the starting point
##end     <- Indicate the end
S 0 0     <- Format Room `NAME X Y`
S-T       <- Link between two rooms (undirected graph)
^D        <- end
```

## Allowed functions:
`malloc`, `free`, `perror`, `strerror`, `read`, `write`, `exit`.
## Keywords
C language, problem solving, pathfinding, Dijkstra’s algorithm, efficiency, optimization.
