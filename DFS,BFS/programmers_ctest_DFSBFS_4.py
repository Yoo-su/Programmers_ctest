from collections import defaultdict, deque
import heapq
import copy

def check(arr):
    for item in arr:
        if item:
            return False
    return True
        
def solution(tickets):
    dic=defaultdict(list)
    for a,b in tickets:
        heapq.heappush(dic[a],b)
    
    global res
    res=[]
    def dfs(port,result,dict):
        global res
        if check(dict.values()) and not res:
            result.append(port)
            res.append(result)
            return 

        result.append(port)

        for i in range(len(dict[port])):
            newdict=copy.deepcopy(dict)
            item=newdict[port].pop(i)
            
            dfs(item,copy.deepcopy(result),newdict)

    dfs("ICN",[],dic)
    
    return res[0]

print(solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL", "SFO"]]))