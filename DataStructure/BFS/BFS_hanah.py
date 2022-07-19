class Traversal():
    graph = {}

    def __init__(self, graph={}):
        self.graph = graph

    def iterative_bfs(self, v):
        discovered = [v]
        queue = [v]

        while queue:
            v = queue.pop(0)
            print(v)
            for w in self.graph[v]:
                if w not in discovered:
                    queue.append(w)
                    discovered.append(w)
        print(discovered)

    # 이하 코드보다 위의 분기가 더 깔끔하다.
    def _iterative_bfs(self, v):
        discovered = []
        queue = [v]

        while queue:
            v = queue.pop(0)
            if v not in discovered:
                for w in self.graph[v]:
                    if w not in discovered:
                        queue.append(w)
                discovered.append(v)
                print(v)
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
print('---------iterative_bfs---------')
traversal.iterative_bfs(1)
