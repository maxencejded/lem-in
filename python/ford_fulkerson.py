import math
from pprint import pprint

def create_residual_graph(graph):
	rgraph = {}
	for v in graph:
		if v not in rgraph:
			rgraph[v] = graph[v].copy()
		for w in graph[v]:
			if w not in rgraph:
				rgraph[w] = {}
			rgraph[v][w] = graph[v][w].copy()
			rgraph[w][v] = [rgraph[v][w][0], 0]
	return rgraph

def get_residual_capacity(edge):
	return edge[0] - edge[1]

def find_path(graph, rgraph, s, e, path=None):
	"""
		Find s path in the resuidual graph, such that every edge has a positive residual capacity
	"""
	if path is None:
		path = []
	path.append(s)
	if s == e:
		return path
	for node in rgraph[s]:
		if node not in path and get_residual_capacity(rgraph[s][node]) > 0:
			npath = find_path(graph, rgraph, node, e, path.copy())
			if npath:
				return npath
	return None

def get_min_residual_capacity(rgraph, path):
	min_cap = -1
	for i in range(len(path) - 1):
		cap = get_residual_capacity(rgraph[path[i]][path[i+1]])
		min_cap = cap if min_cap == -1 else min(min_cap, cap)
	return min_cap

def augment(rgraph, path):
	delta = get_min_residual_capacity(rgraph, path)
	for i in range(len(path) - 1):
		data = rgraph[path[i]][path[i+1]]
		data[1] += delta
		rgraph[path[i+1]][path[i]][1] -= delta

def ff_max_flow(graph, s, t):
	rgraph = create_residual_graph(graph)
	while 1:
		path = find_path(graph, rgraph, s, t)
		if path is None:
			break
		augment(rgraph, path)
	for u in graph:
		for v in graph[u]:
			graph[u][v] = rgraph[u][v]

"""
	Graph: { vertice name : { destination name : (capacity, flow) }}
	The graph is directed
"""

def main():
	# g = {
	# 	'S': {'A': [1, 0], 'C': [1, 0], 'D': [1, 0]},
	# 	'A': {'B': [1, 0]},
	# 	'B': {'E': [1, 0]},
	# 	'C': {'D': [1, 0]},
	# 	'D': {'F': [1, 0], 'G': [1, 0]},
	# 	'E': {'G': [1, 0]},
	# 	'F': {'I': [1, 0]},
	# 	'G': {'H': [1, 0], 'T': [1, 0]},
	# 	'H': {'T': [1, 0]},
	# 	'I': {'J': [1, 0]},
	# 	'J': {'T': [1, 0]},
	# 	'T': {}
	# }
	# g = {
	# 	'S': {'A': [1, 0], 'B': [1, 0]},
	# 	'T': {'D': [1, 0]},
	# 	'B': {'D': [1, 0], 'F': [1, 0]},
	# 	'C': {'F': [1, 0]},
	# 	'D': {'C': [1, 0]},
	# 	'F': {'T': [1, 0]},
	# 	'G': {'A': [1, 0], 'F': [1, 0], 'B': [1, 0]},
	# 	'A': {'C': [1, 0]},
	# }
	g = {
		'S': {'A': [1, 0]},
		'A': {'B': [1, 0]},
		'B': {'T': [1, 0]},
		'T': {},
	}
	# g = {
	# 	'S': {'A': [1, 0], 'B': [1, 0]},
	# 	'T': {'A': [1, 0]},
	# 	'B': {'C': [1, 0]},
	# 	'C': {'T': [1, 0]},
	# }
	# g = {
	# 	'S': {'A': [1, 0]},
	# 	'B': {'F': [1, 0], 'S':[1, 0]},
	# 	'E': {'F': [1, 0], 'T': [1, 0]},
	# 	'A': {'C': [1, 0], 'E': [1, 0]},
	# 	'D': {'C': [1, 0]},
	# 	'T': {'D': [1, 0]},
	# 	'F': {},
	# 	'C': {},
	# }
	ff_max_flow(g, 'S', 'T')
	pprint(g)


if __name__ == "__main__":
	main()
