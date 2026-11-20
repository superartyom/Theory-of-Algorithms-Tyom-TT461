def topsort(g):
    n = len(g)
    v = [False] * n
    order = [0] * n
    i = n - 1

    def dfs(at):
        nonlocal i
        v[at] = True
        for _ in g[at]:
            if not v[_]:
                dfs(_)
        order[i] = at
        i -= 1

    for _ in range(n):
        if not v[_]:
            dfs(_)
    return order
  
