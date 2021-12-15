from collections import defaultdict, deque

def solution(n, wires):
    answer=n
    comb=[]
    dic=defaultdict(list)

    for wire in wires:
        dic[wire[0]].append(wire[1])
        dic[wire[1]].append(wire[0])
        
        comb.append((wire[0],wire[1]))
        
    visited=defaultdict(bool)
    deq, count,count2 = deque(), 0,0
    
    for com in comb:
        deq.append(com[0])
        visited[com[0]]=True
        while deq:
            n=deq.popleft()
            count+=1
            for i in dic[n]:
                if i!=com[1] and visited[i]==False:
                    deq.append(i)
                    visited[i]=True
        deq.clear()
        visited.clear()
        
        deq.append(com[1])
        visited[com[1]]=True
        while deq:
            n=deq.popleft()
            count2+=1
            for i in dic[n]:
                if i!=com[0] and visited[i]==False:
                    deq.append(i)
                    visited[i]=True
        answer=min(answer,abs(count-count2))
        deq.clear()
        visited.clear()
        count,count2=0,0
        
    return answer
        
    
print(solution(9,[[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]))