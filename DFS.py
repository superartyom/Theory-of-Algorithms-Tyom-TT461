from graph import graph

def dfs(graph, start, target):
    stack = [[start]]
    visited = set()

    while stack:
        path = stack.pop()
        node = path[-1]

        if node == target:
            return path

        if node not in visited:
            visited.add(node)
            for neigh in graph[node]:
                if neigh not in visited:
                    stack.append(path + [neigh])
    return []

print(dfs(graph, 'A', 'I'))