class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) > (n - 1):
            return False
        visited = set()

        adj_list = [[] for _ in range(n)]
        for u, v in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)
        
        visited = set()
        def dfs(node, par):
            if node in visited:
                return False
            visited.add(node)
            for adj in adj_list[node]:
                if adj != par:
                    dfs(adj, node)
            
            return True
        
        return dfs(0, -1) and len(visited) == n

        