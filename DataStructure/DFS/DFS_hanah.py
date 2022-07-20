class Traversal():
    graph = {}

    def __init__(self, graph={}):
        self.graph = graph

    def recursive_dfs(self, v, discovered=[]):
        discovered.append(v)
        print(v)
        for w in self.graph[v]:
            if w not in discovered:
                discovered = self.recursive_dfs(w, discovered)

        return discovered

    def iterative_dfs(self, v):
        stack = [v]
        discovered = []

        while stack:
            v = stack.pop()
            # if v not in discovered:
            discovered.append(v)
            print(v)
            for w in self.graph[v]:
                if w not in discovered:
                    stack.append(w)
        print(discovered)


# 실행
graph = {1: [2, 3, 4],
         2: [5],
         3: [5],
         4: [],
         5: [6, 7],
         6: [],
         7: [3], }

traversal = Traversal(graph)
print('---------recursive_dfs---------')
traversal.recursive_dfs(1, [])
print('---------iterative_dfs---------')
traversal.iterative_dfs(1)
