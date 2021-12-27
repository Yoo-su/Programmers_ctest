from collections import defaultdict

def solution(tickets):
    answer=[]
    dic=defaultdict(list)
    
    for start,end in tickets:
        dic[start].append(end)
        dic[start].sort()
    
    print(dic)
    stack=['ICN']
    while stack:
        item=stack[-1]
        
        if not dic[item]:
            answer.append(stack.pop())
        else:
            stack.append(dic[item].pop(0))
    answer.reverse()
    
    return answer


print(solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]))