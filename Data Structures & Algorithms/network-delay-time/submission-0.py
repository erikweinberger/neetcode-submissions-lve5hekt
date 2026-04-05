class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # Step 1: Build the graph
        graph = defaultdict(list)
        for u, v, w in times:
            graph[u].append((w, v))

        min_heap = [(0, k)]
        dist = {}

        while min_heap:
            t, node = heapq.heappop(min_heap)
            if node in dist:
                continue

            dist[node] = t
            for w, enode in graph[node]:
                if enode not in dist:
                    heapq.heappush(min_heap, (t + w, enode))
        
        print(dist)
        return max(dist.values()) if len(dist) == n else -1


