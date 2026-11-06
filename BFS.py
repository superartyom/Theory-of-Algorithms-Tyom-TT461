from graph import graph

def bfs(graph, start, target):
    queue = [[start]]
    visited = {start}

    while queue:
        path = queue.pop(0)
        node = path[-1]

        if node == target:
            return path

        for neigh in graph[node]:
            if neigh not in visited:
                visited.add(neigh)
                queue.append(path + [neigh])
    return []

print(bfs(graph, 'A', 'I'))
