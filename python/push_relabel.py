from pprint import pprint

def init_height(residual_graph, s):
	height = {}
	for v in residual_graph:
		height[v] = 0
	height[s] = len(residual_graph)
	return height

def init_residual_graph(graph, excess, s):
	residual_graph = {}
	for v in graph:
		if v not in residual_graph:
			residual_graph[v] = {}
		for w in graph[v]:
			if w not in residual_graph:
				residual_graph[w] = {}
			residual_graph[v][w] = graph[v][w].copy()
			residual_graph[w][v] = graph[v][w].copy()
	for v in residual_graph[s]:
		initial_flow = residual_graph[s][v][0]
		excess[v] = initial_flow
		residual_graph[s][v][1] = initial_flow
	return residual_graph

def init_excess(graph):
	excess = {}
	for v in graph:
		excess[v] = 0
	return excess

def get_vertice_with_exess(residual_graph, excess, height, s, t):
	max_h = -1
	v_max_h = None
	for v in residual_graph:
		if v == s or v == t:
			continue
		if excess[v] > 0 and height[v] > max_h:
			max_h = height[v]
			v_max_h = v
	return v_max_h

def get_downhill_neighbor(residual_graph, height, v):
	for w in residual_graph[v]:
		if height[w] == height[v] - 1 and capacity(residual_graph[v][w]) > 0:
			return w
	return None

def capacity(v):
	return v[0] - v[1]

def push(residual_graph, excess, v, w):
	delta = min(
		excess[v],
		capacity(residual_graph[v][w])
	)
	excess[v] -= delta
	excess[w] += delta
	residual_graph[v][w][1] += delta

def set_flows(graph, residual_graph):
	for v in graph:
		for w in graph[v]:
			net_flow = abs(residual_graph[v][w][1] - residual_graph[w][v][1])
			graph[v][w][1] = net_flow

def pr_max_flow(graph, s, t):
	excess = init_excess(graph)
	residual_graph = init_residual_graph(graph, excess, s)
	height = init_height(residual_graph, s)
	while 1:
		v = get_vertice_with_exess(residual_graph, excess, height, s, t)
		if v is None:
			break
		w = get_downhill_neighbor(residual_graph, height, v)
		if w is None:
			height[v] += 1
		else:
			push(residual_graph, excess, v, w)
	set_flows(graph, residual_graph)

def main():
	# Edges are not directed, no reciprocal edges are allowed
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
	pr_max_flow(g, 'S', 'T')
	pprint(g)

if __name__ == "__main__":
	main()
