from graph_weights_hvals import graph, h

def a_star(graph, h, start, target):
    queue = [[start]]
    g_vals = {start: 0}

    while queue:
        best_index = 0
        best_f = float('inf')

        for i, path in enumerate(queue):
            curr_node = path[-1]
            g = g_vals[curr_node]
            f = g + h[curr_node]

            if f < best_f:
                best_f = f
                best_index = i

        curr_path = queue.pop(best_index)
        curr_node = curr_path[-1]

        if curr_node == target:
            return curr_path, g_vals[target]

        for neigh, weight in graph[curr_node].items():
            neigh_g = g_vals[curr_node] + weight

            if neigh not in g_vals or neigh_g < g_vals[neigh]:
                g_vals[neigh] = neigh_g
                queue.append(curr_path + [neigh])

    return [], float('inf')

path, cost = a_star(graph, h, 'A', 'I')
print(path, cost)