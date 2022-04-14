from collections import defaultdict
import heapq

def solution(N, road, K):
    answer = 0
    mydict=defaultdict(dict)
    
    for a,b,c in road:
        try:
            mydict[a][b]=min(c,mydict[a][b])
            mydict[b][a]=min(c,mydict[b][a])
        except:
            mydict[a][b]=c
            mydict[b][a]=c
            
    def dijkstra(start, graph):
        dists={x:float('inf') for x in graph}
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
                    heapq.heappush(queue,[dist, new_dest])
        
        return dists
    
    res=dijkstra(1,mydict)

    for dest,time in res.items():
        if time<=K:
            answer+=1

    
    return answer