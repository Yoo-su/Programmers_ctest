import sys, heapq
from collections import defaultdict

def solution(n, edge):
    answer = 0
    
    dic=defaultdict(dict)
    for a,b in edge:
        dic[a][b]=1
        dic[b][a]=1

    def dijkstra(graph,start):
        dists={node:float('inf') for node in graph}
        dists[start]=0
        queue=[]
        heapq.heappush(queue,[dists[start],start])
        
        while queue:
            cur_dist, cur_dest=heapq.heappop(queue)
            
            if dists[cur_dest]<cur_dist:
                continue

            for new_dest, new_dist in graph[cur_dest].items():
                dist=cur_dist+new_dist
                if dist<dists[new_dest]:
                    dists[new_dest]=dist
                    heapq.heappush(queue,[dists[new_dest],new_dest])
        return dists
    
    fromOne=dijkstra(dic,1)
    maxVal=max(fromOne.values())
    answer=list(fromOne.values()).count(maxVal)
    
    return answer

print(solution(6,[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))