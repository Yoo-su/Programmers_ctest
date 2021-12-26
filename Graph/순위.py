import sys, heapq
from collections import defaultdict

def solution(n, results):
    answer = 0
    
    win, lose=defaultdict(set), defaultdict(set)
    
    for a,b in results:
        win[a].add(b)
        lose[b].add(a)
    
    for i in range(1,n+1):
        for l in lose[i]:
            win[l].update(win[i])
        
        for w in win[i]:
            lose[w].update(lose[i])
        
    for i in range(1,n+1):
        if len(win[i])+len(lose[i])==n-1:
            answer+=1
    return answer        
    
print(solution(5,[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))

